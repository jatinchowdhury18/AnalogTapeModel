//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/hosting/parameterchanges.h
// Created by  : Steinberg, 03/05/2008.
// Description : VST 3 parameter changes implementation
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// This Software Development Kit may not be distributed in parts or its entirety  
// without prior written agreement by Steinberg Media Technologies GmbH. 
// This SDK must not be used to re-engineer or manipulate any technology used  
// in any Steinberg or Third-party application or software module, 
// unless permitted by law.
// Neither the name of the Steinberg Media Technologies nor the names of its
// contributors may be used to endorse or promote products derived from this 
// software without specific prior written permission.
// 
// THIS SDK IS PROVIDED BY STEINBERG MEDIA TECHNOLOGIES GMBH "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL STEINBERG MEDIA TECHNOLOGIES GMBH BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/vst/ivstparameterchanges.h"
#include <vector>

namespace Steinberg {
namespace Vst {

//--------------------------------------------------------------------------------------------------------------
/** Implementation of IParamValueQueue - not threadsave */
//--------------------------------------------------------------------------------------------------------------
class ParameterValueQueue : public IParamValueQueue
{
public:
//--------------------------------------------------------------------------------------------------------------
	ParameterValueQueue (ParamID paramID);
	virtual ~ParameterValueQueue ();

	ParamID PLUGIN_API getParameterId () { return paramID; }
	int32 PLUGIN_API getPointCount ();
	tresult PLUGIN_API getPoint (int32 index, int32& sampleOffset, ParamValue& value);
	tresult PLUGIN_API addPoint (int32 sampleOffset, ParamValue value, int32& index);

	void setParamID (ParamID pID) {paramID = pID;}
	void clear ();
//--------------------------------------------------------------------------------------------------------------
	DECLARE_FUNKNOWN_METHODS
protected:
	ParamID paramID;

	struct ParameterQueueValue
	{
		ParameterQueueValue (ParamValue value, int32 sampleOffset) : value (value), sampleOffset (sampleOffset) {}
		ParamValue value;
		int32 sampleOffset;
	};
	std::vector<ParameterQueueValue> values;
};

//--------------------------------------------------------------------------------------------------------------
/** Implementation of IParameterChanges - not threadsave */
//--------------------------------------------------------------------------------------------------------------
class ParameterChanges : public IParameterChanges
{
public:
//--------------------------------------------------------------------------------------------------------------
	ParameterChanges (int32 maxParameters = 0);
	virtual ~ParameterChanges ();

	void clearQueue ();
	void setMaxParameters (int32 maxParameters);

	int32 PLUGIN_API getParameterCount ();
	IParamValueQueue* PLUGIN_API getParameterData (int32 index);
	IParamValueQueue* PLUGIN_API addParameterData (const ParamID& pid, int32& index);
	
//--------------------------------------------------------------------------------------------------------------
	DECLARE_FUNKNOWN_METHODS
protected:
	std::vector<ParameterValueQueue*> queues;
	int32 usedQueueCount;
};


//--------------------------------------------------------------------------------------------------------------
/** Ring buffer for transferring parameter changes from a writer to a read thread */
//--------------------------------------------------------------------------------------------------------------
class ParameterChangeTransfer
{
public:
//--------------------------------------------------------------------------------------------------------------
	ParameterChangeTransfer (int32 maxParameters = 0);
	virtual ~ParameterChangeTransfer ();

	void setMaxParameters (int32 maxParameters);

	void addChange (ParamID pid, ParamValue value, int32 sampleOffset);
	bool getNextChange (ParamID& pid, ParamValue& value, int32& sampleOffset);

	void transferChangesTo (ParameterChanges& dest);
	void transferChangesFrom (ParameterChanges& source);

//--------------------------------------------------------------------------------------------------------------
protected:
	struct ParameterChange
	{
		ParamID id;
		ParamValue value;
		int32 sampleOffset;
	};
	int32 size;
	ParameterChange* changes;

	volatile int32 readIndex;
	volatile int32 writeIndex;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
