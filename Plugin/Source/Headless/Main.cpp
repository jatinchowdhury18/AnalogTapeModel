#include "Benchmarks.h"
#include "ScreenshotHelper.h"
#include "FirBench.h"

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

    ScreenshotHelper screenshooter;
    app.addCommand (screenshooter);

    Benchmarks benchmarks;
    app.addCommand (benchmarks);

    FirBench firBench;
    app.addCommand (firBench);

    return app.findAndRunCommand (argc, argv);
}
