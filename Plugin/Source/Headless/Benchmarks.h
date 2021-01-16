#ifndef BENCHMARKS_H_INCLUDED
#define BENCHMARKS_H_INCLUDED

#include <JuceHeader.h>

class Benchmarks : public ConsoleApplication::Command
{
public:
    Benchmarks();

private:
    /** Run benchmarks for ChowTape */
    void runBenchmarks (const ArgumentList& args);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Benchmarks)
};

#endif // BENCHMARKS_H_INCLUDED
