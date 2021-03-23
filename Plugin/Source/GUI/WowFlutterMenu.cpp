#include "WowFlutterMenu.h"

class WowFlutterMenuLNF : public ComboBoxLNF
{
public:
    WowFlutterMenuLNF() = default;

    void drawComboBox (Graphics& g, int width, int height, bool, int, int, int, int, ComboBox& box) override
    {
        auto cornerSize = 5.0f;
        Rectangle<int> boxBounds (0, 0, width, height);

        g.setColour (box.findColour (ComboBox::backgroundColourId));
        g.fillRoundedRectangle (boxBounds.toFloat(), cornerSize);

        g.setColour (box.findColour (ComboBox::outlineColourId));
        g.drawRoundedRectangle (boxBounds.toFloat().reduced (1.0f), cornerSize, 1.0f);

        if (box.getName().isNotEmpty())
        {
            g.setColour (Colours::white);
            g.setFont (getComboBoxFont (box).boldened());
            g.drawFittedText (box.getName(), boxBounds, Justification::centred, 1);
        }
    }

    void positionComboBoxText (ComboBox& box, Label& label) override
    {
        auto b = box.getBounds();
        label.setBounds (b);
        label.setFont (getComboBoxFont (box).boldened());
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WowFlutterMenuLNF)
};

//============================================================================
WowFlutterMenu::WowFlutterMenu (const ChowtapeModelAudioProcessor& proc, const String& type) :
    proc (proc)
{
    setupUI();

    const bool isFlutter = type == "Flutter";
    setupRateParam (isFlutter);

    auto snycToTapeSpeed = [=, &proc] {
        auto& vts = proc.getVTS();
        auto speedParam = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("speed"));
        auto speedIps = speedParam->get();

        auto newFreq = isFlutter ? speedIps / (6.0f * MathConstants<float>::pi) : 0.5f;
        auto newRate = isFlutter ? 0.144765f * std::log (10.0f * newFreq) : 0.5f;
        setRateValue (newRate);
    };

    auto syncToRhythm = [=] (float fractionOfWholeNote) {
        ignoreUnused (fractionOfWholeNote);
        setRateValue (0.5f);
    };

    auto menu = getRootMenu();
    menu->addItem ("Sync to tape speed", snycToTapeSpeed);
    menu->addItem ("Sync to quarter note", std::bind (syncToRhythm, 0.25f));
}

WowFlutterMenu::~WowFlutterMenu()
{
    setLookAndFeel (nullptr);
}

void WowFlutterMenu::setupUI()
{
    setColour (ComboBox::backgroundColourId, Colours::transparentBlack);
    setColour (ComboBox::outlineColourId, Colour (0xff595c6b));

    lnf = std::make_unique<WowFlutterMenuLNF>();
    setLookAndFeel (lnf.get());

    onChange = [=] { setSelectedItemIndex (-1); };
}

void WowFlutterMenu::setupRateParam (bool isFlutter)
{
    auto& vts = proc.getVTS();
    if (isFlutter)
        rateParam = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("rate"));
    else // "Wow"
        rateParam = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("wow_rate"));
    
    jassert (rateParam); // this should never be nullptr!
}

void WowFlutterMenu::setRateValue (float value)
{
    rateParam->beginChangeGesture();
    rateParam->setValueNotifyingHost (value);
    rateParam->endChangeGesture();
}
