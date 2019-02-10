//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/tqueue.h
// Created by  : Steinberg, 01/2009
// Description : Queue class template
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

#ifndef __tqueue__
#define __tqueue__

#include "base/source/tlist.h"

namespace Steinberg 
{

// -----------------------------------------------------------------
// Queue template definition.
// -----------------------------------------------------------------
/** Queue template.

	\ingroup baseContainer
	A queue is a "first in first out" (FIFO) data structure. 
	Elements are added to the back of the queue and may be removed from the front.
	Queue does not allow iteration through its elements. Only the top item of the 
	queue can be examined. */
// -----------------------------------------------------------------
template <class T> class TQueue : public TLinkedList<T>
{
public:
// -----------------------------------------------------------------------
	TQueue () {}								///< Default queue constructor.
	TQueue (const TQueue<T>&);					///< Queue copy constructor.
	~TQueue () {}								///< Queue destructor.

	TQueue<T>& operator= (const TQueue<T>&);	///< Assignment operator.

	bool enqueue (const T&);					///< Push item into queue.
	T dequeue ();								///< Pop front item from queue.
	T& peek () const;							///< Return copy of front item.
};

// -----------------------------------------------------------------------
/** "TQueue" is the queue copy constructor. 
	\param[in] queue : source queue */
// -----------------------------------------------------------------------
template <class T>
TQueue<T>::TQueue (const TQueue<T>& queue)
: TLinkedList<T> (queue)
{}

// -----------------------------------------------------------------------
/** The operator "=" copies the content of the input queue into this queue. 
	\param[in] queue : source queue
	\return : copy of the queue */
// -----------------------------------------------------------------------
template <class T>
TQueue<T>& TQueue<T>::operator= (const TQueue<T>& queue)
{
	if (&queue != this)
		this->copy(queue);
	return *this;
}

// -----------------------------------------------------------------------
/** The method "enqueue" adds a new item at the end of the queue.
	\param[in] obj : the new item which will be added to the queue.
	\return : true if item is successfully added / false if item is not added */
// -----------------------------------------------------------------------
template <class T>
bool TQueue<T>::enqueue (const T& obj)
{
	return this->append (obj);
}

// -----------------------------------------------------------------------
/** The method "dequeue" removes the top item from the queue.
	\return : copy of the removed item */
// -----------------------------------------------------------------------
template <class T>
T TQueue<T>::dequeue ()
{
	return this->removeFirst();
}

// -----------------------------------------------------------------------
/** The method "peek" returns a copy of the top queue item.
	\return : copy of the top queue item */
// -----------------------------------------------------------------------
template <class T>
T& TQueue<T>::peek () const
{
	return this->first();
}

}

#endif
