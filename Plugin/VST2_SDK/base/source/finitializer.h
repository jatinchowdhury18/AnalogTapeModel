//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/finitializer.h
// Created by  : Steinberg, 04/2008
// Description : Global Initialization / Termination Mechanism.
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

//----------------------------------------------------------------------------------
/** @file base/source/finitializer.h
	Global Initialization / Termination Mechanism. */
//----------------------------------------------------------------------------------
#ifndef __finitializer__
#define __finitializer__

#include "pluginterfaces/base/ftypes.h"

namespace Steinberg {

//------------------------------------------------------------------------------
typedef bool (*InitTermFunc) (); ///< Initialization / Termination procedure format.  There must not be parameters. Return true to indicate execution success. An initialization procedure returning false causes immediate initialization abort.

/** With init levels, you may initialize things in different places / at different program startup stages. 
	Assign init levels to initialization procedures to form groups of the same level. 
	When calling OneTimeProcedure::initialize(untilLevel), only procedures with a level up to the indicated one will be executed & discarded.
*/
enum InitLevel
{
	kInitLevelFirst = 0,
	kInitLevelBelowStd = 25,
	kInitLevelStd = 50,
	kInitLevelAboveStd = 75,
	kInitLevelLast = 100
};

/** Manager for initialization & termination code.
   With this, you may register code to be executed at program startup and/or termination.\n
   This is useful when there is class specific code you need to be executed at program startup/termination, but you want to keep it in the classes source file to keep together the class code.\n
   The steps are:
   - For any class that requires this, register the initialization and/or termination code using the INITIALIZE(), INITIALIZE_LEVEL() and TERMINATE() makros.
   - Call OneTimeProcedure::initialize() from where all initialization code should be executed (check for success; on fail call OneTimeProcedure::cancel() & quit).
   - Call OneTimeProcedure::terminate() from where all termination code should be executed.
*/
class OneTimeProcedure
{
public:
//------------------------------------------------------------------------------
	OneTimeProcedure (bool isInit, InitTermFunc f = 0, FIDString name = 0, uint32 level = kInitLevelStd); ///< Register an initialization (isInit = true) or termination (isInit=false) procedure (f) for execution. For convenience, use the INITIALIZE & TERMINATE macros instead of this.

	static bool initialize (uint32 untilLevel = kInitLevelLast); ///< Execute & discard all registered initialization procedures. If there are different code spots where to execute certain kinds of initialization, utilize initialization levels (see enum InitLevel).
	static bool terminate (); ///< Execute & discard all registered termination procedures.
	static void cancel (); ///< Discard any initialization/termination procedures registered.

//------------------------------------------------------------------------------
private:
	static bool initPerformed;
	friend struct OneTimeProcedureSorter;

	FIDString name;
	uint32 level;
	InitTermFunc func;
};

} // namespace Steinberg

//------------------------------------------------------------------------------
/** Get a classes initialization procedure name. */
//------------------------------------------------------------------------------
#define INIT_FUNCTION_NAME(name) init##name 
//------------------------------------------------------------------------------
/** Use this to call an initialization procedure directly. 
	Be aware that this does not unregister the procedure. It will be executed again, if terminate () is called !
*/
//------------------------------------------------------------------------------
#define INIT_FUNCTION(name) bool INIT_FUNCTION_NAME(name) ()

#define TERM_FUNCTION_NAME(name) term##name ///< Get a classes termination procedure name.
#define TERM_FUNCTION(name) bool TERM_FUNCTION_NAME(name) () ///< Use this to call a termination procedure directly. Be aware that this does not unregister the procedure. It will be executed again, if terminate () is called !

//------------------------------------------------------------------------------
/** Use this to register any initialization code. The name parameter must be unique in the code (for example a class name).
       Example:
	   \code
	   INITIALIZE (MyViewController)
	   {
		globalViewControllerRegistry->registerViewController(MyViewController::ClassId);
	   }
	   \endcode
*/
#define INITIALIZE(name)                                                   \
	INIT_FUNCTION(name);                                \
	::Steinberg::OneTimeProcedure name##Initializer (true, INIT_FUNCTION_NAME(name), #name);     \
	INIT_FUNCTION(name)
	
/** Same as INITIALIZE(name), but utilizes initialization levels (see enum InitLevel).
*/
#define INITIALIZE_LEVEL(name, level)                                            \
	INIT_FUNCTION(name);                                      \
	::Steinberg::OneTimeProcedure name##Initializer (true, INIT_FUNCTION_NAME(name), #name, level);    \
	bool init##name ()

/** Use this to register any termination. The name parameter must be unique in the code.
       Example:
	   \code
	  TERMINATE(MyViewController)
	   {
		globalViewControllerRegistry->unregisterViewController(MyViewController::ClassId);
	   }
	   \endcode
*/
#define TERMINATE(name)                                                    \
	TERM_FUNCTION(name);                                \
	::Steinberg::OneTimeProcedure name##Terminator (false, TERM_FUNCTION_NAME(name), #name);     \
	TERM_FUNCTION(name)  
 
 /** Same as TERMINATE(name), but utilizes levels (see enum InitLevel).
 */
#define TERMINATE_LEVEL(name, level)                                             \
	TERM_FUNCTION(name);                                      \
	::Steinberg::OneTimeProcedure name##Terminator (false, TERM_FUNCTION_NAME(name), #name, level);    \
	TERM_FUNCTION(name)                                                    

//------------------------------------------------------------------------
//	friend access for INITIALIZE and TERMINATE funcs of a class
#define FRIEND_INITIALIZE(name) friend INIT_FUNCTION(name);
#define FRIEND_TERMINATE(name) friend TERM_FUNCTION(name);


//------------------------------------------------------------------------
#define PRE_INITIALIZE(name) INITIALIZE_LEVEL(name, kInitLevelFirst)
#define POST_INITIALIZE(name) INITIALIZE_LEVEL(name, kInitLevelLast)

#endif

