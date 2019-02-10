//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/finitializer.cpp
// Created by  : Steinberg, 2008
// Description : Global Initializers / Terminators
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

#include "base/source/finitializer.h"
#include "base/source/tarray.h"
#include "base/source/fdebug.h"

#define PRINT_INITIALIZER_NAMES	(DEVELOPMENT && 0)
#define PRINT_TERMINATOR_NAMES	(DEVELOPMENT && 0)

//------------------------------------------------------------------------------
//	OneTimeProcedure 
//------------------------------------------------------------------------------

namespace Steinberg {

struct OneTimeProcedureSorter
{
	OneTimeProcedureSorter (OneTimeProcedure* otp = 0) : p (otp) {}

	inline bool operator == (const OneTimeProcedureSorter& s) const { return p->level == s.p->level; }
	inline bool operator != (const OneTimeProcedureSorter& s) const { return p->level != s.p->level; }
	inline bool operator < (const OneTimeProcedureSorter& s) const { return p->level < s.p->level; }
	inline bool operator > (const OneTimeProcedureSorter& s) const { return p->level > s.p->level; }
	inline bool operator <= (const OneTimeProcedureSorter& s) const { return p->level <= s.p->level; }
	inline bool operator >= (const OneTimeProcedureSorter& s) const { return p->level >= s.p->level; }

	OneTimeProcedure* p;
};

static TOrderedArray<OneTimeProcedureSorter>* gInitializers = 0;
static TOrderedArray<OneTimeProcedureSorter>* gTerminators = 0;

//------------------------------------------------------------------------------
bool OneTimeProcedure::initPerformed = false;

//------------------------------------------------------------------------------
OneTimeProcedure::OneTimeProcedure (bool isInit, InitTermFunc f, FIDString name, uint32 level)
: func (f)
, name (name)
, level (level)
{
	if (isInit)
	{
		if (gInitializers == 0)
			gInitializers = NEW TOrderedArray<OneTimeProcedureSorter> (64,64);

		gInitializers->add (this);
	}
	else
	{
		if (gTerminators == 0)
			gTerminators = NEW TOrderedArray<OneTimeProcedureSorter> (64,64);

		gTerminators->add (this);
	}
}

//------------------------------------------------------------------------------
void OneTimeProcedure::cancel ()
{
	if (gInitializers)
		delete gInitializers;
	gInitializers = 0;
	if (gTerminators)
		delete gTerminators;
	gTerminators = 0;
}

//------------------------------------------------------------------------------
bool OneTimeProcedure::initialize (uint32 untilLevel)
{
	initPerformed = true;

	if (gInitializers == 0)
		return true;

	bool result = true;
	
	for (int32 i = 0; i < gInitializers->total (); i++)
	{
		OneTimeProcedure* p = gInitializers->at (i).p;

		if (p->level > untilLevel)
		{
			gInitializers->removeRange (0, i-1);
			return true;
		}

		if (p->func () == false)
		{
			result = false;
			DBPRT1 ("Init of %25s failed\n", p->name)
			break;
		}
		#if PRINT_INITIALIZER_NAMES
		DBPRT2 ("Initialized Level %3d '%25s'\n", p->level, p->name)
		#endif
	}

	delete gInitializers;
	gInitializers = 0;
	return result;
}

//------------------------------------------------------------------------------
bool OneTimeProcedure::terminate ()
{
	if (gTerminators == 0)
		return true;

	if (initPerformed)
	{
		for (int32 i = 0; i < gTerminators->total (); i++)
		{
			OneTimeProcedure* p = gTerminators->at (i).p;
			p->func ();

			#if PRINT_TERMINATOR_NAMES
			DBPRT2 ("Terminated Level %3d '%25s'\n", p->level, p->name)
			#endif
		}
	}

	delete gTerminators;
	gTerminators = 0;
	return true;
}

} // Steinberg
