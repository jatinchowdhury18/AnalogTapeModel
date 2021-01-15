#include "ScreenshotHelper.h"

#ifdef TAKE_SCREENSHOTS

namespace ScreenshotHelper
{
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

void screenshotTab (foleys::Container* container, int tabIdx)
{
    container->tabbedButtons->setCurrentTabIndex (tabIdx);
    auto name = container->tabbedButtons->getTabButton (tabIdx)->getName();

    int index = 0;
    for (auto& child : container->children)
        child->setVisible (tabIdx == index++);

    screenshotForBounds (container, container->getLocalBounds(), name + ".png");
}

void takeScreenshots (std::unique_ptr<ChowtapeModelAudioProcessor> plugin)
{
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
    screenshotForBounds (editor.get(), editor->getLocalBounds(), "full_gui.png");

    // get tabbed components
    Array<foleys::Container*> tabbedComps;
    findTabbedComponents (editor.get(), tabbedComps);

    for (auto c : tabbedComps)
        for (int i = 0; i < c->tabbedButtons->getNumTabs(); ++i)
            screenshotTab (c, i);

    plugin->editorBeingDeleted (editor.get());
}

File getScreenshotFolder()
{
    return File ("D:/Documents/CCRMA/Music 420/AnalogTapeModel/Plugin/Screenshots");
}

void screenshotForBounds (Component* editor, Rectangle<int> bounds, const String& filename)
{
    auto screenshot = editor->createComponentSnapshot (bounds);

    File pngFile = getScreenshotFolder().getChildFile (filename);
    pngFile.deleteFile();
    pngFile.create();
    auto pngStream = pngFile.createOutputStream();

    if (pngStream->openedOk())
    {
        PNGImageFormat pngImage;
        pngImage.writeImageToStream (screenshot, *pngStream.get());
    }
}

} // namespace ScreenshotHelper

#endif // TAKE_SCREENSHOTS
