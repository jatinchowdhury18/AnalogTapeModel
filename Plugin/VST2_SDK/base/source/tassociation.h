//------------------------------------------------------------------------ 
// Project     : SDK Base 
// Version     : 1.0
//
// Category    : Helpers / Template Container
// Filename    : base/source/tassociation.h
// Created by  : Steinberg, 2009
// Description : Association class template
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

#ifndef __cmtassoc__
#define __cmtassoc__

#include "base/source/tarray.h"

namespace Steinberg {

//------------------------------------------------------------------------
/*! @class TAssociation
 \brief Association template definition.
 
 \ingroup baseContainer
 **/
//------------------------------------------------------------------------
template <class T, class O> class TAssociation 
{
public:
// -----------------------------------------------------------------
	TAssociation() {}									///< Default constructor.
	TAssociation(const T&, const O&);					///< Construct w/ key&object.
	TAssociation(const T&);								///< Construct with key.
	TAssociation(const TAssociation<T,O>&);				///< Copy constructor.

	TAssociation<T,O>& operator=(const TAssociation<T,O>&); ///< Assignment.

	void     set   (const T&, const O&);				///< Set new key and object.
	T&       key   ();									///< Return key value.
	const T& key   () const {return _key;}				///< Return key value.
	void     key   (const T&);							///< Set new key value.
	O&       object();									///< Return object value.
	const O& object()const {return _object;}			///< Return object value.
	void     object(const O&);							///< Set new object value.

	bool operator==(const TAssociation<T,O>&) const;	///< Equality check.
	bool operator!=(const TAssociation<T,O>&) const;	///< In-equality check.
	bool operator< (const TAssociation<T,O>&) const;	///< Less than check.
	bool operator> (const TAssociation<T,O>&) const;	///< Greater than check.
	bool operator<=(const TAssociation<T,O>&) const;	///< Less than or equal.
	bool operator>=(const TAssociation<T,O>&) const;	///< Greater or equal.
// -----------------------------------------------------------------

private:
	T _key;												///< Key value.
	O _object;											///< Object value.
};


//------------------------------------------------------------------------
/** @class TAssociationArray
 Association Array template definition.
 
 A TArray containing TAssociationArray 's.
 
 @ingroup baseContainer
 **/
//------------------------------------------------------------------------
template <class K, class O>
class TAssociationArray : private TArray <TAssociation<K,O> >
{
public:
// -----------------------------------------------------------------
	TAssociationArray () {}
	
	using TArray<TAssociation<K,O> >::total;
	using TArray<TAssociation<K,O> >::isEmpty;
	using TArray<TAssociation<K,O> >::removeAll;
	using TArray<TAssociation<K,O> >::removeAt;
	using TArray<TAssociation<K,O> >::delta;
	using TArray<TAssociation<K,O> >::resize;
	using TArray<TAssociation<K,O> >::error;
	using TArray<TAssociation<K,O> >::newIterator;
	using TArray<TAssociation<K,O> >::at;

	TAssociationArray<K,O>& operator=(const TAssociationArray<K,O>& t) {TArray<TAssociation<K,O> >::operator= (t); return *this; }

	bool addKeyAndObject (const K& key, const O& object)
	{
		return this->add (TAssociation<K,O> (key, object));
	}

	bool insertKeyAndObject (int32 atIndex, const K& key, const O& object)
	{
		return this->insertAt (atIndex, TAssociation<K,O> (key, object));
	}

	bool removeKeyAndObject (const K& key)
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).key () == key)
				return this->removeAt (i);
		return false;
	}

	bool setKeyAndObject (const K& key, const O& object)
	{
		for (int32 i = 0; i < total (); i++)
		{
			if (this->at(i).key () == key)
			{
				this->at(i).object () = object;
				return true;
			}			
		}
		return this->add (TAssociation<K,O> (key, object));
	}

	bool containsKeyAndObject (const K& key, const O& object)
	{
		return this->contains (TAssociation<K,O> (key, object));
	}

	O lookupObject (const K& key)const
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).key () == key)
				return this->at(i).object ();
		return 0;
	}

	K lookupKey (const O& object)const
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).object () == object)
				return this->at(i).key ();
		return 0;
	}
	
	int32 getObjectIndex (const O& object)const
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).object () == object)
				return i;
		return -1;
	}

	int32 getKeyIndex (const K& key)const
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).key () == key)
				return i;
		return -1;
	}	
	
	bool containsKey (const K& key)const
	{
		for (int32 i = 0; i < total (); i++)
			if (this->at(i).key () == key)
				return true;
		return false;	
	}

	K getKey (int32 index) const
	{
		return this->at(index).key ();
	}
	
	O getObject (int32 index) const
	{
		return this->at(index).object ();
	}

	void setKey (int32 index, const K& k)
	{
		if (index >= 0 && index < total ())
			this->at(index).key () = k;
	}
	
	void setObject (int32 index, const O& o)
	{
		if (index >= 0 && index < total ())
			this->at(index).object () = o;
	}
};


/*! "TAssociation" constructs a new association with the specified key and object. */
template <class T, class O>
TAssociation<T,O>::TAssociation(const T& k, const O& o)
: _key (k)
, _object (o)
{
}


/*! "TAssociation" constructs a new association with the specified key. */
template <class T, class O>
TAssociation<T,O>::TAssociation(const T& k)
: _key (k)
{
}


/*! "TAssociation" is the association copy constructor. */
template <class T, class O>
TAssociation<T,O>::TAssociation(const TAssociation<T,O>& A)
: _key (A._key)
, _object (A._object)
{
}


/*! "=" assignment operator copies the specified association into this association. */
template <class T, class O> TAssociation<T,O>&
TAssociation<T,O>::operator=(const TAssociation<T,O>& A)
{
	if (&A != this)
	{
		_key    = A._key;
		_object = A._object;
	}
	return *this;
}


/*! "set" sets a new key and object value. */
template <class T, class O>
void TAssociation<T,O>::set(const T& k, const O& o)
{
	_key    = k;
	_object = o;
}


/*! "key" returns the key value. */
template <class T, class O> T& TAssociation<T,O>::key()
{
	return _key;
}


/*! "key" sets a new key value. */
// -----------------------------------------------------------------
template <class T, class O> void TAssociation<T,O>::key(const T& k)
{
	_key = k;
}


/*! "object" returns the object value. */
template <class T, class O> O& TAssociation<T,O>::object()
{
	return _object;
}


/*! "object" sets a new object value. */
template <class T, class O> void TAssociation<T,O>::object(const O& o)
{
	_object = o;
}


/*! "==" checks to see if two associations are equal. */
template <class T, class O>
bool TAssociation<T,O>::operator==(const TAssociation<T,O>& A) const
{
	return (_key == A._key);
}


/*! "!=" checks to see if two associations are not equal. */
template <class T, class O>
bool TAssociation<T,O>::operator!=(const TAssociation<T,O>& A) const
{
	return (_key != A._key);
}


/*! "<" checks if this association is less than the specified association. */
template <class T, class O>
bool TAssociation<T,O>::operator<(const TAssociation<T,O>& A) const
{
	return (_key < A._key);
}


/*! ">" checks if this association is greater than the specified association. */
template <class T, class O>
bool TAssociation<T,O>::operator>(const TAssociation<T,O>& A) const
{
	return (_key > A._key);
}


/*! "<=" checks if this association is less than or equal to the specified association. */
template <class T, class O>
bool TAssociation<T,O>::operator<=(const TAssociation<T,O>& A) const
{
	return (_key <= A._key);
}


/*! ">=" checks if this association is greater than or equal to the specified association. */
template <class T, class O>
bool TAssociation<T,O>::operator>=(const TAssociation<T,O>& A) const
{
	return (_key >= A._key);
}

}

#endif
