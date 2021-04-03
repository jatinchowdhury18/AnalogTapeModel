#include <JuceHeader.h>

class UnitTests : public ConsoleApplication::Command
{
public:
    UnitTests();

    void runUnitTests (const ArgumentList& args);

private:
    int64 getRandomSeed (const ArgumentList& args);
    void getTestsForArgs (Array<UnitTest*>& tests, const ArgumentList& args);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UnitTests)
};
