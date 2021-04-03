#include "Benchmarks.h"
#include "FirBench.h"
#include "ScreenshotHelper.h"
#include "UnitTests/UnitTests.h"

String getVersion()
{
    return String (ProjectInfo::projectName) + " - " + ProjectInfo::versionString;
}

String getHelp()
{
    return "ChowTapeModel Headless Interface:";
}

int main (int argc, char* argv[])
{
    std::cout << "Running ChowTapeModel in headless mode..." << std::endl;

#if JUCE_MAC
    Process::setDockIconVisible (false); // hide dock icon
#endif
    ScopedJuceInitialiser_GUI scopedJuce; // creates MessageManager

    ConsoleApplication app;
    app.addVersionCommand ("--version", getVersion());
    app.addHelpCommand ("--help|-h", getHelp(), true);

#if ! JUCE_LINUX // ScreenshotHelper doesn't work on Linux right now
    ScreenshotHelper screenshooter;
    app.addCommand (screenshooter);
#endif

    Benchmarks benchmarks;
    app.addCommand (benchmarks);

    FirBench firBench;
    app.addCommand (firBench);

    UnitTests unitTests;
    app.addCommand (unitTests);

    return app.findAndRunCommand (argc, argv);
}
