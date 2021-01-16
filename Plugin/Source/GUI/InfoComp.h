#ifndef INFOCOMP_H_INCLUDED
#define INFOCOMP_H_INCLUDED

#include <JuceHeader.h>

class InfoComp : public Component
{
public:
    InfoComp (const AudioProcessor::WrapperType wrapperType);

    enum ColourIDs
    {
        text1ColourID,
        text2ColourID,
    };

    void paint (Graphics& g) override;
    void resized() override;

private:
    const AudioProcessor::WrapperType wrapperType;
    HyperlinkButton linkButton { JucePlugin_Manufacturer, URL ("https://ccrma.stanford.edu/~jatin/chowdsp") };

    int linkX = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InfoComp)
};

class InfoItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (InfoItem)

    InfoItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node)
    {
        setColourTranslation ({
            { "text1", InfoComp::text1ColourID },
            { "text2", InfoComp::text2ColourID },
        });

        infoComp = std::make_unique<InfoComp> (builder.getMagicState().getProcessor()->wrapperType);
        addAndMakeVisible (infoComp.get());
    }

    void update() override
    {
    }

    Component* getWrappedComponent() override
    {
        return infoComp.get();
    }

private:
    std::unique_ptr<InfoComp> infoComp;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InfoItem)
};

#endif // INFOCOMP_H_INCLUDED
