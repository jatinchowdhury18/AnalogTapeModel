//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/tstack.h
// Created by  : Steinberg, 01/2009
// Description : Template stack container
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

#ifndef __tstack__
#define __tstack__

#include "base/source/tlist.h"

namespace Steinberg {
	
// -----------------------------------------------------------------
/** @class TStack
	@ingroup baseContainer
	
	TStack is a template container based on the LIFO-principle (last in/first out).
	http://en.wikipedia.org/wiki/Stack_(data_structure)

	Return values in error cases: @see TContainer */
// -----------------------------------------------------------------
template <class T> class TStack : public TLinkedList<T>
{
public:
// -----------------------------------------------------------------
	TStack() {}										///< Default stack constructor.
	TStack(const TStack<T>&);						///< Stack copy constructor.
	~TStack() {}									///< Stack destructor.

	TStack<T>& operator=(const TStack<T>&);			///< Assignment operator.

	bool     push (const T&);						///< Push item onto stack (add to stack)
	T        pop  ();								///< Pop top item from stack (return copy of item and remove from stack)
	const T& peek () const;							///< Return top item (but leave item on the stack)
};

// -----------------------------------------------------------------
template <class T>
TStack<T>::TStack(const TStack<T>& stack)
: TLinkedList<T>(stack)
{}


// -----------------------------------------------------------------
/*! \param stack Assignment operator copies the contents of the input stack into this stack. */
// -----------------------------------------------------------------
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& stack)
{
	if (&stack != this) 
		copy(stack);
	return *this;
}


// -----------------------------------------------------------------
/*! \return Returns true if new item was added successfully. */
template <class T>
bool TStack<T>::push(const T& obj)
{
	return this->prepend(obj);
}

// -----------------------------------------------------------------
template <class T>
T TStack<T>::pop()
{
	return this->removeFirst();
}


// -----------------------------------------------------------------
template <class T>
const T& TStack<T>::peek() const
{
	return this->first();
}

}

#endif
