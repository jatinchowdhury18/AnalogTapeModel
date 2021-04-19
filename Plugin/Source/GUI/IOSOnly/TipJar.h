#pragma once

#include <JuceHeader.h>

class TipJar : public ComboBox
{
public:
    TipJar()
    {
        productInfos = {
            { "Small Tip ($2)", "chowtape_small_tip_123" },
            { "Medium Tip ($5)", "chowtape_medium_tip_456" },
            { "Large Tip ($10)", "chowtape_large_tip_789" },
            { "Huge Tip ($25)", "chowtape_huge_tip_808" },
        };

        if (! InAppPurchases::getInstance()->isInAppPurchasesSupported ())
        {
            // this should never happen, since we only enable IAPs on iOS!
            jassertfalse;
            return;
        }
        
        setTextWhenNothingSelected ("Tip Jar");
        setColour (backgroundColourId, Colours::transparentBlack);
        setJustificationType (Justification::centred);
        
        auto rootMenu = getRootMenu();
        StringArray purchaseIDs;
        for (auto& info : productInfos)
        {
            rootMenu->addItem (info.first, [=] { doTipPurchase (info.second); });
            purchaseIDs.add (info.second);
        }
        
        InAppPurchases::getInstance()->getProductsInformation (purchaseIDs);
    }
    
    void doTipPurchase (const String& id)
    {
        InAppPurchases::getInstance()->purchaseProduct (id);
        setText ("Tip Jar");
    };

private:
    std::vector<std::pair<String, String>> productInfos;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TipJar)
};

class TipJarItem : public foleys::GuiItem
{
public:
    FOLEYS_DECLARE_GUI_FACTORY (TipJarItem)

    TipJarItem (foleys::MagicGUIBuilder& builder, const ValueTree& node) : foleys::GuiItem (builder, node)
    {
        addAndMakeVisible (tipJar);
    }

    void update() override {}

    Component* getWrappedComponent() override { return &tipJar; }

private:
    TipJar tipJar;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TipJarItem)
};
