//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/frwlock_generic.h
// Created by  : Steinberg, 2014
// Description : generic code for RW locks (multiple reader, single writer)
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
//----------------------------------------------------------------------------------

#ifndef __frwlock_generic__
#define __frwlock_generic__

namespace Steinberg {

//---------------------------------------------
// per thread recursion counting
// each thread context will create an instance and
// shares it between multiple RWLocks via FLocalThreadStorage.
// RWLockRecursion contains an association between a lock-key and the recursion count/access type
// Each RWLock will provide a unique lock key, e.g. its instance address.
// Design idea:
// - There are fewer threads than RWLocks, move the storage into the thread not into the RWLock instance
// - Thread local storage also removes the need for a mutex, they are serial per definition (OS offer very efficient access to TLS)
// - Provide sufficient efficient use of lookup/allocation of RWLock access per thread (small fixed size pool)
// Inherits FUnknown to comply with FLocalThreadStorage semantics for automatic thread termination cleanup
//---------------------------------------------
class RWLockRecursion : public FUnknown
{
public:
	enum
	{
		// Holding more than 16 different RWLocks is a ticket to hell, IMHO
		// if more simultaneous locks per threads are needed, a more complicated data structure is required for performance
		kMaxRWLocksPerThread = 16,

		// accessTypes for acquireRecursionCount()
		kNoAccess = 0,
		kReadAccess = 1,
		kWriteAccess = 2,

		// options for releaseRecursionCount()
		kArbitraryRelease = 1 << 0,	// disable check for LIFO base release, this option should be used only for very special cases, normally this pattern leads to deadlocks

		// error codes for acquireRecursionCount()/releaseRecursionCount()
		kErrorLockInbalance = -1,	// more unlock than lock operations
		kErrorLockThreadLocalStorage = -2,	//<< no thread local storage for the recurion counting exists
		kErrorReadToWriteUpgrade = -3,	//<< illegal write to existing read access, deadlock will be the result
		kErrorOutOfMemory = -4	//<< more than kMaxRWLocksPerThread are used
	};

	//---------------------------------------------
	// intialize global recursionLockStorage instance, which is the key element to provide thread local storage
	static void initializeGlobalRecursionData ()
	{
		FLocalThreadStorage::initStates ();	// enforce destruction order of static instances: RWLockRecursion before FLocalThreadStorage
		getRecursionLockStorage().init();
	}

	//---------------------------------------------
	// returns the updated recursion count,
	// initial acquisition for a lock: result is 1
	// negative result indicates an error
	static int32 acquireRecursionCount (void* lockKey, int32 accessType)
	{
		// sorry, it's performance relevant, so no expensive queryInterface
		RWLockRecursion* recursionData = (RWLockRecursion*)getRecursionLockStorage().get().getData();
		
		// lazy initialization
		if (recursionData == 0)
		{
			recursionData = createPerThreadRecursionData ();
			if (recursionData == 0)
				return kErrorLockThreadLocalStorage;
		}
		
		return recursionData->acquireAccess (lockKey, accessType);
	}
	
	//---------------------------------------------
	// returns the updated recursion count,
	// final release for a lock: result is 0
	// negative result indicates an error
	// optionFlags: use kArbitraryRelease only if the SW design is proven to work in such a condition.
	// In most common SW designs it is an indicator for potential deadlock conditions.
	static int32 releaseRecursionCount (void* lockKey, int accessType, int32 optionFlags = 0)
	{
		// sorry, it's performance relevant, so no expensive query interface
		RWLockRecursion* recursionData = (RWLockRecursion*)getRecursionLockStorage().get().getData();

		PANIC_ASSERT (recursionData != 0, kErrorLockThreadLocalStorage)	/* RWLockRecursion:: per thread data missing */
		if (recursionData == 0)
			return kErrorLockThreadLocalStorage;

		return recursionData->releaseAccess (lockKey, accessType, optionFlags);
	}
private:
	//---------------------------------------------
	RWLockRecursion ()
	{
		FUNKNOWN_CTOR
	}
	
	//---------------------------------------------
	virtual ~RWLockRecursion ()
	{
		// catch dangling locks in the thread context, check thread, which locks it might hold
		PANIC_ASSERT (recursionCounts.isEmpty (), kErrorLockInbalance)
		
		FUNKNOWN_DTOR
	}
	
	//---------------------------------------------
	DECLARE_FUNKNOWN_METHODS
	

	//---------------------------------------------
	struct RecursionCount
	{
		void* key;	// RWLock platform neutral key
		int32 count;
		int32 accessType;
	};
	
	//---------------------------------------------
	// light weight container, to be replaced with a proper container template later on
	//---------------------------------------------
	struct RecursionCounts
	{
		RecursionCounts ()
		: maxAcquiredItem (&recursionCounts[0] - 1)
		, lastLookupItem (&recursionCounts[0])
		{
			for (int32 i = 0; i < kMaxRWLocksPerThread; i++)
			{
				recursionCounts[i].key = 0;
				recursionCounts[i].count = 0;
				recursionCounts[i].accessType = kNoAccess;
			}
		}

		//---------------------------------------------
		bool isEmpty () const
		{
			if (maxAcquiredItem >= &recursionCounts[0])
				return false;

			return true;
		}

		//---------------------------------------------
		RecursionCount* lookupKey (void* lockKey)
		{
			// fast check case for test of first lock acquire in the thread context
			if (maxAcquiredItem < lastLookupItem)
				return 0;

			// cache for the last lookup to speed up simple recursive RWLock lock/unlocks on the thread
			if (lastLookupItem->key == lockKey)
				return lastLookupItem;

			// search for containment backwards, recursive identical lock acquisition is the normal expected pattern
			// starting from the end usually is faster
			RecursionCount* item = maxAcquiredItem;
			for (item = maxAcquiredItem; item >= &recursionCounts[0]; item--)
			{
				if (item->key == lockKey)
					return (lastLookupItem = item);
			}
			return 0;
		}

		//---------------------------------------------
		RecursionCount* allocateKey ()
		{
			RecursionCount* nextSlot = maxAcquiredItem + 1;
			if (nextSlot >= &recursionCounts[kMaxRWLocksPerThread])
				return 0;

			// allocate a new assignment (always increasing, holes will not be filled)
			// - it's need to be fast on normal operation - not usig defensive programming
			maxAcquiredItem = nextSlot;
			return (lastLookupItem = maxAcquiredItem);
		}

		//---------------------------------------------
		bool deallocateKey (RecursionCount* recursion)
		{
			// deallocate the key
			recursion->key = 0;

			// invalidate the lookup cache
			if (lastLookupItem == recursion)
				lastLookupItem = &recursionCounts[0];

			// update the stack top if the deallocated element is at the stack top
			if (recursion == maxAcquiredItem)
			{
				// skip any existing holes in the allocation
				while (--maxAcquiredItem >= &recursionCounts[0] && maxAcquiredItem->key == 0)
					;
				return true;	// top most deallocated
			}
			return false;	// arbitrary deallocation (should never happen)
		}
		
		//---------------------------------------------
		RecursionCount recursionCounts[kMaxRWLocksPerThread];	///< per thread RWLock acquisition constainer (random access, LIFO result preferred)
		RecursionCount* maxAcquiredItem;
		RecursionCount* lastLookupItem;	// cache for the most recent lookup, most common case use
	};
	
	//---------------------------------------------
	static RWLockRecursion* createPerThreadRecursionData ()
	{
		// no need for locks, FLocalThreadStorage handles this
		RWLockRecursion* newRecursionCount = NEW RWLockRecursion;

		bool tlsDataAdded = getRecursionLockStorage().get().setData(newRecursionCount);
		newRecursionCount->release ();

		if (tlsDataAdded)
			return newRecursionCount;

		/* RWLockRecursion::Thread Local Storage failed, setData() is damned to succeed */
		PANIC_ASSERT (tlsDataAdded, kErrorLockThreadLocalStorage)

		return 0;
	}
	
	//---------------------------------------------
	static bool tryingWriteAccessOnExistingReadAccess (int32 accessType, const struct RecursionCount* slot)
	{
		if (accessType == kWriteAccess && slot->accessType == kReadAccess)
			return true;
		return false;
	}

	//---------------------------------------------
	static bool allowArbitraryRelease (int32 options)
	{
		return (options & kArbitraryRelease) ? true : false;
	}

	//---------------------------------------------
	int32 acquireAccess (void* lockKey, int32 accessType)
	{
		RecursionCount* recursion = recursionCounts.lookupKey (lockKey);
	
		// Handle recursive call
		if (recursion)
		{
			// Allow read after write (state remains write)
			// write after read is a fatal error
			if (tryingWriteAccessOnExistingReadAccess (accessType, recursion))
			{
				// FATAL it should crash here not later
				PANIC_ASSERT (!(tryingWriteAccessOnExistingReadAccess (accessType, recursion)), kErrorReadToWriteUpgrade)
				return kErrorReadToWriteUpgrade;
			}

			recursion->count++;
			return recursion->count;
		}

		// allocate a new assignment
		RecursionCount* newRecursion = recursionCounts.allocateKey ();
		if (newRecursion)
		{
			// This local copy construct seems to provide slighlty better compiled code
			RecursionCount initData = {lockKey, 1, accessType};
			*newRecursion = initData;

			return newRecursion->count;
		}

		// allocation was not possible, this is FATAL and should crash here not later
		PANIC_ASSERT (false, RWLockRecursion::kErrorOutOfMemory)
		return kErrorOutOfMemory;
	}

	//---------------------------------------------
	int32 releaseAccess (void* lockKey, int32 accessType, int32 optionFlags)
	{
		// search for containment
		RecursionCount* recursion = recursionCounts.lookupKey (lockKey);
		if (recursion == 0)
		{
			// removed RWLock was tried to removed again, this is FATAL and should crash here not later
			PANIC_ASSERT (false, RWLockRecursion::kErrorLockInbalance)
			return kErrorLockInbalance;
		}

		PANIC_ASSERT (recursion->count > 0, RWLockRecursion::kErrorLockInbalance)

		recursion->count--;

		// if recursion not back to 0 return the result
		if (recursion->count != 0)
			return recursion->count;

		// Development check only so far, its bad to release a lock with the wrong mode
		// Indicator for a lock/unlock order change
		PANIC_ASSERT (accessType == recursion->accessType, RWLockRecursion::kErrorLockInbalance)

		// deallocate the key storage when releasing the last recursion
		if (recursionCounts.deallocateKey (recursion) == false)
		{
			// deallocation succeeded but the ordering just does not look right, this can result in deadlocks
			// Though in some design's migth require this. Remove the assert then.
			if (!allowArbitraryRelease (optionFlags))
			{
				WARNING ("RWLock released in different order than acquired. This might be a dead lock potential.");
				PANIC_ASSERT (false, RWLockRecursion::kErrorLockInbalance)
			}
		}
		return 0;
	}

	//---------------------------------------------
	RecursionCounts recursionCounts;	// thread local storage for RWLock recursion handling

	//---------------------------------------------
	// Thread safe on demand singleton for FLocalThreadStorage management
	// wrap FLocalThreadStorage to achieve thread safety and end of process cleanup
	//---------------------------------------------
	struct TLS
	{
		//---------------------------------------------
		TLS ()
		: tls (0)
		{
		}
		
		//---------------------------------------------
		~TLS ()
		{
			FGuard guard (initGuard);	// avoid process termination race, deadlock instead
			if (tls)
			{	// TODO: This needs to be done in the FLocalThreadStorage destructor.
				FUnknown* mainThreadZombieDataSet = tls->getData();
				if (mainThreadZombieDataSet)
					mainThreadZombieDataSet->release ();
				delete tls;
			}
		}
		
		//---------------------------------------------
		FLocalThreadStorage& get () const
		{
			PANIC_ASSERT (tls != 0, kErrorLockThreadLocalStorage)	// successful init call was mandatory
			return *tls;
		}
		
		//---------------------------------------------
		void init ()
		{
			// trick the system to accept "tls" as volatile
			volatile FLocalThreadStorage** globalTls = (volatile FLocalThreadStorage**)&tls;
			
			// fast exit, if already initialized
			if (*globalTls != 0)
				return;
			
			// rare initialization phase during program start up
			{
				FGuard guard (initGuard);
				if (*globalTls != 0)	// in the meantime another initializer succeeded
					return;

				FLocalThreadStorage* newIstance = FLocalThreadStorage::create ();

				bool firstTimeSet = FAtomicCompareAndSwap (*(volatile void**)&tls, (void*)0, (void*)newIstance);
				PANIC_ASSERT (firstTimeSet == true, kErrorLockThreadLocalStorage)	// assure that the compiler is not setting an incomplete instance
			}
		}

		//---------------------------------------------
		FLocalThreadStorage *tls;
		FLock initGuard; // lock to secure the initialization/termination phase
	};
	
	//---------------------------------------------
	static TLS& getRecursionLockStorage()
	{
		static TLS recursionLockStorage;
		return recursionLockStorage;
	}
};

} // Steinberg

#endif
