/*
 *  mdaComboProcessor.cpp
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/14/08.
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

#include "mdaComboProcessor.h"
#include "mdaComboController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ComboProcessor::uid (0x11C1BD22, 0x888F4F17, 0xB2E2A77B, 0x51CEDCD6);

//-----------------------------------------------------------------------------
ComboProcessor::ComboProcessor ()
: buffer (0)
, buffe2 (0)
{
	setControllerClass (ComboController::uid);
	allocParameters (7);
}

//-----------------------------------------------------------------------------
ComboProcessor::~ComboProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ComboProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 1.00f; //select
		params[1] = 0.50f; //drive
		params[2] = 0.50f; //bias
		params[3] = 0.50f; //output
		params[4] = 0.40f; //stereo
		params[5] = 0.00f; //hpf freq
		params[6] = 0.50f; //hpf reso

		size = 1024;
		bufpos = 0;
		buffer = new float[size];
		buffe2 = new float[size];
		
		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ComboProcessor::terminate ()
{
	if (buffer) delete [] buffer;
	if (buffe2) delete [] buffe2;
	buffer = buffe2 = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ComboProcessor::setActive (TBool state)
{
	if (state)
		clearBuffers ();
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void ComboProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, trm, m1=mix1, m2=mix2, clp=clip;	
	float o=lpf, i = 1.f-lpf, o2=hpf, bi=bias, drv=drive;
	float f1=ff1, f2=ff2, f3=ff3, f4=ff4, f5=ff5;
	float a2, b2, f6=ff6, f7=ff7, f8=ff8, f9=ff9, f10=ff10;
	float hf=hhf, hq=hhq, h0=hh0, h1=hh1;
	int32 d1=del1, d2=del2, bp = bufpos;

	trm = trim * i * i * i * i;

	--in1;	
	--in2;	
	--out1;
	--out2;

	if (ster) //stereo
	{
		while (--sampleFrames >= 0)
		{
			a = drv * (*++in1 + bi); a2 = drv * (*++in2 + bi);

			if (mode)
			{
				b = (a>0.f)? a : -a;     b2 = (a2>0.f)? a2 : -a2;
				b = a / (1.f + b);       b2 = a2 / (1.f + b2);
			}
			else
			{
				b = (a> clp)?  clp : a;  b2 = (a2> clp)?  clp : a2; //distort
				b = (a<-clp)? -clp : b;  b2 = (a2<-clp)? -clp : b2;
			}

			*(buffer + bp) = b;        *(buffe2 + bp) = b2; 
			b += (m1* *(buffer+((bp+d1)%1000))) + (m2* *(buffer+((bp+d2)%1000)));
			b2+= (m1* *(buffe2+((bp+d1)%1000))) + (m2* *(buffe2+((bp+d2)%1000)));

			f1 = o * f1 + trm * b;     f6 = o * f6 + trm * b2;
			f2 = o * f2 + f1;      f7 = o * f7 + f6;
			f3 = o * f3 + f2;      f8 = o * f8 + f7;
			f4 = o * f4 + f3;      f9 = o * f9 + f8; //-24dB/oct filter

			f5 = o2 * (f5 - f4) + f4;  f10 = o2 * (f10 - f9) + f9;//high pass
			b = f4 - f5;               b2 = f9 - f10;

			if (bp == 0) bufpos=999; else bufpos=bp-1;

			*++out1 = b;	
			*++out2 = b2;
		}
	}
	else //mono
	{
		if (mode) //soft clip
		{
			while (--sampleFrames >= 0)
			{
				a = drv * (*++in1 + *++in2 + bi);

				h0 += hf * (h1 + a); //resonant highpass (Chamberlin SVF)
				h1 -= hf * (h0 + hq * h1);
				a += h1;

				b = (a>0.f)? a : -a;
				b = a / (1.f + b);

				*(buffer + bp) = b; 
				b += (m1* *(buffer+((bp+d1)%1000))) + (m2* *(buffer+((bp+d2)%1000)));

				f1 = o * f1 + trm * b;
				f2 = o * f2 + f1;
				f3 = o * f3 + f2;
				f4 = o * f4 + f3; //-24dB/oct filter

				f5 = o2 * (f5 - f4) + f4; //high pass
				b = f4 - f5;

				bp = (bp == 0)? 999 : bp - 1; //buffer position

				*++out1 = b;
				*++out2 = b;
			}
		}
		else //hard clip
		{
			while (--sampleFrames >= 0)
			{
				a = drv * (*++in1 + *++in2 + bi);

				h0 += hf * (h1 + a); //resonant highpass (Chamberlin SVF)
				h1 -= hf * (h0 + hq * h1);
				a += h1;

				b = (a>clp)? clp : a; //distort
				b = (a<-clp)? -clp : b;

				*(buffer + bp) = b; 
				b += (m1* *(buffer+((bp+d1)%1000))) + (m2* *(buffer+((bp+d2)%1000)));

				f1 = o * f1 + trm * b;
				f2 = o * f2 + f1;
				f3 = o * f3 + f2;
				f4 = o * f4 + f3; //-24dB/oct filter

				f5 = o2 * (f5 - f4) + f4; //high pass //also want smile curve here...
				b = f4 - f5;

				bp = (bp == 0)? 999 : bp - 1; //buffer position

				*++out1 = b;
				*++out2 = b;
			}
		}
	}
	bufpos = bp;
	if (fabs (f1) < 1.0e-10) { ff1=0.f; ff2=0.f; ff3=0.f; ff4=0.f; ff5=0.f;  }
	else { ff1=f1;  ff2=f2;  ff3=f3;  ff4=f4;  ff5=f5;   }
	if (fabs (f6) < 1.0e-10) { ff6=0.f; ff7=0.f; ff8=0.f; ff9=0.f; ff10=0.f; } 
	else { ff6=f6;  ff7=f7;  ff8=f8;  ff9=f9;  ff10=f10; }
	if (fabs (h0) < 1.0e-10) { hh0 = hh1 = 0.0f; } else { hh0=h0; hh1=h1; }
}

//-----------------------------------------------------------------------------
void ComboProcessor::clearBuffers ()
{
	memset (buffer, 0, size * sizeof (float));
	memset (buffe2, 0, size * sizeof (float));

	ff1=0.f; ff2=0.f; ff3=0.f; ff4=0.f; ff5=0.f;
	ff6=0.f; ff7=0.f; ff8=0.f; ff9=0.f; ff10=0.f;
	hh0 = hh1 = 0.0f;
}

//-----------------------------------------------------------------------------
float ComboProcessor::filterFreq(float hz)
{
	float j, k, r=0.999f;

	j = r * r - 1;
	k = (float)(2.f - 2.f * r * r * cos(0.647f * hz / getSampleRate () ));
	return (float)((sqrt (k*k - 4.f*j*j) - k) / (2.f*j));
}

//-----------------------------------------------------------------------------
void ComboProcessor::recalculate ()
{
	ster=0; if (params[4]>0.5) ster=1;
	hpf = filterFreq(25.f);
	switch (int (params[0]*6.9))
	{
		case 0: trim = 0.5f; lpf = 0.f;                 //DI
				mix1 = (float)0.0; mix2 = (float)0.0;
				del1 = 0; del2 = 0; 
				break;

		case 1: trim = 0.53f; lpf = filterFreq(2700.f); //speaker sim
				mix1 = (float)0.0; mix2 = (float)0.0;
				del1 = 0; del2 = 0;
				hpf = filterFreq(382.f); 
				break;

		case 2: trim = 1.10f; lpf = filterFreq(1685.f); //radio
				mix1 = -1.70f; mix2 = 0.82f; 
				del1 = int (getSampleRate () / 6546.f);
				del2 = int (getSampleRate () / 4315.f); 
				break;

		case 3: trim = 0.98f; lpf = filterFreq(1385.f); //mesa boogie 1"
				mix1 = -0.53f; mix2 = 0.21f;
				del1 = int (getSampleRate () / 7345.f);
				del2 = int (getSampleRate () / 1193.f); 
				break;

		case 4: trim = 0.96f; lpf = filterFreq(1685.f); //mesa boogie 8"
				mix1 = -0.85f; mix2 = 0.41f; 
				del1 = int (getSampleRate () / 6546.f);
				del2 = int (getSampleRate () / 3315.f); 
				break;

		case 5: trim = 0.59f; lpf = lpf = filterFreq(2795.f); 
				mix1 = -0.29f; mix2 = 0.38f;          //Marshall 4x12" celestion
				del1 = int (getSampleRate () / 982.f);
				del2 = int (getSampleRate () / 2402.f);
				hpf = filterFreq(459.f); 
				break;

		case 6: trim = 0.30f; lpf = filterFreq(1744.f); //scooped-out metal 
				mix1 = -0.96f; mix2 = 1.6f; 
				del1 = int (getSampleRate () / 356.f);
				del2 = int (getSampleRate () / 1263.f);
				hpf = filterFreq(382.f); 
				break;
	}

	mode = (params[1]<0.5)? 1 : 0; 
	if (mode) //soft clipping
	{
		drive = (float)pow (10.f, (float)(2.f - 6.f * params[1]));
		trim *= 0.55f + 150.f * (float)pow ((float)(params[1]),4.0f);
	}
	else //hard clipping
	{
		drive = 1.f;
		clip = (float)(11.7f - 16.f*params[1]);
	if (params[1]>0.7)
	{
		drive = (float)pow (10.0f, (float)(7.f*params[1] - 4.9f));
		clip = 0.5f;
	}
	}
	bias = (float)(1.2f * params[2] - 0.6f);
	if (params[1]>0.5) bias /= (float)(1.f + 3.f * (params[1]-0.5f));
	else bias /= (float)(1.f + 3.f * (0.5f-params[1]));
	trim *= (float)pow (10.f, (float)(2.f*params[3] - 1.f));
	if (ster) trim *=2.f;

	hhf = (float)params[5];
	hhq = 1.1f - (float)params[6];
	if (params[5]>0.05f) drive = drive * (1 + 0.1f * drive);
}

}}} // namespaces
