//------------------------------------------------------------------------ 
// Project     : SDK Base 
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/tbinarytree.h
// Created by  : Steinberg, 1998
// Description : Binary Tree class template
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

#ifndef __tbinarytree__
#define __tbinarytree__

#include "base/source/tqueue.h"
#include "base/source/tstack.h"

namespace Steinberg {

template <class T> class TBinaryTreeNode;
template <class T> class TBinaryTreeIterator;

//-----------------------------------------------------------------------------
/** TBinaryTree is a rooted binary tree.
@ingroup baseContainer

From wikipedia:
A binary tree is a connected acyclic graph such that the degree of each vertex is no more than 3.
It can be shown that in any binary tree, there are exactly two more nodes of degree one than there are of degree three,
but there can be any number of nodes of degree two.
A rooted binary tree is such a graph that has one of its vertices of degree no more than 2 singled out as the root.
*/
//-----------------------------------------------------------------------------
template <class T> class TBinaryTree : public TContainer<T>
{
public:
// -----------------------------------------------------------------
	TBinaryTree ();										///< Default constructor.
	TBinaryTree (const TBinaryTree<T>&);				///< Copy constructor.
	TBinaryTree (const TContainer<T>&);					///< Construct from container.
	~TBinaryTree ();									///< Tree destructor.

	virtual TContainer<T>* newInstance () const;

	TBinaryTree<T>& operator=(const TBinaryTree<T>&);	///< Assignment. 

	virtual bool add (const T&);								///< Add item to tree.
	virtual bool remove (const T&);								///< Remove item from tree.
	virtual bool remove (const TIterator<T>&);					///< Remove iterator item.
	virtual bool removeAt (int32 index);						///< Remove item at index.
	virtual void removeAll ();									///< Remove all items.

	const T& root () const;								///< Return root tree item.
	void balance ();									///< Balance the tree.

	virtual T& lookup (const T&) const;					///< Find equal item in tree.
	virtual bool contains (const T&) const;				///< Is equal item in tree?
	virtual int32 occurrences (const T&) const;			///< Count occurrences of item.

	TIterator<T>* newIterator() const;					///< Get tree iterator.
// -----------------------------------------------------------------
private:
	bool removeNode (TBinaryTreeNode<T>*, TBinaryTreeNode<T>*); ///< Remove node.
	void balanceHalf (const TQueue<T>&, int32, int32);	///< Balance tree half.

	static void killNode (TBinaryTreeNode<T>*);			///< Destroy node children.

	TBinaryTreeNode<T> *_root;							///< Tree root node.

	friend class TBinaryTreeIterator<T>;				///< Iterator can access.
};

/// \cond ignore
// The other classes in this file should be treated private !

// -----------------------------------------------------------------
// TBinaryTreeIterator
// -----------------------------------------------------------------
template <class T> class TBinaryTreeIterator : public TIterator<T>
{
public:
// -----------------------------------------------------------------
	TBinaryTreeIterator (const TBinaryTree<T>&);		///< Iterator constructor.

	bool done () const;									///< Check if end of container.
	virtual T& next ();									///< Advance and return.
	virtual T& previous ();								///< Return and backup.
	virtual T& current () const;							///< Return current item.
	void first ();										///< Move to first item.
	void last ();										///< Move to last item.

	const TBinaryTree<T>& tree () const;				///< Return tree reference.
// -----------------------------------------------------------------

private:
	TBinaryTreeNode<T>           *_node;				///< Current tree node.
	TStack<TBinaryTreeNode<T>*> _stack;					///< Node stack.
};


// -----------------------------------------------------------------
// TBinaryTreeNode
// -----------------------------------------------------------------
template <class T> class TBinaryTreeNode
{
// -----------------------------------------------------------------
private:
	TBinaryTreeNode(const T& D)							///< Node constructor.
		: _left(0), _data(D), _right(0) {}

	TBinaryTreeNode<T>* _left;							///< Left node from this.
	T _data;											///< Node key (data).
	TBinaryTreeNode<T>* _right;							///< Right node from this.

	friend class TBinaryTree<T>;						///< Tree class can access.
	friend class TBinaryTreeIterator<T>;				///< Iterator can access.
};


// -----------------------------------------------------------------
// -----------------------------------------------------------------
// -----------------------------------------------------------------


// -----------------------------------------------------------------
// "TBinaryTree" is the default tree constructor.
// -----------------------------------------------------------------
template <class T> TBinaryTree<T>::TBinaryTree()
: _root(0)
{}


// -----------------------------------------------------------------
// "TBinaryTree" is the tree copy constructor.
// -----------------------------------------------------------------
template <class T>
TBinaryTree<T>::TBinaryTree(const TBinaryTree<T>& tree)
: TContainer<T>(tree), _root(0)
{
	copy   (tree);
	balance();
}


// -----------------------------------------------------------------
// "TBinaryTree" constructs a binary tree from the specified
// container.
// -----------------------------------------------------------------
template <class T>
TBinaryTree<T>::TBinaryTree(const TContainer<T>& cont)
: _root(0)
{
	copy   (cont);
	balance();
}


// -----------------------------------------------------------------
// "~TBinaryTree" is the tree destructor.
// -----------------------------------------------------------------
template <class T> 
TBinaryTree<T>::~TBinaryTree()
{
	removeAll();
}

// -----------------------------------------------------------------
template <class T> 
TContainer<T>* TBinaryTree<T>::newInstance () const
{
	return NEW TBinaryTree<T> ();
}


// -----------------------------------------------------------------
// "=" assignment operator copies the specified tree into this tree.
// -----------------------------------------------------------------
template <class T>
TBinaryTree<T>& TBinaryTree<T>::operator=(const TBinaryTree<T>& tree)
{
	if (&tree != this)
	{
		removeAll();
		copy     (tree);
		balance  ();
	}
	return *this;
}


// -----------------------------------------------------------------
// "add" adds a new item to the tree.
// -----------------------------------------------------------------
template <class T>
bool TBinaryTree<T>::add(const T& rObj)
{
	TBinaryTreeNode<T> *newnode = NEW TBinaryTreeNode<T>(rObj);
	if (!newnode)
		return false;

	if (!_root)                                // Tree is empty.  Add at root.
		_root = newnode;

	else                                       // Tree is not empty.
	{
		TBinaryTreeNode<T> *parent = _root;
		TBinaryTreeNode<T> *rover;
		rover = (rObj < _root->_data) ? _root->_left : _root->_right;

		while (rover)                            // Search for vacant slot.
		{
			parent = rover;
			rover  = (rObj < rover->_data) ? rover->_left : rover->_right;
		}

		if (rObj < parent->_data) parent->_left  = newnode;  // Add new node.
		else                      parent->_right = newnode;
	}
	this->_size++;
	return true;
}


// -----------------------------------------------------------------
// "remove" removes the specified item from the tree.
// -----------------------------------------------------------------
template <class T> 
bool TBinaryTree<T>::remove(const T& rObj)
{
	if (!_root)
		return false;                    // Exit if empty tree.

	TBinaryTreeNode<T> *rover   = _root;       // Init for search.
	TBinaryTreeNode<T> *parent  = 0;
	bool                  done    = false;
	bool                  success = false;

	while (rover && !done)                       // Search for item.
	{
		if (rObj != rover->_data)                  // Advance to next node.
		{
			parent = rover;
			rover  = (rObj < rover->_data) ? rover->_left : rover->_right;
		}

		else                                       // Item was found.
		{
			success = removeNode(parent, rover);
			done    = true;
		}
	}
	return success;
}


// -----------------------------------------------------------------
// "remove" removes the item pointed to by the specified iterator.
// -----------------------------------------------------------------
template <class T> 
bool TBinaryTree<T>::remove(const TIterator<T>& iter)
{
	return remove(iter.current());
}


// -----------------------------------------------------------------
// "removeAt" removes the item at the specified tree index.
// -----------------------------------------------------------------
template <class T> 
bool TBinaryTree<T>::removeAt(int32 idx)
{
	if (!_root)
		return false;
	TStack<TBinaryTreeNode<T>*> stack;
	TBinaryTreeNode<T>* node = _root;
	while (node->_left)
	{
		stack.push(node);
		node = node->_left;
	}

	int32 ix = 0;
	while (node && ix < idx)
	{
		if (node->_right)
		{
			stack.push(node);
			node = node->_right;
			while (node->_left)
			{
				stack.push(node);
				node = node->_left;
			}
		}
		else
		{
			TBinaryTreeNode<T> *temp;
			do
			{
				temp = node;
				node = (stack.size() == 0) ? 0 : stack.pop();
			} while (node && node->_right == temp);
		}
		ix++;
	}
	TBinaryTreeNode<T> *par = (stack.size() > 0) ? stack.pop() : 0;
	return (ix == idx) ? removeNode(par, node) : false;
}


// -----------------------------------------------------------------
// "removeAll" removes all items from this tree.
// -----------------------------------------------------------------
template <class T> 
void TBinaryTree<T>::removeAll()
{
	if (_root)
	{
		killNode(_root);
		delete _root;
		_root = 0;
		this->_size = 0;
	}
}


// -----------------------------------------------------------------
// "root" returns the item at the root of this tree.
// -----------------------------------------------------------------
template <class T> 
const T& TBinaryTree<T>::root() const
{
	return (_root) ? _root->_data : this->error ();
}


// -----------------------------------------------------------------
// "balance" balances the current contents of the tree.
// -----------------------------------------------------------------
template <class T> 
void TBinaryTree<T>::balance()
{
	TQueue<T> que;
	TBinaryTreeIterator<T> iter(*this);
	while (!iter.done())
		que.push(iter.next());
	removeAll();
	balanceHalf(que, 0, que.size() - 1);
}


// -----------------------------------------------------------------
// "lookup" returns the item in the tree equal to the specified item.
// -----------------------------------------------------------------
template <class T>  
T& TBinaryTree<T>::lookup(const T& rObj) const
{
	if (!_root)
		return this->error ();

	TBinaryTreeNode<T> *rover = _root;
	TBinaryTreeNode<T> *temp  = 0;

	while (rover && !temp)
	{
		if (rObj == rover->_data)
			temp  = rover;
		else
			rover = (rObj < rover->_data) ? rover->_left : rover->_right;
	}
	return (temp) ? temp->_data : this->error ();
}


// -----------------------------------------------------------------
// "contains" checks if the specified item is in this tree.
// -----------------------------------------------------------------
template <class T>
bool TBinaryTree<T>::contains(const T& rObj) const
{
	if (!_root) return 0;

	TBinaryTreeNode<T> *rover = _root;
	bool found = false;

	while (rover && !found)
	{
		if (rObj == rover->_data)
			found = true;
		else
			rover = (rObj < rover->_data) ? rover->_left : rover->_right;
	}
	return found;
}


// -----------------------------------------------------------------
// "occurrences" counts the occurrences of the specified item in this tree.
// -----------------------------------------------------------------
template <class T> 
int32 TBinaryTree<T>::occurrences(const T& rObj) const
{
	int32 occur = 0;
	TBinaryTreeIterator<T> iter(*this);
	while (!iter.done())
		if (iter.next() == rObj)
			occur++;
	return occur;
}


// -----------------------------------------------------------------
// "newIterator" creates and returns a new tree iterator.
// -----------------------------------------------------------------
template <class T> 
TIterator<T>* TBinaryTree<T>::newIterator() const
{
	return NEW TBinaryTreeIterator<T>(*this);
}


// -----------------------------------------------------------------
// "removeNode" removes the specified node from the tree.
// -----------------------------------------------------------------
template <class T>
bool TBinaryTree<T>::removeNode(TBinaryTreeNode<T>* parent,
								  TBinaryTreeNode<T>* node)
{
	TBinaryTreeNode<T> *temp1 = node;

	if (node->_right == 0)
		node = node->_left;

	else if (node->_right->_left == 0)
	{
		node        = node->_right;
		node->_left = temp1->_left;
	}

	else
	{
		TBinaryTreeNode<T> *temp2 = node->_right;
		while (temp2->_left->_left)
			temp2 = temp2->_left;
		node         = temp2->_left;
		temp2->_left = node->_right;
		node->_left  = temp1->_left;
		node->_right = temp1->_right;
	}

	if (!parent)
		_root = node;
	else
	{
		if (temp1->_data < parent->_data)
			parent->_left  = node;
		else
			parent->_right = node;
	}

	delete temp1;
	this->_size--;
	return true;
}


// -----------------------------------------------------------------
// "balanceHalf" is called recursively for tree balancing.
// -----------------------------------------------------------------
template <class T>
void TBinaryTree<T>::balanceHalf(const TQueue<T>& que, int32 low, int32 high)
{
	if (low <= high)
	{
		int32 mid = (low + high) / 2;
		add(que[mid]);
		balanceHalf(que, mid + 1, high);
		balanceHalf(que, low, mid-1);
	}
}


// -----------------------------------------------------------------
// "killNode" is recursively called to destroy branches of a node.
// -----------------------------------------------------------------
template <class T> 
void TBinaryTree<T>::killNode(TBinaryTreeNode<T>* sub)
{
	if (sub->_left)
	{
		killNode(sub->_left);
		delete sub->_left;
		sub->_left = 0;
	}

	if (sub->_right)
	{
		killNode(sub->_right);
		delete sub->_right;
		sub->_right = 0;
	}
}


// -----------------------------------------------------------------
// "TBinaryTreeIterator" is the iterator constructor.
// -----------------------------------------------------------------
template <class T>
TBinaryTreeIterator<T>::TBinaryTreeIterator(const TBinaryTree<T>& tr)
: TIterator<T>(tr), _node(tr._root)
{
	if (_node)
	{
		while (_node->_left)
		{
			_stack.push(_node);
			_node = _node->_left;
		}
	}
}


// -----------------------------------------------------------------
// "tree" returns a reference to the tree being iterated.
// -----------------------------------------------------------------
template <class T>
const TBinaryTree<T>& TBinaryTreeIterator<T>::tree() const
{
	return (const TBinaryTree<T>&) this->_container;
}


// -----------------------------------------------------------------
// "done" returns true if the iterator can proceed no further.
// -----------------------------------------------------------------
template <class T> 
bool TBinaryTreeIterator<T>::done() const
{
	return (!_node) ? true : false;
}


// -----------------------------------------------------------------
// "next" returns the current item and advances the iterator.
// -----------------------------------------------------------------
template <class T> 
T& TBinaryTreeIterator<T>::next()
{
	if (!_node)
		return tree().error ();               // Iteration is over.

	T& retValue = _node->_data;               // Save item reference.

	if (_node->_right)                              // If there is a right
	{                                               // branch, advance to it
		_stack.push(_node);                           // and descend all the way
		_node = _node->_right;                        // down it's left side.
		while (_node->_left)
		{
			_stack.push(_node);
			_node = _node->_left;
		}
	}

	else                                            // Otherwise, back up the
	{                                               // tree until we are back
		TBinaryTreeNode<T>* temp;                   // at the top or until we
		do                                            // are no longer a right
		{                                             // branch.
			temp  = _node;
			_node = (_stack.size() == 0) ? 0 : _stack.pop();
		} while (_node && _node->_right == temp);
	}
	return retValue;
}


// -----------------------------------------------------------------
// "previous" returns the current item and advances the iterator.
// -----------------------------------------------------------------
template <class T> 
T& TBinaryTreeIterator<T>::previous()
{
	if (!_node)
		return tree().error ();               // Iteration is over.

	T& retValue = _node->_data;               // Save item reference.

	if (_node->_left)                               // If there is a left
	{                                               // branch, advance to it
		_stack.push(_node);                           // and descend all the way
		_node = _node->_left;                         // down it's right side.
		while (_node->_right)
		{
			_stack.push(_node);
			_node = _node->_right;
		}
	}

	else                                            // Otherwise, back up the
	{                                               // tree until we are back
		TBinaryTreeNode<T>* temp;                   // at the top or until we
		do                                            // are no longer a left
		{                                             // branch.
			temp  = _node;
			_node = (_stack.size() == 0) ? 0 : _stack.pop();
		} while (_node && _node->_left == temp);
	}
	return retValue;
}


// -----------------------------------------------------------------
// "current" returns the curren item.
// -----------------------------------------------------------------
template <class T> 
T& TBinaryTreeIterator<T>::current() const
{
	return (_node) ? _node->_data : tree().error ();
}


// -----------------------------------------------------------------
// "first" moves the iterator to the first item.
// -----------------------------------------------------------------
template <class T> 
void TBinaryTreeIterator<T>::first()
{
	_stack.removeAll();
	_node = tree()._root;
	if (_node)
	{
		while (_node->_left)
		{
			_stack.push(_node);
			_node = _node->_left;
		}
	}
}


// -----------------------------------------------------------------
// "last" moves the iterator to the last item.
// -----------------------------------------------------------------
template <class T> 
void TBinaryTreeIterator<T>::last()
{
	_stack.removeAll();
	_node = tree()._root;
	if (_node)
	{
		while (_node->_right)
		{
			_stack.push(_node);
			_node = _node->_right;
		}
	}
}

/// \endcond

}
#endif
