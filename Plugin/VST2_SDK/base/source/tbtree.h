//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/tbtree.h
// Created by  : Steinberg, 05/2006
// Description : B-Tree class template
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

//----------------------------------------------------------------------------------
/** @file base/source/tbtree.h
	Template definition for a BTree. 
	@see Steinberg::TBTree */
//----------------------------------------------------------------------------------
#ifndef __tbtree__
#define __tbtree__

#include "base/source/tcontainer.h"

namespace Steinberg {

template <class T> class TBTreeNode; // Tree node class stub.
template <class T> class TBTreeIterator; // Tree iterator class stub.

//------------------------------------------------------------------------
/** BTree template definition.
@ingroup baseContainer
 
Template definition for a BTree 
*/
//------------------------------------------------------------------------
template <class T> class TBTree : public TContainer<T>
{
public:
// -----------------------------------------------------------------
	TBTree (int32 = 3); ///< Default tree constructor.
	TBTree (const TBTree<T>&); ///< Tree copy constructor.
	TBTree (const TContainer<T>&); ///< Construct from container.
	~TBTree (); ///< Tree destructor.

	TContainer<T>* newInstance () const;

	TBTree<T>& operator=(const TBTree<T>&); ///< Assignment operator.

	int32 order () const; ///< Return tree order.
	int32 height () const; ///< Return tree height.

	virtual bool add (const T&); ///< Add item to tree.
	virtual bool remove (const T&); ///< Remove item from tree.
	virtual bool remove (const TIterator<T>&); ///< Remove iterator item.
	virtual bool removeAt (int32); ///< Remove at index.
	virtual void removeAll (); ///< Remove all items.

	virtual T& lookup (const T&) const; ///< Find equal item in tree.
	bool lookup (const T&, TBTreeIterator<T>&);
	bool lookupLowerEqual (const T&, TBTreeIterator<T>&);
	virtual bool contains (const T&) const; ///< See if tree contains equal.
	virtual int32 occurrences (const T&) const; ///< Count occurrences of equal.

	TIterator<T>* lookupIterator (const T&) const;
	TIterator<T>* newIterator () const; ///< Create tree iterator.
// -----------------------------------------------------------------

private:
	TBTreeNode<T>* nodeSearch (const T&) const; ///< Search for insertion node.
	TBTreeNode<T>* lookupNode (const T&) const; ///< Get node where item is.
	TBTreeNode<T>* lookupNodeLowerEqual (const T&) const; ///< Get node where item is.

	bool remove (TBTreeNode<T>*, int32); /// Remove at index in node.

	static void removeNodes (TBTreeNode<T>*); ///< Remove node children.
	static int32 minKeys (int32); ///< Get minimum keys allowed.

	int32 _order; ///< Tree order.
	TBTreeNode<T> *_root; ///< Root tree node.

	friend class TBTreeIterator<T>; ///< Iterator class can access.
};

// -----------------------------------------------------------------
// Tree node definition.
// -----------------------------------------------------------------
template <class T> class TBTreeNode
{
private:
	TBTreeNode (TBTreeNode<T>*, int32); ///< Node constructor.
	~TBTreeNode (); ///< Node destructor.

	int32 shouldGo (const T&); ///< Where should item insert.
	int32 index (const T&); ///< Index where item is located.
	int32 index (TBTreeNode<T>*); ///< Index where child is located.
	bool addAt (int32, const T&, TBTreeNode<T>*, int32); ///< Add item at index.
	bool removeAt (int32, int32); ///< Remove item at index.
	void clear (int32); ///< Clear arrays.

	TBTreeNode<T>* split (int32); ///< Split the node.

	int32 _total; ///< Number of items in node.
	TBTreeNode<T> *_parent; ///< Parent node.
	T *_data; ///< (order ) data items.
	TBTreeNode<T> **_children; ///< (order+1) child nodes.

	friend class TBTree<T>; ///< Tree class can access.
	friend class TBTreeIterator<T>; ///< Iterator class can access.
};

//------------------------------------------------------------------------
/** Iterator for the BTree template.
@ingroup baseContainer
 
Iterator for a BTree 
*/
//------------------------------------------------------------------------
template <class T> 
class TBTreeIterator : public TIterator<T>
{
public:
// -----------------------------------------------------------------
	TBTreeIterator (const TBTree<T>&); ///< Iterator constructor.

	virtual bool done () const; ///< Check if at end.
	virtual T& next (); ///< Return and advance.
	virtual T& previous (); ///< Return and backup.
	virtual T& current () const; ///< Get current item.
	virtual void first (); ///< Move to first item.
	virtual void last (); ///< Move to last item.

	const TBTree<T>& tree () const; ///< Return tree reference.

	friend class TBTree<T>; ///< Tree class can access.

// -----------------------------------------------------------------
protected:
	void setCurrent (TBTreeNode<T> *node, int32 index2) { _node = node; _index = index2; };

private:
	TBTreeNode<T> *_node; ///< Current tree node.
	int32 _index; ///< Current node item.
};

// -----------------------------------------------------------------
// -----------------------------------------------------------------
// -----------------------------------------------------------------

// -----------------------------------------------------------------
// "TBTree" is the default tree constructor.
// -----------------------------------------------------------------
template <class T> TBTree<T>::TBTree (int32 ordr)
: _order ((ordr >= 3) ? ordr : 3)
, _root (0)
{}

// -----------------------------------------------------------------
// "TBTree" is the tree copy constructor.
// -----------------------------------------------------------------
template <class T>
TBTree<T>::TBTree (const TBTree<T>& tree)
: TContainer<T> (tree)
, _order (tree._order)
, _root (0)
{
	copy (tree);
}

// -----------------------------------------------------------------
// "TBTree" constructs a tree from the specified container.
// -----------------------------------------------------------------
template <class T>
TBTree<T>::TBTree (const TContainer<T>& cont)
: _order (3)
, _root (0)
{
	copy (cont);
}

// -----------------------------------------------------------------
// "~TBTree" is the tree destructor.
// -----------------------------------------------------------------
template <class T> TBTree<T>::~TBTree ()
{
	removeAll ();
}

// -----------------------------------------------------------------
template <class T> TContainer<T>* TBTree<T>::newInstance () const
{
	return NEW TBTree<T> ();
}

// -----------------------------------------------------------------
// "=" assignment operator copies the specified tree into this tree.
// -----------------------------------------------------------------
template <class T>
TBTree<T>& TBTree<T>::operator= (const TBTree<T>& tree)
{
	if (&tree != this)
	{
		removeAll ();
		_order = tree._order;
		copy (tree);
	}
	return *this;
}

// -----------------------------------------------------------------
// "order" returns the tree order.
// -----------------------------------------------------------------
template <class T> int32 TBTree<T>::order () const
{
	return _order;
}

// -----------------------------------------------------------------
// "height" returns the current tree height.
// -----------------------------------------------------------------
template <class T> int32 TBTree<T>::height () const
{
	TBTreeNode<T> *rover = _root;
	int32 ht = 0;
	while (rover)
	{
		ht++;
		rover = rover->_children[0];
	}
	return ht;
}

// -----------------------------------------------------------------
// "add" adds a new item to this tree.
// -----------------------------------------------------------------
template <class T> bool TBTree<T>::add (const T& rObj)
{
	T data = rObj; // Initialize data item.
	TBTreeNode<T> *child = 0; // Initialize child.
	TBTreeNode<T> *rover = nodeSearch (rObj); // Find node to insert into.
	bool done = false; // Loop flag.

	while (rover && !done) // Loop.
	{
		int32 idx = rover->shouldGo (data); // Get position for new item.
		rover->addAt (idx, data, child, 1); // Add new data and child to node.
		if (rover->_total <= _order-1) // Data fits so exit.
			done = true;
		else
		{
			data = rover->_data[(rover->_total) / 2]; // Data doesn't fit.
			TBTreeNode<T> *newRight = rover->split (_order); // Split the node.
			if (!newRight) 
				return false; // Split unsuccessful.
			child = newRight; // Set new child right.
			rover = rover->_parent; // Move to parent.
		}
	}

	if (!done) // Not done, create a
	{ // new root.
		TBTreeNode<T> *newRoot = NEW TBTreeNode<T> (0, _order);
		newRoot->_children[0] = _root; // Old root is child of new.
		newRoot->_children[1] = child; // Stray child is also child.
		newRoot->_data [0] = data; // Data is lone root item.
		newRoot->_total = 1; // New root contains 1.

		if (_root) // Set parentage of children
		{ // if not first time in.
			child->_parent = newRoot;
			_root->_parent = newRoot;
		}
		_root = newRoot; // New root is now root.
	}
	this->_size++; // Bump size and split.
	return true;
}

// -----------------------------------------------------------------
// "remove" removes an item equal to the specified item from the tree.
// -----------------------------------------------------------------
template <class T> bool TBTree<T>::remove (const T& rObj)
{
	TBTreeNode<T> *node = lookupNode (rObj); // Find node where item is.
	if (!node)
		return false; // No item, exit.
	int32 idx = node->index (rObj); // Get index of item in node.
	if (idx == -1)
		return false; // No item, exit.
	return remove (node, idx); // Remove item.
}

// -----------------------------------------------------------------
// "remove" removes the item pointed to by the specified iterator
// from the tree.
// -----------------------------------------------------------------
template <class T> bool TBTree<T>::remove (const TIterator<T>& iter)
{
	return remove (iter.current ());
}

// -----------------------------------------------------------------
// "removeAt" removes the item at the specified index from the
// tree.
// -----------------------------------------------------------------
template <class T> bool TBTree<T>::removeAt (int32 idx)
{
	if (!_root)
		return false;
	TBTreeNode<T> *node = _root;
	int32 nodeIdx = 0;
	int32 ix = 0;
	
	while (node->_children[0]) 
		node = node->_children[0];

	while (node && ix < idx)
	{
		if (node->_children[nodeIdx+1])
		{
			node = node->_children[nodeIdx+1];
			while (node->_children[0])
				node = node->_children[0];
			nodeIdx = 0;
		}
		else if (nodeIdx < node->_total-1)
			nodeIdx++;
		else
		{
			bool done = false;
			while (!done)
			{
				if (!node->_parent)
				{
					node = 0;
					done = true;
				}
				else
				{
					int32 idx = node->_parent->index (node);
					node = node->_parent;
					if (idx < node->_total)
					{
						nodeIdx = idx;
						done = true;
					}
				}
			}
		}
		ix++;
	}
	return (ix == idx) ? remove (node, nodeIdx) : false;
}

// -----------------------------------------------------------------
// "removeAll" removes all items from the tree.
// -----------------------------------------------------------------
template <class T> 
void TBTree<T>::removeAll ()
{
	removeNodes (_root);
	_root = 0;
	this->_size = 0;
}

// -----------------------------------------------------------------
// "lookup" returns an item equal to the specified item in the tree.
// -----------------------------------------------------------------
template <class T> 
T& TBTree<T>::lookup (const T& rObj) const
{
	if (!_root)
		return this->error ();
	TBTreeNode<T> *node = lookupNode (rObj);
	if (!node)
		return this->error ();
	int32 idx = node->index (rObj);
	return (idx == -1) ? this->error () : node->_data[idx];
}

// -----------------------------------------------------------------
// "lookup" sets the iterator to the objects position if it finds it
// -----------------------------------------------------------------
template <class T> 
bool TBTree<T>::lookup (const T& rObj, TBTreeIterator<T>& iter)
{
	if (!_root)
		return false;
	TBTreeNode<T> *node = lookupNode (rObj);
	if (!node)
		return false;
	int32 idx = node->index (rObj);
	if (idx == -1)
		return false;
	iter._node = node;
	iter._index = idx;
	return true;
}

// -----------------------------------------------------------------
// "lookupIterator" return the iterator to the objects position if it finds it
// -----------------------------------------------------------------
template <class T> 
TIterator<T>* TBTree<T>::lookupIterator (const T& rObj) const
{
	if (!_root)
		return 0;
	TBTreeNode<T> *node = lookupNode (rObj);
	if (!node)
		return 0;
	int32 idx = node->index (rObj);
	if (idx == -1)
		return 0;

	TBTreeIterator<T>* iter = NEW TBTreeIterator<T> (*this);
	iter->setCurrent (node, idx);

	return iter;
}

// -----------------------------------------------------------------
// "lookupLowerEqual" sets the iterator to the objects position which 
// have a lower or equal value as request
// -----------------------------------------------------------------
template <class T> 
bool TBTree<T>::lookupLowerEqual (const T& rObj, TBTreeIterator<T>& iter)
{
	if (!_root)
		return false;
	TBTreeNode<T> *node = lookupNodeLowerEqual (rObj);
	if (!node)
		return false;

	int32 idx = node->index (rObj);

	if (idx == -1) 
	{
		int32 idxMin = 0;
		bool minFind = false;  
		int32 ii = 0;
		while (ii < node->_total && idx == -1) 
		{
			if (rObj < node->_data[ii]) 
			{
				idx = ii;
			}
			else if (rObj > node->_data[ii])
			{
				idxMin = ii;
				minFind = true;
			}
			ii++;
		}

		if (minFind) 
		{
			iter.setCurrent (node, idxMin);
		}
		else 
		{
			iter.setCurrent (node, idx);
			iter.previous ();

			if (iter.done ()) 
			{
				iter.setCurrent (node, idx);
			}
		}
	}
	else 
	{
		iter.setCurrent (node, idx);
	}

	return true;
}

// -----------------------------------------------------------------
// "contains" checks if the tree contains any items equal to the
// specified item.
// -----------------------------------------------------------------
template <class T> 
bool TBTree<T>::contains (const T& rObj) const
{
	if (!_root)
		return 0;
	TBTreeNode<T> *node = lookupNode (rObj);
	if (!node)
		return false;
	int32 idx = node->index (rObj);
	return (idx != -1) ? true : false;
}

// -----------------------------------------------------------------
// "occurrences" counts the number of items equal to the specified
// item in the tree.
// -----------------------------------------------------------------
template <class T> 
int32 TBTree<T>::occurrences (const T& rObj) const
{
	int32 occur = 0;
	TBTreeIterator<T> iter (*this);
	while (!iter.done ())
		if (rObj == iter.next ())
			occur++;
	return occur;
}

// -----------------------------------------------------------------
// "newIterator" creates and returns a tree iterator.
// -----------------------------------------------------------------
template <class T> 
TIterator<T>* TBTree<T>::newIterator () const
{
	return NEW TBTreeIterator<T> (*this);
}

// -----------------------------------------------------------------
// "nodeSearch" returns the node where the specified item should be
// inserted.
// -----------------------------------------------------------------
template <class T>
TBTreeNode<T>* TBTree<T>::nodeSearch (const T& rObj) const
{
	TBTreeNode<T> *rover = _root;
	TBTreeNode<T> *found = 0;

	while (rover && !found)
	{
		int32 idx = rover->shouldGo (rObj);
		if (rover->_children[idx])
			rover = rover->_children[idx];
		else 
			found = rover;
	}
	return found;
}

// -----------------------------------------------------------------
// "lookupNode" returns the node where the specified item is located.
// -----------------------------------------------------------------
template <class T>
TBTreeNode<T>* TBTree<T>::lookupNode (const T& rObj) const
{
	if (!_root)
		return 0;

	TBTreeNode<T> *rover = _root; // Start at root node.
	TBTreeNode<T> *ret = 0;
	while (rover && !ret)
	{
		int32 idx = rover->index (rObj); // Is item in node?
		if (idx != -1)
			ret = rover; // Yes.
		else
		{
			idx = rover->shouldGo (rObj); // No. Set node to point to
			rover = rover->_children[idx]; // child where item would be.
		}
	}
	return ret;
}

// -----------------------------------------------------------------
// "lookupNodeLowerEquals" returns the node (lower or equal) where the specified item is located.
// -----------------------------------------------------------------
template <class T>
TBTreeNode<T>* TBTree<T>::lookupNodeLowerEqual (const T& rObj) const
{
	if (!_root)
		return 0;

	TBTreeNode<T> *rover = _root; // Start at root node.
	TBTreeNode<T> *ret = 0;
	while (rover && !ret)
	{
		int32 idx = rover->index (rObj); // Is item in node?
		if (idx != -1)
			ret = rover; // Yes.
		else
		{
			idx = rover->shouldGo (rObj); // No. Set node to point to
			if (!rover->_children[idx])
			{
				ret = rover;
			}
			rover = rover->_children[idx]; // child where item would be.  
		}
	}
	return ret;
}

// -----------------------------------------------------------------
// "remove" removes the item at the specified index in the specified
// node.
// -----------------------------------------------------------------
template <class T> 
bool TBTree<T>::remove (TBTreeNode<T>* node, int32 idx)
{
	this->_size--; // Decrement size.

	if (node->_children[0]) // If node is not leaf, swap
	{ // item with item at left
		TBTreeNode<T> *rover = node->_children[idx+1]; // most side of right.
		while (rover->_children[0])
			rover = rover->_children[0];
		node->_data[idx] = rover->_data[0];
		node = rover;
		idx = 0;
	}

	node->removeAt (idx, 0); // Remove item from node.
	int32 minkeys = minKeys (_order); // Save min allowable keys.

	while (node != _root && node->_total < minkeys) // Start looping if number
	{ // of keys fell below min.
		int32 nodeIdx = node->_parent->index (node); // Save index of node in parent.
		if (nodeIdx == -1)
			return false;

		if (node->_parent->_children[nodeIdx+1]) // If node has a right sibling,
		{
			TBTreeNode<T> *sib = node->_parent->_children[nodeIdx+1];
			TBTreeNode<T> *par = node->_parent;

			// If the right sibling has keys to spare, move the left most key in
			// the right sibling up to the parent. Take the parent key parenting
			// this node and move that key into this node. Exit.
			if (sib->_total > minkeys)
			{
				node->addAt (node->_total, par->_data[nodeIdx], sib->_children[0], 1);
				par->_data[nodeIdx] = sib->_data[0];
				sib->removeAt (0, 0);
				return true;
			}

			// The right sibling has no keys to spare, so we need to combine the
			// remaining keys in this node with the parent key parenting this node
			// and the keys of the right sibling to form one node.
			node->addAt (node->_total, par->_data[nodeIdx], sib->_children[0], 1);
			for (int32 ii = 0; ii < sib->_total; ii++)
				node->addAt (node->_total, sib->_data[ii], sib->_children[ii+1], 1);
			delete sib;
			par->removeAt (nodeIdx, 1);
			node = par;
		}

		else if (node->_parent->_children[nodeIdx-1]) // If node has left sibling,
		{
			TBTreeNode<T> *sib = node->_parent->_children[nodeIdx-1];
			TBTreeNode<T> *par = node->_parent;

			// If the left sibling has keys to spare, move the right most key in
			// the left sibling up to the parent. Take the parent key parenting
			// the left sibling and move that key into this node. Exit.
			if (sib->_total > minkeys)
			{
				node->addAt (0, par->_data[nodeIdx-1], sib->_children[sib->_total], 0);
				par->_data[nodeIdx-1] = sib->_data[sib->_total-1];
				// sib->removeAt (sib->_total-1, 0);
				sib->removeAt (sib->_total-1, 1);
				return true;
			}

			// The left sibling has no keys to spare, so we need to combine the
			// keys in the left sibling with the parent key parenting the left
			// sibling and the keys of this node to form one node.
			sib->addAt (sib->_total, par->_data[nodeIdx-1], node->_children[0], 1);
			for (int32 ii = 0; ii < node->_total; ii++)
				sib->addAt (sib->_total, node->_data[ii], node->_children[ii+1], 1);
			delete node;
			par->removeAt (nodeIdx-1, 1);
			node = par;
		}
	}

	if (node->_total == 0) // If only the root node is left,
	{ // and it has no keys, then delete
		TBTreeNode<T> *temp = _root; // delete the root node and make
		_root = _root->_children[0]; // it's left most child the new
		delete temp; // root node.
	}
	if (_root && _root->_parent)
		_root->_parent = 0;
	return true;
}

// -----------------------------------------------------------------
// "removeNodes" removes all the child nodes from the specified node.
// -----------------------------------------------------------------
template <class T> 
void TBTree<T>::removeNodes (TBTreeNode<T>* pNode)
{
	if (pNode)
	{
		for (int32 ii = 0; ii < pNode->_total; ii++)
			removeNodes (pNode->_children[ii]);
		removeNodes (pNode->_children[pNode->_total]);
		delete pNode;
	}
}

// -----------------------------------------------------------------
// "minKeys" returns the minimum number of items that a non-root node
// can contain.
// -----------------------------------------------------------------
template <class T> 
int32 TBTree<T>::minKeys (int32 ordr)
{
	return (((ordr / 2) * 2) == ordr) ? (ordr / 2) - 1 : (ordr / 2);
}

// -----------------------------------------------------------------
// "TBTreeNode" is the node constructor.
// -----------------------------------------------------------------
template <class T>
TBTreeNode<T>::TBTreeNode (TBTreeNode<T>* parent, int32 order)
: _total (0)
, _parent (parent)
{
	_data = NEWVEC T[order];
	_children = NEWVEC TBTreeNode<T>*[order+1];
	if (_data && _children)
		clear (order);
}

// -----------------------------------------------------------------
// "~TBTreeNode" is the node destructor.
// -----------------------------------------------------------------
template <class T> 
TBTreeNode<T>::~TBTreeNode ()
{
	delete[] _data;
	delete[] _children;
}

// -----------------------------------------------------------------
// "shouldGo" returns the index where the specified item should
// be inserted in the data list.
// -----------------------------------------------------------------
template <class T> 
int32 TBTreeNode<T>::shouldGo (const T& rObj)
{
	if (_total == 0)
		return 0;

	if (rObj <  _data[0])
		return 0;
	if (rObj >= _data[_total-1])
		return _total;

	int32 idx = -1, ii = _total - 1;
	while (ii >= 0 && idx == -1)
		if (rObj >= _data[ii--])
			idx = ii+2;
	return idx;
}

// -----------------------------------------------------------------
// "index" returns the index of the specified item in the data list.
// -----------------------------------------------------------------
template <class T> int32 TBTreeNode<T>::index (const T& rObj)
{
	if (_total == 0)
		return -1;
	
	int32 idx = -1, ii = 0;
	while (ii < _total && idx == -1)
		if (rObj == _data[ii++])
			idx = ii-1;
	
	return idx;
}

// -----------------------------------------------------------------
// "index" returns the index of the specified node in the child list.
// -----------------------------------------------------------------
template <class T> int32 TBTreeNode<T>::index (TBTreeNode<T>* pNode)
{
	if (_total == 0 || !pNode)
		return -1;
	int32 idx = -1, ii = 0;
	while (ii <= _total && idx == -1)
		if (pNode == _children[ii++])
			idx = ii-1;
	return idx;
}

// -----------------------------------------------------------------
// "addAt" adds the specified item/child pair at the specified index.
// -----------------------------------------------------------------
template <class T>
bool TBTreeNode<T>::addAt (int32 idx, const T& rObj, TBTreeNode<T>* pNode, int32 offset)
{
	if (offset == 0)
		_children[_total+1] = _children[_total];
	
	for (int32 ii = _total; ii > idx; ii--) // Slide other stuff to make room
	{
		_data [ii ] = _data [ii-1];
		_children[ii+offset] = _children[ii+offset-1];
	}

	_data [idx] = rObj; // Insert item and child.
	_children [idx+offset] = pNode;
	_total++;
	if (pNode)
		pNode->_parent = this;
	return true;
}

// -----------------------------------------------------------------
// "removeAt" removes the item/child pairs at the specified index.
// -----------------------------------------------------------------
template <class T> bool TBTreeNode<T>::removeAt (int32 idx, int32 offset)
{
	if (idx < 0 || idx >= _total)
		return false;

	for (int32 ii = idx; ii < _total-1; ii++)
	{
		_data[ii] = _data[ii+1];
		if (offset == 1)
			_children[ii+1] = _children[ii+2];
		else
			_children[ii] = _children[ii+1];
	}
	if (offset == 0)
		_children[_total-1] = _children[_total];
	
	_children[_total ] = 0;
	_total--;
	return true;
}

// -----------------------------------------------------------------
// "clear" nulls out all the child pointers in the node.
// -----------------------------------------------------------------
template <class T> void TBTreeNode<T>::clear (int32 order)
{
	for (int32 ii = 0; ii <= order; ii++)
		_children[ii] = 0;
}

// -----------------------------------------------------------------
// "split" splits the node returning the new right node.
// -----------------------------------------------------------------
template <class T> TBTreeNode<T>* TBTreeNode<T>::split (int32 ordr)
{
	TBTreeNode<T> *newRight = NEW TBTreeNode<T> (_parent, ordr);
	if (!newRight)
		return 0;

	int32 ix = 0, midIdx = _total / 2;
	for (int32 ii = midIdx+1; ii <= _total; ii++, ix++)
	{
		if (ii != _total)
		{
			newRight->_data[ix] = _data[ii];
			newRight->_total++;
		}
		newRight->_children[ix] = _children[ii];
		_children[ii] = 0;
		if (newRight->_children[ix])
			newRight->_children[ix]->_parent = newRight;
	}
	_total = midIdx;
	return newRight;
}

// -----------------------------------------------------------------
// "TBTreeIterator" is the iterator constructor.
// -----------------------------------------------------------------
template <class T>
TBTreeIterator<T>::TBTreeIterator (const TBTree<T> &Tr)
: TIterator<T> (Tr)
, _node (Tr._root)
, _index (0)
{
	if (_node) // Descend all the way down left.
		while (_node->_children[0])
			_node = _node->_children[0];
}

// -----------------------------------------------------------------
// "tree" returns a reference to the tree being iterated.
// -----------------------------------------------------------------
template <class T> 
const TBTree<T>& TBTreeIterator<T>::tree () const
{
	return (const TBTree<T>&) this->_container;
}

// -----------------------------------------------------------------
// "done" checks if the iterator is at the end of the tree.
// -----------------------------------------------------------------
template <class T> 
bool TBTreeIterator<T>::done () const
{
	return (!_node) ? true : false;
}

// -----------------------------------------------------------------
// "next" returns the current item and advances the iterator.
// -----------------------------------------------------------------
template <class T> 
T& TBTreeIterator<T>::next ()
{
	if (!_node)
		return tree ().error ();

	T& retValue = current (); // Save current item.

	if (_node->_children[_index+1]) // Traverse all the way down
	{ // the left part of the next
		_node = _node->_children[_index+1]; // child branch.
		while (_node->_children[0])
			_node = _node->_children[0];
		_index = 0;
		return retValue;
	}

	if (_index < _node->_total-1) // No child branches, but there
	{ // are still items in this
		_index++; // node so bump the index and
		return retValue; // exit.
	}

	bool done = false; // Need to back up the tree.
	while (!done)
	{
		if (!_node->_parent) // If node has no parent, we
		{ // are done iterating.
			_node = 0;
			done = true;
		}

		else // Node has parent.
		{
			int32 idx = _node->_parent->index (_node); // What branch were we just in.
			if (idx == -1) // Error! - shouldn't happen.
			{
				_node = 0;
				done = true;
			}
			else // Got the branch.
			{
				_node = _node->_parent; // Move up to parent.
				if (idx < _node->_total) // If not end of data list,
				{ // bump index and exit.
					_index = idx;
					done = true;
				}
			}
		}
	}
	return retValue; // Return the item.
}

// -----------------------------------------------------------------
// "previous" backs the iterator up one item and returns that item.
// -----------------------------------------------------------------
template <class T> 
T& TBTreeIterator<T>::previous ()
{
	if (!_node)
		return tree ().error ();

	T& retValue = current (); // Save current item.

	if (_node->_children[_index]) // Traverse all the way down
	{ // the right part of the
		_node = _node->_children[_index]; // previous child branch.
		while (_node->_total && _node->_children[_node->_total-1])
			_node = _node->_children[_node->_total];
		_index = _node->_total-1;
		return retValue;
	}

	if (_index > 0) // No child branches, but there
	{ // are still items in this
		_index--; // node so decrement the index
		return retValue; // and exit.
	}

	bool done = false; // Need to back up the tree.
	while (!done)
	{
		if (!_node->_parent) // If node has no parent, we
		{ // are done iterating.
			_node = 0;
			done = true;
		}

		else // Node has parent.
		{
			int32 idx = _node->_parent->index (_node); // What brach were we just in?
			if (idx == -1) // Error! - shouldn't happen.
			{
				_node = 0;
				done = true;
			}
			else // Got the branch.
			{
				_node = _node->_parent; // Move up to parent.
				if (idx > 0) // If not at beginning,
				{ // decrement index and exit.
					_index = idx - 1;
					done = true;
				}
			}
		}
	}
	return retValue; // Return the item.
}

// -----------------------------------------------------------------
// "current" returns the current item.
// -----------------------------------------------------------------
template <class T>
T& TBTreeIterator<T>::current () const
{
	return (_node) ? _node->_data[_index] : tree ().error ();
}

// -----------------------------------------------------------------
// "first" moves the iterator to the first item.
// -----------------------------------------------------------------
template <class T> 
void TBTreeIterator<T>::first ()
{
	_node = tree ()._root;
	_index = 0;

	if (_node)
		while (_node->_children[0])
			_node = _node->_children[0];
}

// -----------------------------------------------------------------
// "last" moves the iterator to the last item.
// -----------------------------------------------------------------
template <class T> 
void TBTreeIterator<T>::last ()
{
	_node = tree ()._root;
	if (_node)
	{
		while (_node->_children[_node->_total])
			_node = _node->_children[_node->_total];
		_index = _node->_total - 1;
	}
}

}

#endif
