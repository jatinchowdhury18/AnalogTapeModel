#pragma once

#include <JuceHeader.h>

class TipJar : public ComboBox,
               private InAppPurchases::Listener
{
public:
    TipJar();
    ~TipJar() override;

    void productsInfoReturned (const Array<InAppPurchases::Product>& products) override;
    void doTipPurchase (const String& id);
    void setDisconnectedMenu();

private:
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
