/*
 *  mdaParameter.h
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/15/08.
 *
 *  mda VST Plug-ins
 *
 *  Copyright (c) 2008 Paul Kellett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __mdaParameter__
#define __mdaParameter__

#include "public.sdk/source/vst/vstparameters.h"
#include "pluginterfaces/base/ustring.h"
#include <list>
#include <algorithm>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class BaseParameter : public Parameter
{
public:
	BaseParameter	(	const TChar* title, 
						const TChar* units, 
						int32 stepCount, 
						ParamValue defaultValueNormalized,
						int32 flags,
						int32 tag,
						UnitID unitID = kRootUnitId);

	bool fromString (const TChar* string, ParamValue& _valueNormalized) const;
	bool setNormalized (ParamValue v);

};

//-----------------------------------------------------------------------------
class IndexedParameter : public BaseParameter
{
public:
	IndexedParameter (	const TChar* title, 
						const TChar* units, 
						int32 stepCount, 
						ParamValue defaultValueNormalized,
						int32 flags,
						int32 tag,
						UnitID unitID = kRootUnitId);

	ParamValue toPlain (ParamValue _valueNormalized) const;
	ParamValue toNormalized (ParamValue plainValue) const;

	void toString (ParamValue _valueNormalized, String128 string) const;
	bool fromString (const TChar* string, ParamValue& _valueNormalized) const;

	void setIndexString (int32 index, const String128 str);
protected:
	~IndexedParameter ();
	String128* indexString;
};

//-----------------------------------------------------------------------------
class ScaledParameter : public BaseParameter
{
public:
	ScaledParameter (	const TChar* title, 
						const TChar* units, 
						int32 stepCount, 
						ParamValue defaultValueNormalized,
						int32 flags,
						int32 tag,
						ParamValue minValue = 0.,
						ParamValue maxValue = 1.,
						bool printAsInteger = false,
						UnitID unitID = kRootUnitId);

	ParamValue toPlain (ParamValue _valueNormalized) const;
	ParamValue toNormalized (ParamValue plainValue) const;

	void toString (ParamValue _valueNormalized, String128 string) const;
	bool fromString (const TChar* string, ParamValue& _valueNormalized) const;
protected:
	ParamValue minValue;
	ParamValue maxValue;
	bool printAsInteger;
};

}}} // namespaces

#endif
