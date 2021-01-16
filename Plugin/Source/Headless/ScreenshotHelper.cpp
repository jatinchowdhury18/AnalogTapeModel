#include "ScreenshotHelper.h"
#include "../PluginProcessor.h"

ScreenshotHelper::ScreenshotHelper()
{
    this->commandOption = "--screenshots";
    this->argumentDescription = "--screenshots --out=[DIR]";
    this->shortDescription = "Generates screenshots for ChowTapeModel documentation";
    this->longDescription = "";
    this->command = std::bind (&ScreenshotHelper::takeScreenshots, this, std::placeholders::_1);
}

/**
  * Process audio through the plugin so the screenshots have
  * some signal show up in the meters and scopes.
  */
void processAudio (ChowtapeModelAudioProcessor* plugin)
{
    constexpr double fs = 48000.0;
    constexpr int blockSize = 1024;
    constexpr float freq = 200.0f;

    AudioBuffer<float> buffer (2, blockSize);
    for (int ch = 0; ch < 2; ++ch)
    {
        auto* data = buffer.getWritePointer (ch);
        for (int n = 0; n < blockSize; ++n)
            data[n] = -0.7f * std::cos (MathConstants<float>::twoPi * freq * (float) n / (float) fs);
    }

    plugin->prepareToPlay (fs, blockSize);

    MidiBuffer midi;
    plugin->processBlock (buffer, midi);
}

void findTabbedComponents (Component* root, Array<foleys::Container*>& tabbedComps)
{
    if (root == nullptr)
        return;

    for (auto child : root->getChildren())
    {
        if (auto tabbedComponent = dynamic_cast<foleys::Container*> (child))
        {
            if (tabbedComponent->layout == foleys::Container::Layout::Tabbed)
                tabbedComps.add (tabbedComponent);
        }

        findTabbedComponents (child, tabbedComps);
    }
}

void ScreenshotHelper::screenshotTab (foleys::Container* container, int tabIdx, const File& outDir)
{
    container->tabbedButtons->setCurrentTabIndex (tabIdx);
    auto name = container->tabbedButtons->getTabButton (tabIdx)->getName();

    int index = 0;
    for (auto& child : container->children)
        child->setVisible (tabIdx == index++);

    screenshotForBounds (container, container->getLocalBounds(), outDir, name + ".png");
}

void ScreenshotHelper::takeScreenshots (const ArgumentList& args)
{
    File outputDir = File::getCurrentWorkingDirectory();
    if (args.containsOption ("--out"))
        outputDir = args.getExistingFolderForOption ("--out");

    std::cout << "Generating screenshots... Saving to " << outputDir.getFullPathName() << std::endl;

    auto plugin = std::make_unique<ChowtapeModelAudioProcessor>();
    processAudio (plugin.get());
    std::unique_ptr<AudioProcessorEditor> editor (plugin->createEditorIfNeeded());

    // make sure all plugin sections are enabled
    StringArray onOffIDs { "ifilt_onoff", "hyst_onoff", "tone_onoff", "loss_onoff", "chew_onoff", "deg_onoff", "flutter_onoff" };
    for (auto param : plugin->getParameters())
    {
        if (auto* paramCast = dynamic_cast<RangedAudioParameter*> (param))
        {
            if (onOffIDs.contains (paramCast->paramID))
                paramCast->setValueNotifyingHost (1.0f);
        }
    }

    // full screenshot
    screenshotForBounds (editor.get(), editor->getLocalBounds(), outputDir, "full_gui.png");

    // get tabbed components
    Array<foleys::Container*> tabbedComps;
    findTabbedComponents (editor.get(), tabbedComps);

    for (auto c : tabbedComps)
        for (int i = 0; i < c->tabbedButtons->getNumTabs(); ++i)
            screenshotTab (c, i, outputDir);

    plugin->editorBeingDeleted (editor.get());
}

void ScreenshotHelper::screenshotForBounds (Component* editor, Rectangle<int> bounds, const File& dir, const String& filename)
{
    auto screenshot = editor->createComponentSnapshot (bounds);

    File pngFile = dir.getChildFile (filename);
    pngFile.deleteFile();
    pngFile.create();
    auto pngStream = pngFile.createOutputStream();

    if (pngStream->openedOk())
    {
        PNGImageFormat pngImage;
        pngImage.writeImageToStream (screenshot, *pngStream.get());
    }
}
