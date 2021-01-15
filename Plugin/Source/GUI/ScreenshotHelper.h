#ifndef SCREENSHOTHELPER_H_INCLUDED
#define SCREENSHOTHELPER_H_INCLUDED

// #define TAKE_SCREENSHOTS

#ifdef TAKE_SCREENSHOTS

// weird hack, but I need acces to some private
// member variables from foleys::Container
#define _XKEYCHECK_H
#define private public
#include "../PluginProcessor.h"
#undef private

namespace ScreenshotHelper
{
/** Take a series of screenshots used for the plugin documentation */
void takeScreenshots (std::unique_ptr<ChowtapeModelAudioProcessor> plugin);

/** Take a single screenshot for a given rectangle */
void screenshotForBounds (Component* editor, Rectangle<int> bounds, const String& filename);

} // namespace ScreenshotHelper

#endif // TAKE_SCREENSHOTS

#endif // SCREENSHOTHELPER_H_INCLUDED
