//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins : 
//
// Version 3.6
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// (c) 2008, Steinberg Media Technologies, All Rights Reserved
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation 
//     and/or other materials provided with the distribution.
//   * Neither the name of the Steinberg Media Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from this 
//     software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#ifndef __cfileselector__
#define __cfileselector__

#include "vstgui.h"

#ifndef VSTGUI_NEW_CFILESELECTOR
#define VSTGUI_NEW_CFILESELECTOR MAC
#endif

#if VSTGUI_NEW_CFILESELECTOR
#include <list>
#include <vector>

BEGIN_NAMESPACE_VSTGUI

//-----------------------------------------------------------------------------
// CFileExtension Declaration
//! \brief file extension description
//-----------------------------------------------------------------------------
class CFileExtension : public CBaseObject
{
public:
	CFileExtension (const char* description, const char* extension, const char* mimeType = 0, int macType = 0);
	CFileExtension (const CFileExtension& ext);
	~CFileExtension ();

	const char* getDescription () const { return description; }
	const char* getExtension () const { return extension; }
	const char* getMimeType () const { return mimeType; }
	int getMacType () const { return macType; }

	bool operator== (const CFileExtension& ext) const;
protected:
	void init (const char* description, const char* extension, const char* mimeType);
	
	char* description;
	char* extension;
	char* mimeType;
	int macType;
};

//-----------------------------------------------------------------------------
// CNewFileSelector Declaration
//! \brief New file selector class
/// \nosubgrouping
/*! @class CNewFileSelector
@section usage Usage
Running the file selector
\code
void MyClass::runFileSelector ()
{
	CNewFileSelector* selector = CNewFileSelector::create (getFrame (), CNewFileSelector::kSelectFile);
	if (selector)
	{
		selector->addFileExtension (CFileExtension ("AIFF", "aif", "audio/aiff"));
		selector->setDefaultExtension (CFileExtension ("WAVE", "wav"));
		selector->setTitle("Choose An Audio File");
		selector->run (this);
		selector->forget ();
	}
}
\endcode
Getting results
\code
CMessageResult MyClass::notify (CBaseObject* sender, const char* message)
{
	if (message == CNewFileSelector::kSelectEndMessage)
	{
		CNewFileSelector* sel = dynamic_cast<CNewFileSelector*>(sender);
		if (sel)
		{
			// do anything with the selected files here
			return kMessageNotified;
		}
	}
	return parent::notify (sender, message);
}
\endcode
*/
//-----------------------------------------------------------------------------
class CNewFileSelector : public CBaseObject
{
public:
	enum Style {
		kSelectFile,				///< select file(s) selector style
		kSelectSaveFile,			///< select save file selector style
		kSelectDirectory			///< select directory style
	};
	
	//-----------------------------------------------------------------------------
	/// \name CFileSelector running
	//-----------------------------------------------------------------------------
	//@{
	static CNewFileSelector* create (CFrame* parent = 0, Style style = kSelectFile); ///< create a new instance

	bool run (CBaseObject* delegate);	///< the delegate will get a kSelectEndMessage throu the notify method where the sender is this CNewFileSelector object
	void cancel ();						///< cancel running the file selector
	bool runModal ();					///< run as modal dialog
	//@}

	//-----------------------------------------------------------------------------
	/// \name CFileSelector setup
	//-----------------------------------------------------------------------------
	//@{
	void setTitle (const char* title);							///< set title of file selector
	void setInitialDirectory (const char* path);				///< set initial directory (UTF8 string)
	void setDefaultSaveName (const char* name);					///< set initial save name (UTF8 string)
	void setDefaultExtension (const CFileExtension& extension);	///< set default file extension
	void setAllowMultiFileSelection (bool state);				///< set allow multi file selection (only valid for kSelectFile selector style)
	void addFileExtension (const CFileExtension& extension);	///< add a file extension
	//@}

	//-----------------------------------------------------------------------------
	/// \name CFileSelector result
	//-----------------------------------------------------------------------------
	//@{
	int getNumSelectedFiles () const;							///< get number of selected files
	const char* getSelectedFile (int index) const;				///< get selected file. Result is only valid as long as the instance of CNewFileSelector is valid.
	//@}

	static const CFileExtension& getAllFilesExtension ();		///< get the all files extension

	static const char* kSelectEndMessage;
//-----------------------------------------------------------------------------
protected:
	CNewFileSelector (CFrame* frame = 0);
	~CNewFileSelector ();

	virtual bool runInternal (CBaseObject* delegate) = 0;
	virtual void cancelInternal () = 0;
	virtual bool runModalInternal () = 0;

	CFrame* frame;
	char* title;
	char* initialPath;
	char* defaultSaveName;
	const CFileExtension* defaultExtension;
	bool allowMultiFileSelection;

	std::list<CFileExtension> extensions;
	std::vector<char*> result;
};

END_NAMESPACE_VSTGUI

#endif

#if !__LP64__

#ifndef __aeffectx__
struct VstFileSelect;
#endif

BEGIN_NAMESPACE_VSTGUI

//-----------------------------------------------------------------------------
// CFileSelector Declaration
//! \brief deprecated file selector class
//! \deprecated
//-----------------------------------------------------------------------------
class CFileSelector
{
public:
	CFileSelector (void* ptr);
	virtual ~CFileSelector ();

	long run (VstFileSelect *vstFileSelect);

protected:
	void* ptr;
	VstFileSelect *vstFileSelect;

	#if MAC
	static pascal void navEventProc (const NavEventCallbackMessage callBackSelector, NavCBRecPtr callBackParms, NavCallBackUserData callBackUD);
	static pascal Boolean navObjectFilterProc (AEDesc *theItem, void *info, void *callBackUD, NavFilterModes filterMode);
	#endif
};

END_NAMESPACE_VSTGUI

#ifndef __aeffectx__
struct VstFileType
{
	VstFileType (char* _name, char *_macType, char *_dosType, char *_unixType = 0, char *_mimeType1 = 0, char *_mimeType2 = 0)
	{
		if (_name)
			strcpy (name, _name);
		if (_macType)
			strcpy (macType, _macType);
		if (_dosType)
			strcpy (dosType, _dosType);
		if (_unixType)
			strcpy (unixType, _unixType);
		if (_mimeType1)
			strcpy (mimeType1, _mimeType1);
		if (_mimeType2)
			strcpy (mimeType2, _mimeType2);
	}
	char name[128];
	char macType[8];
	char dosType[8];
	char unixType[8];
	char mimeType1[128];
	char mimeType2[128];
};

struct VstFileSelect
{
	long command;           // see enum kVstFileLoad....
	long type;              // see enum kVstFileType...

	long macCreator;        // optional: 0 = no creator

	long nbFileTypes;       // nb of fileTypes to used
	VstFileType *fileTypes; // list of fileTypes

	char title[1024];       // text display in the file selector's title

	char *initialPath;      // initial path

	char *returnPath;       // use with kVstFileLoad and kVstDirectorySelect
							// if null is passed, the host will allocated memory
							// the plugin should then called closeOpenFileSelector for freeing memory
	long sizeReturnPath; 

	char **returnMultiplePaths; // use with kVstMultipleFilesLoad
								// the host allocates this array. The plugin should then called closeOpenFileSelector for freeing memory
	long nbReturnPath;			// number of selected paths

	long reserved;				// reserved for host application
	char future[116];			// future use
};

enum {
	kVstFileLoad = 0,
	kVstFileSave,
	kVstMultipleFilesLoad,
	kVstDirectorySelect,

	kVstFileType = 0
};
#endif
#endif // !__LP64__

#endif
