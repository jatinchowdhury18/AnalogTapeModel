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
namespace
{
float flutterFreqToParam (float freq)
{
    return 0.144765f * std::log (10.0f * freq);
}

float wowFreqToParam (float freq)
{
    return 0.664859f * std::log (freq + 1.0f);
}
} // namespace

WowFlutterMenu::WowFlutterMenu (const ChowtapeModelAudioProcessor& proc, const String& type) : proc (proc)
{
    setDescription (type + " Sync Menu");
    setupUI();

    const bool isFlutter = type == "Flutter";
    setupRateParam (isFlutter);

    auto snycToTapeSpeed = [=, &proc] {
        const auto& vts = proc.getVTS();
        if (auto speedParam = dynamic_cast<AudioParameterFloat*> (vts.getParameter ("speed")))
        {
            auto speedIps = speedParam->get();

            auto motorFreq = speedIps / (6.0f * MathConstants<float>::pi);
            auto newRate = isFlutter ? flutterFreqToParam (motorFreq)
                                     : wowFreqToParam (std::sqrt (motorFreq));
            setRateValue (newRate);
        }
        else
        {
            // speedParam was nullptr!
            jassertfalse;
        }
    };

    auto syncToRhythm = [=, &proc] (float multipleOfQuarterNote) {
        const auto& posInfo = proc.getPositionInfo();
        auto quarterNoteTime = 60.0f / (float) posInfo.bpm;

        auto newFreq = 1.0f / (quarterNoteTime * multipleOfQuarterNote);
        auto newRate = isFlutter ? flutterFreqToParam (newFreq) : wowFreqToParam (newFreq);
        setRateValue (newRate);
    };

    auto menu = getRootMenu();
    menu->addItem ("Sync to tape speed", snycToTapeSpeed);

    if (isFlutter)
    {
        menu->addItem ("Sync to eighth note", std::bind (syncToRhythm, 0.125f));
        menu->addItem ("Sync to quarter note", std::bind (syncToRhythm, 0.25f));
        menu->addItem ("Sync to half note", std::bind (syncToRhythm, 0.5f));
        menu->addItem ("Sync to whole note", std::bind (syncToRhythm, 1.0f));
    }
    else
    {
        menu->addItem ("Sync to one bar", std::bind (syncToRhythm, 1.0f));
        menu->addItem ("Sync to two bars", std::bind (syncToRhythm, 2.0f));
        menu->addItem ("Sync to four bars", std::bind (syncToRhythm, 4.0f));
        menu->addItem ("Sync to eight bars", std::bind (syncToRhythm, 8.0f));
    }
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
    rateParam->setValueNotifyingHost (jlimit (0.0f, 1.0f, value));
    rateParam->endChangeGesture();
}
