//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/updatehandler.cpp
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

#include "base/source/updatehandler.h"
#include "base/source/classfactory.h"
#include "base/source/tarray.h"
#include "base/source/tlist.h"

#define NON_EXISTING_DEPENEDENCY_CHECK 0 // not now, mm

namespace Steinberg  {

DEF_CLASS_IID (IUpdateManager)

namespace Update
{
	const uint32 kHashSize = (1 << 8);    // must be power of 2 (16 bytes * 256 == 4096)
	const uint32 kMapSize = 1024 * 10;		  

	inline uint32 hashPointer (void* p)
	{
		return (uint32)((uint64(p) >> 12) & (kHashSize - 1));
	}

	inline FUnknown* getUnknownBase (FUnknown* unknown)
	{
		FUnknown* result = 0;
		if (unknown)
			if (unknown->queryInterface (FUnknown::iid, (void**)&result) == kResultOk)
				unknown->release ();

		return result;
	}

	struct Dependency
	{
		Dependency (FUnknown* o = 0, IDependent* d = 0)
		: obj (o)
		, dep (d) 
		#if DEVELOPMENT
		, objClass (0)
		, depClass (0)
		#endif
		{}

		inline bool operator == (const Dependency& d) const { return obj == d.obj; }
		inline bool operator != (const Dependency& d) const { return obj != d.obj; }
		inline bool operator < (const Dependency& d) const { return obj < d.obj; }
		inline bool operator > (const Dependency& d) const { return obj > d.obj; }
		FUnknown* obj;
		IDependent* dep;

	#if DEVELOPMENT
		FClassID objClass;
		FClassID depClass;
	#endif
	};

	struct DeferedChange 
	{ 
		DeferedChange (FUnknown* o = 0, int32 m = 0) : obj (o), msg (m) { }
		~DeferedChange () {}
		DeferedChange (const DeferedChange& r) : obj (r.obj), msg (r.msg) { }
		inline bool operator == (const DeferedChange& d) const { return obj == d.obj; }
		inline bool operator != (const DeferedChange& d) const { return obj != d.obj; }
		FUnknown* obj; 
		int32 msg; 
	};	

	struct UpdateData
	{
		UpdateData (FUnknown* o = 0, IDependent** d = 0, uint32 c = 0) : obj (o), dependents (d), count (c) {}
		FUnknown* obj; 
		IDependent** dependents;
		uint32 count;
		bool operator == (const UpdateData& d) const {return d.obj == obj && d.dependents == dependents;}
	};

	struct Table
	{
		TOrderedArray<Dependency> map[kHashSize];
		TLinkedList<DeferedChange> defered;
		TLinkedList<UpdateData> updateData;
	};

	void updateDone (FUnknown* unknown, int32 message)
	{
		if (message != IDependent::kDestroyed)
		{
			FObject* obj = FObject::unknownToObject (unknown);
			if (obj)
				obj->updateDone (message);
		}
	}
}

//------------------------------------------------------------------------ 
SINGLE_CREATE_FUNC (UpdateHandler)
//_META_CLASS_IFACE (UpdateHandler, IUpdateHandler)
//_META_CLASS_IFACE (UpdateHandler, IUpdateManager)

//------------------------------------------------------------------------ 
UpdateHandler::UpdateHandler ()
: table (0)
{
	table = NEW Update::Table;
	if (FObject::getUpdateHandler () == 0)
		FObject::setUpdateHandler (this);
}

//------------------------------------------------------------------------ 
UpdateHandler::~UpdateHandler ()
{
	if (FObject::getUpdateHandler () == this)
		FObject::setUpdateHandler (0);
	delete table;
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::addDependent (FUnknown* u, IDependent* dependent)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (!unknown || !dependent)
		return kResultFalse;

	FGuard guard (lock);
	Update::Dependency d (unknown, dependent);

#if DEVELOPMENT
	FObject* obj = FObject::unknownToObject (unknown);
	if (obj)
		d.objClass = obj->isA ();
	obj = FObject::unknownToObject (dependent);
	if (obj)
		d.depClass = obj->isA ();
#endif

	table->map[Update::hashPointer (unknown)].add (d);
	return kResultTrue;
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::removeDependent (FUnknown* u, IDependent* dependent)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (unknown == 0 && dependent == 0)
		return kResultFalse;

	FGuard guard (lock);

	FOREACH_T (Update::UpdateData, data, table->updateData)
		if (data.obj == unknown || unknown == 0)
		{
			for (uint32 count = 0; count < data.count; count++)
			{
				if (data.dependents [count] == dependent)
					data.dependents [count] = 0;
			}
		}
	ENDFOR

	if (unknown == 0)            // Remove all objects for dependent
	{
		for (uint32 j = 0; j < Update::kHashSize; j++)
		{
			for (int32 i = 0; i < table->map[j].total (); i++)
			{
				while (table->map[j].at(i).dep == dependent)
				{
					table->map[j].removeAt (i);
					i--;
				}
			}
		}
	}
	else
	{
		Update::Dependency d (unknown, dependent);
		TOrderedArray<Update::Dependency>& m = table->map[Update::hashPointer (unknown)];

		bool mustFlush = true;

		int32 index = m.index (d);
		
#if NON_EXISTING_DEPENEDENCY_CHECK
		ASSERT (index >= 0 && "ERROR: Trying to remove a non existing dependency!") 
#endif
		if (index >= 0)
		{
			if (dependent == 0)    // Remove all dependents of object
			{
				while (m.at (index) == d)
					m.removeAt (index);			
			}
			else // Remove one dependent
			{
				for (int32 i = index; i < m.total (); i++)
				{
					Update::Dependency& dep = m.at (i);
					if (dep.obj != unknown)
						break;
					if (dep.dep == dependent)
					{
						m.removeAt (i);
						i--;
					}
					else
						mustFlush = false;
				}
			}
		}
		if (mustFlush)
			cancelUpdates (unknown);
	}

	return kResultTrue;
}

//------------------------------------------------------------------------ 
tresult UpdateHandler::doTriggerUpdates (FUnknown* u, int32 message, bool suppressUpdateDone)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (!unknown)
		return kResultFalse;

#define DYNAMIC_DEPENDENTS_MAPSIZE 1
#if DYNAMIC_DEPENDENTS_MAPSIZE
	// to avoid crashes due to stack overflow, we reduce the amount of memory reserved for the dependents
	// (this might no longer necessary once the envelopeview in the halion project is refactored to
	//  not cause recursive updates)
	IDependent* smallDependents[Update::kMapSize / 10]; // 8kB for x64
	IDependent** dependents = smallDependents;
	int32 maxDependents = Update::kMapSize / 10;
#else
	IDependent* dependents[Update::kMapSize];
	static const int32 maxDependents = Update::kMapSize;
#endif
	int32 count = 0;
 
	{	FGuard g (lock); // scope for lock

		TOrderedArray<Update::Dependency>& m = table->map[Update::hashPointer (unknown)];
		Update::Dependency d (unknown, 0);

		int32 index = m.index (d);
		if (index >= 0)
		{
			while (true)
			{
				dependents[count] = m.at(index).dep;
				count++;
				index++;
				if (m.at (index).obj != unknown)
					break;

				if (count >= maxDependents)
				{
#if DYNAMIC_DEPENDENTS_MAPSIZE
					if (dependents == smallDependents)
					{
						dependents = new IDependent*[Update::kMapSize];
						memcpy (dependents, smallDependents, count * sizeof (dependents[0]));
						maxDependents = Update::kMapSize;
					}
					else
#endif
					{
						WARNING ("Dependency overflow")
						break;
					}
				}
			}
		}

		// push update data on the stack
		if (count > 0)
		{
			Update::UpdateData data (unknown, dependents, count);
			table->updateData.append (data);
		}
	}

	int32 i = 0;
	while (i < count)
	{
		if (dependents[i])
			dependents[i]->update (unknown, message);
		i++;
	}

#if DYNAMIC_DEPENDENTS_MAPSIZE
	if (dependents != smallDependents)
		delete [] dependents;
#endif

	// remove update data from the stack
	if (count > 0)
	{
		FGuard g (lock);
		table->updateData.removeLast ();
	}

	// send update done message
	if (suppressUpdateDone == false)
		Update::updateDone (unknown, message);

	return count > 0 ? kResultTrue : kResultFalse; // Object was found and has been updated
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::triggerUpdates (FUnknown* u, int32 message)
{
	return doTriggerUpdates (u, message, false);
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::deferUpdates (FUnknown* u, int32 message)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (!unknown)
		return kResultFalse;

	FGuard g (lock);

	TOrderedArray<Update::Dependency>& m = table->map[Update::hashPointer (unknown)];
	Update::Dependency d (unknown, 0);
	bool hasDependency = m.index (d) >= 0;

	if (hasDependency == false)
	{
		Update::updateDone (unknown, message);
		return kResultTrue;
	}

	bool found = false;
	TLinkedListIterator <Update::DeferedChange> iter (table->defered);
	while (iter.done () == false)
	{
		const Update::DeferedChange& dc = iter.next ();
		if (dc.obj == unknown && dc.msg == message)
		{
			found = true;
			break;
		}
	}

	if (!found)
	{
		Update::DeferedChange change (unknown, message);
		table->defered.append (change);
	}

	return kResultTrue;
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::triggerDeferedUpdates (FUnknown* unknown)
{
	TLinkedList<Update::DeferedChange> deferedAgain;

	if (!unknown)
	{
		while (table->defered.isEmpty () == false)
		{
			// Remove first from queue
			lock.lock ();

			FUnknown* obj = table->defered.first ().obj;
			int32 msg = table->defered.first().msg;
			table->defered.removeFirst ();

			// check if this object is currently being updated. in this case, defer update again...
			bool canSignal = true;
			FOREACH_T (Update::UpdateData, data, table->updateData)
				if (data.obj == obj)
				{
					canSignal = false;
					break;
				}
			ENDFOR

			lock.unlock ();
		
			if (canSignal)
			{
				triggerUpdates (obj, msg);
			}
			else
			{
				Update::DeferedChange change (obj, msg);
				deferedAgain.append (change);
			}
		}

	}
	else
	{
		FUnknown* object = Update::getUnknownBase (unknown);
		Update::DeferedChange tmp (object);
	
		while (true)
		{		
			lock.lock ();
			int32 index = table->defered.index (tmp);
			if (index < 0)
			{
				lock.unlock ();
				return kResultTrue;
			}
			Update::DeferedChange& def = table->defered.at (index); 
			if (def.obj != 0)
			{			
				int32 msg = def.msg;
				table->defered.removeAt (index);
				
				// check if this object is currently being updated. in this case, defer update again...
				bool canSignal = true;
				FOREACH_T (Update::UpdateData, data, table->updateData)
					if (data.obj == object)
					{
						canSignal = false;
						break;
					}
				ENDFOR

				lock.unlock ();
				
				if (canSignal)
				{
					triggerUpdates (object, msg);
				}
				else
				{
					Update::DeferedChange change (object, msg);
					deferedAgain.append (change);
				}
			}	
		}			
	}

	if (deferedAgain.isEmpty () == false)
	{
		FGuard guard (lock);
		TLinkedListIterator <Update::DeferedChange> iter (deferedAgain);
		while (!iter.done ())
			table->defered.append (iter.next ());
	}

	return kResultTrue;
}

//------------------------------------------------------------------------ 
tresult PLUGIN_API UpdateHandler::cancelUpdates (FUnknown* u)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (!unknown)
		return kResultFalse;

	FGuard guard (lock);

	Update::DeferedChange change (unknown, 0);
	while (table->defered.remove (change)) 
	{
	}
	return kResultTrue;
}


#if DEVELOPMENT

//------------------------------------------------------------------------ 
bool UpdateHandler::checkDeferred (FUnknown* object)
{
	FUnknown* unknown = Update::getUnknownBase (object);
	
	FGuard guard (lock);
	TLinkedListIterator <Update::DeferedChange> iter (table->defered);
	while (iter.done () == false)
	{
		if (iter.next ().obj == unknown)
			return true;
	}
	return false;
}

//------------------------------------------------------------------------ 
bool UpdateHandler::hasDependencies (FUnknown* u)
{
	FUnknown* unknown = Update::getUnknownBase (u);
	if (!unknown)
		return false;

	FGuard g (lock);

	TOrderedArray<Update::Dependency>& m = table->map[Update::hashPointer (unknown)];
	Update::Dependency d (unknown, 0);
	bool hasDependency = m.index (d) >= 0;
	return hasDependency;
}

//------------------------------------------------------------------------ 
void UpdateHandler::printForObject (FObject* obj) const
{
	FUnknown* unknown = Update::getUnknownBase (obj);
	if (!unknown)
		return;

	FUnknownPtr<IDependent> dep (obj);

	bool header = false;

	TOrderedArray<Update::Dependency>& m = table->map[Update::hashPointer (unknown)];

	for (int32 i = 0; i < m.total (); i++) 
	{
		const Update::Dependency& d = m.at (i);

		if (d.obj == unknown || d.dep == dep.getInterface ()) 
		{
			if (!header) 
			{
				FDebugPrint ("Dependencies for object %8" FORMAT_INT64A" %s\n", (uint64)obj, obj->isA ());
				header = true;
			}
			FDebugPrint ("%s %8" FORMAT_INT64A"\n <- %s %8" FORMAT_INT64A"\n", d.depClass, (uint64)d.dep, d.objClass, (uint64)d.obj);
		}
	}
}

#endif

} // namespace Steinberg
