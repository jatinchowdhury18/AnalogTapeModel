#ifndef PROCESSORBASE_H_INCLUDED
#define PROCESSORBASE_H_INCLUDED

#include "JuceHeader.h"

class ProcessorBase : public AudioProcessor
{
public:
    ProcessorBase (String name) : name (name) {}

    const String getName() const override { return name; }

    double getTailLengthSeconds() const override { return 0.0; }

    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }

    AudioProcessorEditor* createEditor() override { return nullptr; };
    bool hasEditor() const override { return false; }

    int getNumPrograms() override { return 0; }
    void setCurrentProgram (int /*index*/) override {}
    int getCurrentProgram() override { return 0; }

    const String getProgramName (int /*index*/) override { return {}; }
    void changeProgramName (int /*index*/, const String& /*newName*/) override {}

    void getStateInformation (MemoryBlock& /*destData*/) override {}
    void setStateInformation (const void* /*data*/, int /*sizeInBytes*/) override {}

private:
    String name;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProcessorBase)
};

#endif //PROCESSORBASE_H_INCLUDED
