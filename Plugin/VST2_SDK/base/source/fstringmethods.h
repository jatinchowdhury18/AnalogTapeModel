//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fstringmethods.h
// Created by  : Steinberg, 2012
// Description : String Utility Functions
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
#pragma once

#include "base/source/fstring.h"

#include "base/source/tcontainer.h"
#include "base/source/basefwd.h"
#include "pluginterfaces/base/ftypes.h"

namespace Steinberg {
namespace StringMethods {

namespace Detail {
template <typename Structure>
inline void doSplit (const ConstString &string, const ConstString &separatorString, Structure &result)
{
	int32 index = string.findFirst (separatorString);
	if (index > 0)
	{
		String tmp;
		string.extract (tmp, 0, index);
		result.add (tmp);
		index += separatorString.length ();
		int32 index2;
		while ((index2 = string.findNext (index, separatorString)) > 0)
		{
			string.extract (tmp, index, index2 - index);
			result.add (tmp);
			index = index2 + separatorString.length ();
		}
		if (string.extract (tmp, index))
		{
			if (!tmp.isEmpty ())
				result.add (tmp);
		}
	}
}
}	// Detail


//-----------------------------------------------------------------------------
///! parse a version string in the form of 'Version 3.7.8'
//-----------------------------------------------------------------------------
inline bool parseVersionString (const ConstString& string, int32& major, int32& sub, int32& release)
{
	bool result = false;
	int32 index1 = string.findFirst ('.');
	if (index1 > 0)
	{
		String tmp;
		string.extract (tmp, 0, index1);
		major = tmp.getNumber ();
		index1++;
		int32 index2 = string.findNext (index1, '.');
		if (index2 == -1)
		{
			string.extract (tmp, index1);
			if (!tmp.isEmpty () && tmp.scanInt32 (sub, 0, false))
			{
				result = true;
			}
		}
		else if (index2 - index1 > 0)
		{
			string.extract (tmp, index1, index2 - index1);
			if (tmp.isDigit (0))
			{
				sub = tmp.getNumber ();
				index2++;
				int32 index3 = string.findNext (index2, '.');
				if (index3 - index2 > 0)
				{
					string.extract (tmp, index2, index3 - index2);
					if (tmp.isDigit (0))
					{
						release = tmp.getNumber ();
						result = true;
					}
				}
				else if (index3 == -1)
				{
					if (string.extract (tmp, index2))
					{
						if (tmp.isDigit (0))
						{
							release = tmp.getNumber ();
							result = true;
						}
					}
				}
			}
		}
	}
	return result;
}

//-----------------------------------------------------------------------------
///! split a string into multiple substrings separated by a separator string
//-----------------------------------------------------------------------------
inline int32 split (const ConstString& string, const ConstString& separatorString, TContainer<String>& result)
{
	result.removeAll ();
	Detail::doSplit (string, separatorString, result);
	return result.total ();
}

//-----------------------------------------------------------------------------
///! split a string into multiple substrings separated by a separator string (template version)
//-----------------------------------------------------------------------------
template <typename Structure>
inline int32 tsplit (const ConstString& string, const ConstString& separatorString, Structure& result)
{
	result.clear ();
	Detail::doSplit (string, separatorString, result);
	return result.size ();
}

} // StringMethods
} // Steinberg
