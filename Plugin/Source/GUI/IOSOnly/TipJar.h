#pragma once

#include <JuceHeader.h>

class TipJar : public ComboBox,
               private InAppPurchases::Listener
{
public:
    TipJar()
    {
        productInfos = {
            { "Small Tip ($2)", "chowtape_small_tip_123" },
            { "Medium Tip ($5)", "chowtape_medium_tip_456" },
            { "Large Tip ($10)", "chowtape_small_tip_123" },
            { "Huge Tip ($25)", "chowtape_small_tip_123" },
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
            std::cout << info.second << std::endl;
        }
        
        InAppPurchases::getInstance()->addListener (this);
        InAppPurchases::getInstance()->getProductsInformation (purchaseIDs);
    }
    
    ~TipJar() override
    {
        InAppPurchases::getInstance()->removeListener (this);
    }
    
    void doTipPurchase (const String& id)
    {
        InAppPurchases::getInstance()->purchaseProduct (id);
        setText ("Tip Jar");
    };
    
    void productPurchaseFinished (const PurchaseInfo& pInfo, bool success, const String& status) override
    {
        std::cout << success << std::endl;
        std::cout << status << std::endl;
        std::cout << pInfo.purchase.productId << std::endl;
    }
    
    void productsInfoReturned (const juce::Array<juce::InAppPurchases::Product>& products) override
    {
        std::cout << products.size() << std::endl;
    }

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
