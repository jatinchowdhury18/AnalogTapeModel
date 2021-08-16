#include "UnitTests.h"

//==============================================================================
class ConsoleLogger : public Logger
{
    void logMessage (const String& message) override
    {
        std::cout << message << std::endl;

#if JUCE_WINDOWS
        Logger::outputDebugString (message);
#endif
    }
};

//==============================================================================
class ConsoleUnitTestRunner : public UnitTestRunner
{
    void logMessage (const String& message) override
    {
        Logger::writeToLog (message);
    }
};

//==============================================================================
UnitTests::UnitTests()
{
    this->commandOption = "--unit-tests";
    this->argumentDescription = "--unit-tests [--seed=RANDOM_SEED --all] TEST1 TEST2 ...";
    this->shortDescription = "Runs unit tests for ChowTapeModel";
    this->longDescription = "";
    this->command = std::bind (&UnitTests::runUnitTests, this, std::placeholders::_1);
}

void UnitTests::runUnitTests (const ArgumentList& args)
{
    ConsoleLogger logger;
    Logger::setCurrentLogger (&logger);

    ConsoleUnitTestRunner runner;
    auto seed = getRandomSeed (args);

    auto tests = getTestsForArgs (args);
    runner.runTests (tests, seed);

    Logger::setCurrentLogger (nullptr);

    for (int i = 0; i < runner.getNumResults(); ++i)
        if (runner.getResult (i)->failures > 0)
            ConsoleApplication::fail ("Unit Tests failed!");
}

int64 UnitTests::getRandomSeed (const ArgumentList& args)
{
    if (args.containsOption ("--seed"))
    {
        auto seedValueString = args.getValueForOption ("--seed");
        if (seedValueString.startsWith ("0x"))
            return seedValueString.getHexValue64();

        return seedValueString.getLargeIntValue();
    }

    return int64 (0);
}

Array<UnitTest*> UnitTests::getTestsForArgs (const ArgumentList& args)
{
    if (args.containsOption ("--all"))
        return UnitTest::getAllTests();

    Array<UnitTest*> unitTests;
    for (auto* test : UnitTest::getAllTests())
    {
        if (args.containsOption (test->getName()))
            unitTests.add (test);
    }

    return unitTests;
}
