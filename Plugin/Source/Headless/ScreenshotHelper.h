#ifndef SCREENSHOTHELPER_H_INCLUDED
#define SCREENSHOTHELPER_H_INCLUDED

#if JUCE_LINUX
#include "JuceHeader.h"
#else
// weird hack, but I need acces to some private
// member variables from foleys::Container
// @TODO: figure out a better way!
#define _XKEYCHECK_H
#define private public
#include <JuceHeader.h>
#undef private
#endif

class ScreenshotHelper : public ConsoleApplication::Command
{
public:
    ScreenshotHelper();

private:
    /** Take a series of screenshots used for the plugin documentation */
    void takeScreenshots (const ArgumentList& args);

    /** Take a single screenshot for a given rectangle */
    void screenshotForBounds (Component* editor, Rectangle<int> bounds, const File& dir, const String& filename);

    /** Takes a screenshot from an individual tab of a TabbedComponent */
    void screenshotTab (foleys::Container* container, int tabIdx, const File& dir);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScreenshotHelper)
};

#endif // SCREENSHOTHELPER_H_INCLUDED
