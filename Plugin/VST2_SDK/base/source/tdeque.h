//-------------------------------------------------------------------------------------
// Project      : SDK Base
// Version      : 1.0
//
// Category	    : Helpers
// Filename	    : base/source/tdeque.h
// Created by   : Steinberg, 04/2008
// Description  : Deque class template
//
//-------------------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------

#ifndef __tdeque__
#define __tdeque__

#include "base/source/tlist.h"

namespace Steinberg {

//-------------------------------------------------------------------------------------
/** @class TDeque
	@ingroup baseContainer
	TDeque is a double ended queue. Items can be pushed or popped to the left and right
	end of the queue.
	@see TContainer, TLinkedList
*/
//-------------------------------------------------------------------------------------
template <class T>
class TDeque : public TLinkedList<T>
{
public:
//-------------------------------------------------------------------------------------
	TDeque () {}                                  ///< Default constructor.
	TDeque (const TDeque<T>&);                    ///< Copy constructor.
	~TDeque () {}                                 ///< Destructor.

	TDeque<T>& operator= (const TDeque<T>&);     ///< Assignment operator.

	bool     pushLeft  (const T&);               ///< Push item into queue left.
	bool     pushRight (const T&);               ///< Push item into queue right.
	T        popLeft   ();                       ///< Pop item from queue left.
	T        popRight  ();                       ///< Pop item from queue right.
	const T& peekLeft  () const;                 ///< Return copy of left item.
	const T& peekRight () const;                 ///< Return copy of right item.
//-------------------------------------------------------------------------------------
};



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// "TDeque" is the deque copy constructor.
//-------------------------------------------------------------------------------------
/*! @param[in] deque Deque to copy. */
//-------------------------------------------------------------------------------------
template <class T>
TDeque<T>::TDeque (const TDeque<T>& deque)
: TLinkedList<T> (deque)
{

}


//-------------------------------------------------------------------------------------
// "=" assignment operator copies the contents of the input queue into this queue.
//-------------------------------------------------------------------------------------
/*! @param[in] deque Assign left side (this) to deque.
	@return Assigned double ended queue. */
//-------------------------------------------------------------------------------------
template <class T>
TDeque<T>& TDeque<T>::operator= (const TDeque<T>& deque)
{
	return (TDeque<T>&) TLinkedList<T>::operator= (deque);
}


//-------------------------------------------------------------------------------------
// "pushLeft" pushes the specified item into queue left.
//-------------------------------------------------------------------------------------
/*! @param[in] obj Item to push on left side.
	@return true, if pushed.
	@return false, if failed */
//-------------------------------------------------------------------------------------
template <class T>
bool TDeque<T>::pushLeft (const T& obj)
{
	return prepend (obj);
}


//-------------------------------------------------------------------------------------
// "pushRight" pushes the specified item into queue right.
//-------------------------------------------------------------------------------------
/*! @param[in] obj Item to push on right side.
	@return true, if pushed.
	@return false, if failed */
//-------------------------------------------------------------------------------------
template <class T>
bool TDeque<T>::pushRight (const T& obj)
{
	return append (obj);
}


//-------------------------------------------------------------------------------------
// "popLeft" removes the left item from the queue and returns a copy.
//-------------------------------------------------------------------------------------
/*! @return Removed item. */
//-------------------------------------------------------------------------------------
template <class T>
T TDeque<T>::popLeft ()
{
	return this->removeFirst ();
}


//-------------------------------------------------------------------------------------
// "popRight" removes the right item from the queue and returns a copy.
//-------------------------------------------------------------------------------------
/*! @return Removed item */
//-------------------------------------------------------------------------------------
template <class T>
T TDeque<T>::popRight ()
{
	return this->removeLast ();
}


//-------------------------------------------------------------------------------------
// "peekLeft" returns a copy of the left queue item.
//-------------------------------------------------------------------------------------
/*! @return Copy of item on left end of queue */
//-------------------------------------------------------------------------------------
template <class T>
const T& TDeque<T>::peekLeft () const
{
	return this->first ();
}


//-------------------------------------------------------------------------------------
// "peekRight" returns a copy of the right queue item.
//-------------------------------------------------------------------------------------
/*! @return Copy of item on right end of queue */
//-------------------------------------------------------------------------------------
template <class T>
const T& TDeque<T>::peekRight () const
{
	return this->last ();
}


} //namespace

#endif
