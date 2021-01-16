#include "AutoUpdating.h"

namespace
{
const String updateFilePath = "ChowdhuryDSP/ChowTape/UpdateManage.txt";
const String currentVersion = "v" + String (JucePlugin_VersionString);
const String versionURL = "https://api.github.com/repos/jatinchowdhury18/AnalogTapeModel/releases/latest";
const String updateURL = "https://github.com/jatinchowdhury18/AnalogTapeModel/releases/latest";
const Colour backgroundColour = Colour (0xFF31323A).withAlpha (0.9f);
const Colour textColour = Colour (0xFFEAA92C);
} // namespace

AutoUpdater::AutoUpdater()
{
    auto setupButton = [=] (TextButton& button) {
        addAndMakeVisible (button);
        button.setColour (TextButton::buttonColourId, backgroundColour);
        button.setColour (TextButton::textColourOffId, textColour);
        button.setColour (ComboBox::outlineColourId, Colours::transparentBlack);
        button.setOpaque (false);
        button.setMouseCursor (MouseCursor::PointingHandCursor);
        button.setLookAndFeel (&ubLNF);
    };

    setupButton (yesButton);
    setupButton (noButton);

    yesButton.onClick = std::bind (&AutoUpdater::yesButtonPressed, this);
    noButton.onClick = std::bind (&AutoUpdater::noButtonPressed, this);

    needsUpdate = std::async (std::launch::async, &AutoUpdater::runAutoUpdateCheck, this);
}

AutoUpdater::~AutoUpdater()
{
    yesButton.setLookAndFeel (nullptr);
    noButton.setLookAndFeel (nullptr);
}

void AutoUpdater::yesButtonPressed()
{
    // open update link
    URL updateLink (updateURL);
    updateLink.launchInDefaultBrowser();

    // reset update check file
    setVisible (false);
    editUpdateCheckFile (newVersion, true);
}

void AutoUpdater::noButtonPressed()
{
    // reset update check file
    setVisible (false);
    editUpdateCheckFile (newVersion, false);
}

void AutoUpdater::paint (Graphics& g)
{
    g.fillAll (backgroundColour);

    g.setColour (Colours::white);
    g.setFont (Font (36.0f));

    String updatePrompt = String ("Version " + newVersion.removeCharacters ("v") + " of CHOW Tape is available. Would you like to download?");

    const auto promptWidth = getWidth() * 2 / 3;
    const auto promptX = getWidth() / 6;
    const auto promptHeight = 50;
    const auto promptY = getHeight() / 2 - promptHeight;

    g.drawFittedText (updatePrompt, promptX, promptY, promptWidth, promptHeight, Justification::centred, 2);
}

void AutoUpdater::resized()
{
    const auto y = getHeight() / 2 + 10;
    const auto width = 90;
    const auto pad = 5;
    const auto height = 40;

    yesButton.setBounds (getWidth() / 2 - width - pad, y, width, height);
    noButton.setBounds (getWidth() / 2 + pad, y, width, height);
}

void AutoUpdater::showUpdaterScreen (Component* parent)
{
    if (! needsUpdate.valid())
        return;

    if (needsUpdate.get())
    {
        parent->addAndMakeVisible (this);
        setBounds (0, 0, parent->getWidth(), parent->getHeight());
    }
}

bool AutoUpdater::runAutoUpdateCheck()
{
    auto updateFile = getUpdateCheckFile();
    String latestVersion = getLatestVersion();

    if (latestVersion.isEmpty()) // unable to get latest version
        return false;

    if (latestVersion == currentVersion) // you're up to date!
        return false;

    String updateVersion = getUpdateFileVersion (updateFile);
    bool lastYesNo = getUpdateFileYesNo (updateFile);

    // you've already said you don't want to update to this version
    if ((updateVersion == latestVersion) && (lastYesNo == false))
        return false;

    newVersion = latestVersion;
    return true;
}

File AutoUpdater::getUpdateCheckFile()
{
    File updateCheckFile = File::getSpecialLocation (File::userApplicationDataDirectory);
    updateCheckFile = updateCheckFile.getChildFile (updateFilePath);

    if (! updateCheckFile.existsAsFile())
    {
        updateCheckFile.create();
        updateCheckFile.appendText (currentVersion + "\n");
        updateCheckFile.appendText ("YES\n");
    }

    return updateCheckFile;
}

String AutoUpdater::getLatestVersion()
{
    URL latestVersionURL (versionURL);
    std::unique_ptr<InputStream> inStream (latestVersionURL.createInputStream (false, nullptr, nullptr, {}, 5000));

    if (inStream == nullptr)
        return {};

    auto content = inStream->readEntireStreamAsString();
    auto latestReleaseDetails = JSON::parse (content);

    auto* json = latestReleaseDetails.getDynamicObject();

    if (json == nullptr)
        return {};

    return json->getProperty ("tag_name").toString();
}

String AutoUpdater::getUpdateFileVersion (const File& updateFile)
{
    StringArray lines;
    updateFile.readLines (lines);

    return lines[0];
}

bool AutoUpdater::getUpdateFileYesNo (const File& updateFile)
{
    StringArray lines;
    updateFile.readLines (lines);

    return lines[1] == "YES";
}

void AutoUpdater::editUpdateCheckFile (String version, bool wantsUpdate)
{
    auto updateFile = getUpdateCheckFile();
    updateFile.deleteFile();
    updateFile.create();
    updateFile.appendText (version + "\n");

    if (wantsUpdate)
        updateFile.appendText ("YES\n");
    else
        updateFile.appendText ("NO\n");
}
