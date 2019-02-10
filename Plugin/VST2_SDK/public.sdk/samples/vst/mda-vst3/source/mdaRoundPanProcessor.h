/*
 *  mdaRoundPanProcessor.h
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/14/08.
 *
 *  mda VST Plug-ins
 *
 *  Copyright (c) 2008 Paul Kellett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __mdaRoundPanProcessor__
#define __mdaRoundPanProcessor__

#include "mdaBaseProcessor.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class RoundPanProcessor : public BaseProcessor
{
public:
	RoundPanProcessor ();
	~RoundPanProcessor ();
	
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate ();
	tresult PLUGIN_API setActive (TBool state);

	void doProcessing (ProcessData& data);

//-----------------------------------------------------------------------------
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new RoundPanProcessor; }
	static FUID uid;
//-----------------------------------------------------------------------------
protected:
	void recalculate ();

	float phi, dphi;
};

}}} // namespaces

#endif
