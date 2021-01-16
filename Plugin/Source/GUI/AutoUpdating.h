#ifndef AUTOUPDATING_H_INCLUDED
#define AUTOUPDATING_H_INCLUDED

#include "MyLNF.h"
#include <JuceHeader.h>
#include <future>

struct UpdateButtonLNF : public MyLNF
{
    UpdateButtonLNF() {}

    Font getTextButtonFont (TextButton&, int /*buttonHeight*/) override
    {
        return Font (30.0f).boldened();
    }

    void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour, bool, bool) override
    {
        LookAndFeel_V4::drawButtonBackground (g, button, backgroundColour, false, false);
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UpdateButtonLNF)
};

class AutoUpdater : public Component
{
public:
    AutoUpdater();
    ~AutoUpdater();

    void paint (Graphics& g) override;
    void resized() override;

    void showUpdaterScreen (Component* parent);

    bool runAutoUpdateCheck();
    void noButtonPressed();
    void yesButtonPressed();

private:
    File getUpdateCheckFile();
    String getLatestVersion();
    String getUpdateFileVersion (const File& updateFile);
    bool getUpdateFileYesNo (const File& updateFile);
    void editUpdateCheckFile (String version, bool wantsUpdate);

    String newVersion = String (JucePlugin_VersionString);

    TextButton yesButton { "Yes" };
    TextButton noButton { "No" };
    UpdateButtonLNF ubLNF;

    std::future<bool> needsUpdate;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AutoUpdater)
};

#endif // AUTOUPDATING_H_INCLUDED
