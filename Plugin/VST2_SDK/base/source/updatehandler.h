//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/updatehandler.h
// Created by  : Steinberg, 2008
// Description :
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

#ifndef __updatehandler__
#define __updatehandler__

#include "base/source/fobject.h"
#include "base/source/fthread.h"
#include "pluginterfaces/base/iupdatehandler.h"

namespace Steinberg  {

/// @cond ignore
namespace Update { struct Table; }
/// @endcond

//------------------------------------------------------------------------
/** Handle Send and Cancel pending message for a given object*/
//------------------------------------------------------------------------
class IUpdateManager: public FUnknown
{
public:
//------------------------------------------------------------------------
  virtual tresult PLUGIN_API cancelUpdates (FUnknown* object) = 0;             ///< cancel pending messages send by \param object or by any if object is 0
  virtual tresult PLUGIN_API triggerDeferedUpdates (FUnknown* object = 0) = 0; ///< send pending messages send by \param object or by any if object is 0
  static const FUID iid;
};

DECLARE_CLASS_IID (IUpdateManager, 0x030B780C, 0xD6E6418D, 0x8CE00BC2, 0x09C834D4)

//------------------------------------------------------------------------------
/**
UpdateHandler implements IUpdateManager and IUpdateHandler to handle dependencies
between objects to store and forward messages to dependent objects.

This implementation is thread save, so objects can send message, add or remove 
dependents from different threads. 
Do do so it uses mutex, so be aware of locking. 
*/
//------------------------------------------------------------------------------
class UpdateHandler : public FObject, public IUpdateHandler, public IUpdateManager
{
public:
//------------------------------------------------------------------------------
	UpdateHandler ();
	~UpdateHandler ();

	// IUpdateHandler
	virtual tresult PLUGIN_API addDependent (FUnknown* object, IDependent* dependent);    ///< register \param dependent to get messages from \param object
	virtual tresult PLUGIN_API removeDependent (FUnknown* object, IDependent* dependent); ///< unregister \param dependent to get no messages from \param object
	virtual	tresult PLUGIN_API triggerUpdates (FUnknown* object, int32 message);          ///< send \param message to all dependents of \param object immediately
	virtual	tresult PLUGIN_API deferUpdates (FUnknown* object, int32 message);            ///< send \param message to all dependents of \param object when idle

	// IUpdateManager
	virtual	tresult PLUGIN_API cancelUpdates (FUnknown* object);                          ///< cancel pending messages send by \param object or by any if object is 0
	virtual tresult PLUGIN_API triggerDeferedUpdates (FUnknown* object = 0);              ///< send pending messages send by \param object or by any if object is 0

	/// @cond ignore
	void checkUpdates (FObject* object = 0) {triggerDeferedUpdates (object);}			// obsolete functions kept for compatibility
	void flushUpdates (FObject* object) {cancelUpdates (object);}						// obsolete functions kept for compatibility
	void deferUpdate (FObject* object, int32 message) {deferUpdates (object, message);}	// obsolete functions kept for compatibility
	void signalChange (FObject* object, int32 message, bool suppressUpdateDone = false)	// obsolete functions kept for compatibility
	                   {doTriggerUpdates (object, message, suppressUpdateDone);}
	#if DEVELOPMENT
	bool checkDeferred (FUnknown* object);
	bool hasDependencies (FUnknown* object);
	void printForObject (FObject* object) const;
	#endif

	/// @endcond

	OBJ_METHODS (UpdateHandler, FObject) 
	FUNKNOWN_METHODS2 (IUpdateHandler, IUpdateManager, FObject)
	SINGLETON (UpdateHandler)
//------------------------------------------------------------------------------
private:
	tresult doTriggerUpdates (FUnknown* object, int32 message, bool suppressUpdateDone);

	FLock lock;
	Update::Table* table;
};

} // namespace Steinberg

#endif	// __updatehandler__
