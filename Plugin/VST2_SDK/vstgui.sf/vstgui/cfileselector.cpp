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

#if ENABLE_VST_EXTENSION_IN_VSTGUI
#include "public.sdk/source/vst2.x/audioeffectx.h"
#endif

#include "cfileselector.h"

#if VSTGUI_NEW_CFILESELECTOR

//-----------------------------------------------------------------------------
CFileExtension::CFileExtension (const char* inDescription, const char* inExtension, const char* inMimeType, int inMacType)
: description (0)
, extension (0)
, mimeType (0)
, macType (inMacType)
{
	init (inDescription, inExtension, inMimeType);
}

//-----------------------------------------------------------------------------
CFileExtension::CFileExtension (const CFileExtension& ext)
: description (0)
, extension (0)
, mimeType (0)
, macType (ext.macType)
{
	init (ext.description, ext.extension, ext.mimeType);
}

//-----------------------------------------------------------------------------
CFileExtension::~CFileExtension ()
{
	if (description)
		free (description);
	if (extension)
		free (extension);
	if (mimeType)
		free (mimeType);
}

//-----------------------------------------------------------------------------
void CFileExtension::init (const char* inDescription, const char* inExtension, const char* inMimeType)
{
	if (inDescription)
	{
		description = (char*)malloc (strlen (inDescription) + 1);
		strcpy (description, inDescription);
	}
	if (inExtension)
	{
		extension = (char*)malloc (strlen (inExtension) + 1);
		strcpy (extension, inExtension);
	}
	if (inMimeType)
	{
		mimeType = (char*)malloc (strlen (inMimeType) + 1);
		strcpy (mimeType, inMimeType);
	}
	if (description == 0 && extension)
	{
		// TODO: query system for file type description
		// Win32: AssocGetPerceivedType
		// Mac: Uniform Type Identifier
	}
}

//-----------------------------------------------------------------------------
bool CFileExtension::operator== (const CFileExtension& ext) const
{
	bool result = false;
	if (extension && ext.extension)
		result = (strcmp (extension, ext.extension) == 0);
	if (!result && mimeType && ext.mimeType)
		result = (strcmp (mimeType, ext.mimeType) == 0);
	if (!result && macType != 0 && ext.macType != 0)
		result = (macType == ext.macType);
	return result;
}

//-----------------------------------------------------------------------------
const CFileExtension& CNewFileSelector::getAllFilesExtension ()
{
	static CFileExtension allFilesExtension ("All Files", "");
	return allFilesExtension;
}

//-----------------------------------------------------------------------------
const char* CNewFileSelector::kSelectEndMessage = "CNewFileSelector Select End Message";

//-----------------------------------------------------------------------------
// CNewFileSelector Implementation
//-----------------------------------------------------------------------------
CNewFileSelector::CNewFileSelector (CFrame* frame)
: frame (frame)
, defaultExtension (0)
, title (0)
, initialPath (0)
, defaultSaveName (0)
, allowMultiFileSelection (false)
{
}

//-----------------------------------------------------------------------------
CNewFileSelector::~CNewFileSelector ()
{
	setTitle (0);
	setInitialDirectory (0);
	setDefaultSaveName (0);
	for (int i = 0; i < result.size (); i++)
		free (result[i]);
}

//-----------------------------------------------------------------------------
bool CNewFileSelector::run (CBaseObject* delegate)
{
	if (delegate == 0)
	{
		#if DEBUG
		DebugPrint ("You need to specify a delegate in CNewFileSelector::run (CBaseObject* delegate, void* parentWindow)\n");
		#endif
		return false;
	}
	return runInternal (delegate);
}

//-----------------------------------------------------------------------------
void CNewFileSelector::cancel ()
{
	cancelInternal ();
}

//-----------------------------------------------------------------------------
bool CNewFileSelector::runModal ()
{
	return runModalInternal ();
}

//-----------------------------------------------------------------------------
void CNewFileSelector::setTitle (const char* inTitle)
{
	if (title)
		free (title);
	title = 0;
	if (inTitle)
	{
		title = (char*)malloc (strlen (inTitle) + 1);
		strcpy (title, inTitle);
	}
}

//-----------------------------------------------------------------------------
void CNewFileSelector::setInitialDirectory (const char* path)
{
	if (initialPath)
		free (initialPath);
	initialPath = 0;
	if (path)
	{
		initialPath = (char*)malloc (strlen (path) + 1);
		strcpy (initialPath, path);
	}
}

//-----------------------------------------------------------------------------
void CNewFileSelector::setDefaultSaveName (const char* name)
{
	if (defaultSaveName)
		free (defaultSaveName);
	defaultSaveName = 0;
	if (name)
	{
		defaultSaveName = (char*)malloc (strlen (name) + 1);
		strcpy (defaultSaveName, name);
	}
}

//-----------------------------------------------------------------------------
void CNewFileSelector::setAllowMultiFileSelection (bool state)
{
	allowMultiFileSelection = state;
}

//-----------------------------------------------------------------------------
void CNewFileSelector::setDefaultExtension (const CFileExtension& extension)
{
	if (defaultExtension)
	{
		#if DEBUG
		DebugPrint ("VSTGUI Warning: It's not allowed to set a default extension twice on a CFileSelector instance\n");
		#endif
		return;
	}

	bool found = false;
	std::list<CFileExtension>::const_iterator it = extensions.begin ();
	while (it != extensions.end ())
	{
		if ((*it) == extension)
		{
			defaultExtension = &(*it);
			found = true;
			break;
		}
		it++;
	}
	if (!found)
	{
		addFileExtension (extension);
		setDefaultExtension (extension);
	}
}

//-----------------------------------------------------------------------------
void CNewFileSelector::addFileExtension (const CFileExtension& extension)
{
	extensions.push_back (extension);
}

//-----------------------------------------------------------------------------
int CNewFileSelector::getNumSelectedFiles () const
{
	return result.size ();
}

//-----------------------------------------------------------------------------
const char* CNewFileSelector::getSelectedFile (int index) const
{
	if (index < result.size ())
		return result[index];
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#endif // VSTGUI_NEW_CFILESELECTOR

#if !__LP64__
//-----------------------------------------------------------------------------
// CFileSelector Implementation
//-----------------------------------------------------------------------------
#define stringAnyType  "Any Type (*.*)"
#define stringAllTypes "All Types: ("
#define stringSelect   "Select"
#define stringCancel   "Cancel"
#define stringLookIn   "Look in"
#define kPathMax        1024

#if WINDOWS
#include <stdio.h>

static UINT_PTR APIENTRY SelectDirectoryHook (HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK SelectDirectoryButtonProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
WNDPROC fpOldSelectDirectoryButtonProc;
static UINT_PTR APIENTRY WinSaveHook (HWND hdlg, UINT msg, WPARAM wParam, LPARAM lParam);
static bool bFolderSelected;
static bool bDidCancel;
static TCHAR selDirPath[kPathMax];

extern void* hInstance;
inline HINSTANCE GetInstance () { return (HINSTANCE)hInstance; }
#endif

BEGIN_NAMESPACE_VSTGUI

//-----------------------------------------------------------------------------
/**
 * CFileSelector constructor.
 * @param ptr if ENABLE_VST_EXTENSION_IN_VSTGUI is active this is a ptr to the AudioEffectX class. If it is not active this must be the system window.
 */
CFileSelector::CFileSelector (void* ptr)
: ptr (ptr)
, vstFileSelect (0)
{}

//-----------------------------------------------------------------------------
CFileSelector::~CFileSelector ()
{
	if (vstFileSelect)
	{
		#if ENABLE_VST_EXTENSION_IN_VSTGUI
		if (ptr && ((AudioEffectX*)ptr)->canHostDo ("closeFileSelector"))
			((AudioEffectX*)ptr)->closeFileSelector (vstFileSelect);
		else
		#endif
		{
			if (vstFileSelect->reserved == 1 && vstFileSelect->returnPath)
			{
				delete []vstFileSelect->returnPath;
				vstFileSelect->returnPath = 0;
				vstFileSelect->sizeReturnPath = 0;
			}
			if (vstFileSelect->returnMultiplePaths)
			{
				for (long i = 0; i < vstFileSelect->nbReturnPath; i++)
				{
					delete []vstFileSelect->returnMultiplePaths[i];
					vstFileSelect->returnMultiplePaths[i] = 0;
				}
				delete[] vstFileSelect->returnMultiplePaths;
				vstFileSelect->returnMultiplePaths = 0;
			}
		}
	}
}

//-----------------------------------------------------------------------------
long CFileSelector::run (VstFileSelect *vstFileSelect)
{
	this->vstFileSelect = vstFileSelect;
	vstFileSelect->nbReturnPath = 0;
	if (vstFileSelect->returnPath)
		vstFileSelect->returnPath[0] = 0;

	#if ENABLE_VST_EXTENSION_IN_VSTGUI
	if (ptr
	#if MAC 
		&& vstFileSelect->command != kVstFileSave 
	#endif
		&& ((AudioEffectX*)ptr)->canHostDo ("openFileSelector") && ((AudioEffectX*)ptr)->canHostDo ("closeFileSelector"))
	{
		if (((AudioEffectX*)ptr)->openFileSelector (vstFileSelect))
			return vstFileSelect->nbReturnPath;
	}
	else
	#endif
	{
#if WINDOWS
		TCHAR filter[512];
		TCHAR filePathBuffer[kPathMax];
		filePathBuffer[0] = 0;
		TCHAR* filePath = filePathBuffer;
		TCHAR fileName[kPathMax];
		filter[0] = 0;
		//filePath[0] = 0;
		fileName[0] = 0;
		#if ENABLE_VST_EXTENSION_IN_VSTGUI
		HWND owner = (HWND)((AEffGUIEditor*)((AudioEffectX*)ptr)->getEditor ())->getFrame ()->getSystemWindow ();
		#else
		HWND owner = (HWND)ptr;
		#endif

		//----------------------------------------
		// TODO:: filter does not work in UTF8 yet
		//----------------------------------------
		UTF8StringHelper filterText (filter);
		UTF8StringHelper initialPathText (vstFileSelect->initialPath);
		UTF8StringHelper titleText (vstFileSelect->title);

		//-----------------------------------------
		if (vstFileSelect->command == kVstFileLoad ||
			vstFileSelect->command == kVstMultipleFilesLoad ||
			vstFileSelect->command == kVstDirectorySelect)
		{
			TCHAR* multiBuffer = 0;
			if (vstFileSelect->command == kVstMultipleFilesLoad)
			{
				multiBuffer = new TCHAR [kPathMax * 100];
				multiBuffer[0] = 0;
				filePath = multiBuffer;
			}

			if (vstFileSelect->command != kVstDirectorySelect) 
			{
				TCHAR allBuffer [kPathMax] = {0};
				TCHAR* p = filter;
				TCHAR* p2 = allBuffer;

				TCHAR extensions [100][24];
				long i, j, extCount = 0;
				TCHAR string[24];

				for (long ty = 0; ty < vstFileSelect->nbFileTypes; ty++)
				{
					UTF8StringHelper ext (vstFileSelect->fileTypes[ty].dosType);
					UTF8StringHelper name (vstFileSelect->fileTypes[ty].name);
					for (i = 0; i < 2 ; i++)
					{				
						if (i == 0)
						{
							VSTGUI_STRCPY (p, name);
							VSTGUI_STRCAT (p, TEXT (" (."));
							VSTGUI_STRCAT (p, ext);
							VSTGUI_STRCAT (p, TEXT (")"));
							p += VSTGUI_STRLEN (p) + 1;

							VSTGUI_STRCPY (string, TEXT ("*."));
							VSTGUI_STRCAT (string, ext);
							VSTGUI_STRCPY (p, string);
							p += VSTGUI_STRLEN (p);	
						}
						else
						{
							if (!strcmp (vstFileSelect->fileTypes[ty].dosType, vstFileSelect->fileTypes[ty].unixType) || !strcmp (vstFileSelect->fileTypes[ty].unixType, ""))
								break; // for
							UTF8StringHelper ext2 (vstFileSelect->fileTypes[ty].unixType);
							VSTGUI_STRCPY (string, TEXT(";*."));
							VSTGUI_STRCAT (string, ext2);
							VSTGUI_STRCPY (p, string);
							p += VSTGUI_STRLEN (p);	
						}
						bool found = false;
						for (j = 0; j < extCount;j ++)
						{
							if (VSTGUI_STRCMP (ext, extensions [j]) == 0)
							{
								found = true;
								break;
							}
						}
						if (!found && extCount < 100)
							VSTGUI_STRCPY (extensions [extCount++], ext);
					}
					p ++;
				} // end for filetype
			
				if (extCount > 1)
				{
					for (i = 0; i < extCount ;i ++)
					{				
						const TCHAR* ext2 = extensions [i];
						VSTGUI_STRCPY (string, TEXT ("*."));
						VSTGUI_STRCAT (string, ext2);

						if (p2 != allBuffer)
						{
							VSTGUI_STRCPY (p2, TEXT (";"));
							p2++;
						}
						VSTGUI_STRCPY (p2, string);
						p2 += VSTGUI_STRLEN (p2);
					}

					// add the : All types
					UTF8StringHelper allTypesStr (stringAllTypes);
					VSTGUI_STRCPY (p, allTypesStr);			
					VSTGUI_STRCAT (p, allBuffer);
					VSTGUI_STRCAT (p, TEXT (")"));
					p += VSTGUI_STRLEN (p) + 1;
					VSTGUI_STRCPY (p, allBuffer);
					p += VSTGUI_STRLEN (p) + 1;			
				}
				UTF8StringHelper anyTypeStr (stringAnyType);
				VSTGUI_STRCPY (p, anyTypeStr);
				p += VSTGUI_STRLEN (p) + 1;
				VSTGUI_STRCPY (p, TEXT("*.*"));
				p += VSTGUI_STRLEN (p) + 1;

				*p++ = 0;
				*p++ = 0;
			}

			OPENFILENAME ofn = {0};
			ofn.lStructSize  = sizeof (OPENFILENAME);
			ofn.hwndOwner    = owner;
	
			if (vstFileSelect->command == kVstDirectorySelect) 
				ofn.lpstrFilter = TEXT("HideFileFilter\0*.___\0\0"); // to hide files
			else
				ofn.lpstrFilter  = (filter[0] ? filterText : (TCHAR*)0);
			ofn.nFilterIndex = 1;
			ofn.lpstrCustomFilter = NULL;
			ofn.lpstrFile    = filePath;
			if (vstFileSelect->command == kVstMultipleFilesLoad)
				ofn.nMaxFile    = 100 * kPathMax - 1;
			else
				ofn.nMaxFile    = sizeof (filePathBuffer) - 1;

			ofn.lpstrFileTitle  = fileName;
			ofn.nMaxFileTitle   = 64;
			ofn.lpstrInitialDir = initialPathText;
			ofn.lpstrTitle      = titleText;
			ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_EXPLORER | OFN_ENABLESIZING | OFN_ENABLEHOOK;
			if (vstFileSelect->command == kVstDirectorySelect)
			{
				ofn.Flags &= ~OFN_FILEMUSTEXIST;
				ofn.lpfnHook = SelectDirectoryHook;
			}

			if (vstFileSelect->command == kVstMultipleFilesLoad)
				ofn.Flags |= OFN_ALLOWMULTISELECT;
		
			vstFileSelect->nbReturnPath = 0;
			bDidCancel = true;

			if (GetOpenFileName (&ofn) || 
				((vstFileSelect->command == kVstDirectorySelect) && !bDidCancel && VSTGUI_STRLEN (selDirPath) != 0))  
			{
				UTF8StringHelper resultString (ofn.lpstrFile);
				switch (vstFileSelect->command)
				{
				case kVstFileLoad:
					vstFileSelect->nbReturnPath = 1;
					if (!vstFileSelect->returnPath)
					{
						vstFileSelect->reserved = 1;
						vstFileSelect->returnPath = new char[strlen (resultString) + 1];
						vstFileSelect->sizeReturnPath = (long)strlen (resultString) + 1;			
					}
					strcpy (vstFileSelect->returnPath, resultString);
					break;
				
				case kVstMultipleFilesLoad:
					{
					char string[kPathMax], directory[kPathMax];
					char *previous = (char*)(const char*)resultString;
					size_t len;
					bool dirFound = false;
					bool first = true;
					directory[0] = 0; // !!
					vstFileSelect->returnMultiplePaths = new char*[kPathMax];
					long i = 0;
					while (1)
					{
						if (*previous != 0)
						{   // something found
							if (!dirFound) 
							{
								dirFound = true;
								strcpy (directory, previous);
								len = strlen (previous) + 1;  // including 0
								previous += len;

								if (*previous == 0)
								{  // 1 selected file only		
									vstFileSelect->returnMultiplePaths[i] = new char [strlen (directory) + 1];
									strcpy (vstFileSelect->returnMultiplePaths[i++], directory);
								}
								else
								{
									if (directory[strlen (directory) - 1] != '\\')
										strcat (directory, "\\");
								}
							}
							else 
							{
								sprintf (string, "%s%s", directory, previous);
								len = strlen (previous) + 1;  // including 0
								previous += len;

								vstFileSelect->returnMultiplePaths[i] = new char [strlen (string) + 1];
								strcpy (vstFileSelect->returnMultiplePaths[i++], string);
							}
						}
						else
							break;
					}
					vstFileSelect->nbReturnPath = i;					
					} break;

				case kVstDirectorySelect:
					UTF8StringHelper selDirPathText (selDirPath);
					vstFileSelect->nbReturnPath = 1;
					if (!vstFileSelect->returnPath)
					{
						vstFileSelect->reserved = 1;
						vstFileSelect->returnPath = new char[strlen (selDirPathText) + 1];
						vstFileSelect->sizeReturnPath = (long)strlen (selDirPathText) + 1;			
					}
					strcpy (vstFileSelect->returnPath, selDirPathText);
				}
				if (multiBuffer)
					delete []multiBuffer;
				return vstFileSelect->nbReturnPath;
			}
			if (multiBuffer)
				delete []multiBuffer;
		}

		//-----------------------------------------
		else if (vstFileSelect->command == kVstFileSave)
		{
			TCHAR* p = filter;
			for (long ty = 0; ty < vstFileSelect->nbFileTypes; ty++)
			{
				const char* ext = vstFileSelect->fileTypes[ty].dosType;
				if (ext)
				{
					UTF8StringHelper extStr (ext);
					UTF8StringHelper extName (vstFileSelect->fileTypes[ty].name);
					VSTGUI_STRCPY (p, extName);
					VSTGUI_STRCAT (p, TEXT(" (."));
					VSTGUI_STRCAT (p, extStr);
					VSTGUI_STRCAT (p, TEXT(")"));
					p += VSTGUI_STRLEN (p) + 1;
	
					TCHAR string[24];
					VSTGUI_STRCPY (string, TEXT("*."));
					VSTGUI_STRCAT (string, extStr);
					VSTGUI_STRCPY (p, string);
					p += VSTGUI_STRLEN (p) + 1;
				}
			}
			*p++ = 0;
			*p++ = 0;
		
			OPENFILENAME ofn = {0};
			ofn.lStructSize  = sizeof (OPENFILENAME);
			HWND owner = 0;
			#if ENABLE_VST_EXTENSION_IN_VSTGUI
			if (((AudioEffectX*)ptr)->getEditor () && ((AEffGUIEditor*)((AudioEffectX*)ptr)->getEditor ())->getFrame ())
				owner = (HWND)((AEffGUIEditor*)((AudioEffectX*)ptr)->getEditor ())->getFrame ()->getSystemWindow ();
			#else
			owner = (HWND)ptr;
			#endif
			ofn.hwndOwner    = owner;
			ofn.hInstance    = GetInstance ();
			ofn.lpstrFilter = (filter[0] ? filterText : (TCHAR*)0);
			ofn.nFilterIndex = 1;
			ofn.lpstrFile = filePath;
			ofn.lpstrCustomFilter = NULL;
			ofn.nMaxFile = sizeof (filePathBuffer) - 1;
			ofn.lpstrFileTitle = fileName;
			ofn.nMaxFileTitle = 64;
			ofn.lpstrInitialDir = initialPathText;
			ofn.lpstrTitle = titleText;
			ofn.Flags = OFN_EXPLORER | OFN_ENABLESIZING | OFN_HIDEREADONLY | OFN_ENABLEHOOK;
			
			UTF8StringHelper dosTypeText (vstFileSelect->fileTypes[0].dosType);
			if (vstFileSelect->nbFileTypes >= 1)
				ofn.lpstrDefExt = dosTypeText;
			
			// add a template view
			ofn.lCustData = (DWORD)0;
			ofn.lpfnHook = WinSaveHook;
			
			if (GetSaveFileName (&ofn))	
			{
				UTF8StringHelper resultText (ofn.lpstrFile);
				vstFileSelect->nbReturnPath = 1;
				if (!vstFileSelect->returnPath)
				{
					vstFileSelect->reserved = 1;
					vstFileSelect->returnPath = new char[strlen (resultText) + 1];
					vstFileSelect->sizeReturnPath = (long)strlen (resultText) + 1;			
				}
				strcpy (vstFileSelect->returnPath, resultText);
			
				return vstFileSelect->nbReturnPath;
			}
			#if _DEBUG
			else
			{
				DWORD err = CommDlgExtendedError (); // for breakpoint
			}
			#endif
		}

#elif MAC && !__LP64__
		// new approach for supporting long filenames on mac os x is to use unix path mode
		// if vstFileSelect->future[0] is 1 on entry and 0 on exit the resulting paths are UTF8 encoded paths
		bool unixPathMode = (vstFileSelect->future[0] == 1);
		NavEventUPP	eventUPP = NewNavEventUPP (CFileSelector::navEventProc);
		if (vstFileSelect->command == kVstFileSave)
		{
			NavDialogCreationOptions dialogOptions;
			NavGetDefaultDialogCreationOptions (&dialogOptions);
			dialogOptions.windowTitle = CFStringCreateWithCString (NULL, vstFileSelect->title[0] ? vstFileSelect->title : "Select a Destination", kCFStringEncodingUTF8);
			CFStringRef defSaveName = 0;
			if (unixPathMode && vstFileSelect->initialPath)
			{
				char* name = strrchr (vstFileSelect->initialPath, '/');
				if (name && name[1] != 0)
				{
					defSaveName = dialogOptions.saveFileName = CFStringCreateWithCString (NULL, name+1, kCFStringEncodingUTF8);
					name[0] = 0;
					dialogOptions.optionFlags |= kNavPreserveSaveFileExtension;
				}
				else if (name == 0)
				{
					defSaveName = dialogOptions.saveFileName = CFStringCreateWithCString (NULL, vstFileSelect->initialPath, kCFStringEncodingUTF8);
					dialogOptions.optionFlags |= kNavPreserveSaveFileExtension;
					vstFileSelect->initialPath = 0;
				}
			}
			else if (vstFileSelect->initialPath && ((FSSpec*)vstFileSelect->initialPath)->name)
			{
				FSSpec* defaultSpec = (FSSpec*)vstFileSelect->initialPath;
				defSaveName = CFStringCreateWithPascalString (NULL, defaultSpec->name, kCFStringEncodingASCII);
				if (defSaveName)
				{
					dialogOptions.saveFileName = defSaveName;
					dialogOptions.optionFlags |= kNavPreserveSaveFileExtension;
				}
				*defaultSpec->name = 0;
			}
			NavDialogRef dialogRef;
			if (NavCreatePutFileDialog (&dialogOptions, 0, kNavGenericSignature, eventUPP, this, &dialogRef) == noErr) 
			{
			    AEDesc defaultLocation;   
			    AEDesc* defLocPtr = 0;   
				if (vstFileSelect->initialPath)
				{
					if (unixPathMode)
					{
						FSRef fsRef;
						if (FSPathMakeRef ((const unsigned char*)vstFileSelect->initialPath, &fsRef, NULL) == noErr)
						{
				            if (AECreateDesc (typeFSRef, &fsRef, sizeof(FSRef), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
						}
					}
					else
					{
						FSSpec* defaultSpec = (FSSpec*)vstFileSelect->initialPath;
				        if (defaultSpec->parID && defaultSpec->vRefNum)
				        {
				            if (AECreateDesc (typeFSS, defaultSpec, sizeof(FSSpec), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
						}
					}
				}
		        if (defLocPtr)
		            NavCustomControl (dialogRef, kNavCtlSetLocation, (void*)defLocPtr);
				NavDialogRun (dialogRef);

				if (defLocPtr)
		            AEDisposeDesc (defLocPtr);

				NavReplyRecord navReply;
				if (NavDialogGetReply (dialogRef, &navReply) == noErr)
				{
					FSRef parentFSRef;
					AEKeyword theAEKeyword;
					DescType typeCode;
					Size actualSize;
			        // get the FSRef referring to the parent directory
				    if (AEGetNthPtr(&navReply.selection, 1, typeFSRef,
		        		&theAEKeyword, &typeCode, &parentFSRef, sizeof(FSRef), &actualSize) == noErr)
					{
						if (unixPathMode)
						{
							bool success = true;
							vstFileSelect->nbReturnPath = 1;
							if (vstFileSelect->returnPath == 0)
							{
								vstFileSelect->reserved = 1;
								vstFileSelect->returnPath = new char [PATH_MAX];
							}
							if (FSRefMakePath (&parentFSRef, (unsigned char*)vstFileSelect->returnPath, PATH_MAX) == noErr)
							{
								char saveFileName [PATH_MAX];
								if (CFStringGetCString (navReply.saveFileName, saveFileName, PATH_MAX, kCFStringEncodingUTF8))
								{
									strcat (vstFileSelect->returnPath, "/");
									strcat (vstFileSelect->returnPath, saveFileName);
									vstFileSelect->future[0] = 0;
								}
								else
									success = false;
							}
							else
								success = false;
							if (!success && vstFileSelect->reserved)
							{
								vstFileSelect->nbReturnPath = 0;
								delete [] vstFileSelect->returnPath;
							}
						}
						else
						{
							FSSpec spec;
							FSCatalogInfoBitmap infoBitmap = kFSCatInfoNone;
							FSGetCatalogInfo (&parentFSRef, infoBitmap, NULL, NULL, &spec, NULL);
							CInfoPBRec pbRec = {0};	
							pbRec.dirInfo.ioDrDirID = spec.parID;
							pbRec.dirInfo.ioVRefNum = spec.vRefNum;
							pbRec.dirInfo.ioNamePtr = spec.name;
							if (PBGetCatInfoSync (&pbRec) == noErr)
							{
								spec.parID = pbRec.dirInfo.ioDrDirID;
								// the cfstring -> pascalstring can fail if the filename length > 63 (FSSpec sucks)
								if (CFStringGetPascalString (navReply.saveFileName, (unsigned char*)&spec.name, sizeof (spec.name), kCFStringEncodingASCII))
								{
									vstFileSelect->nbReturnPath = 1;
									if (!vstFileSelect->returnPath)
									{
										vstFileSelect->reserved = 1;
										vstFileSelect->returnPath = new char [sizeof (FSSpec)];
									}
									memcpy (vstFileSelect->returnPath, &spec, sizeof (FSSpec));
								}
							}
						}
					}
					NavDisposeReply (&navReply);
				}
				if (defSaveName)
					CFRelease (defSaveName);
				NavDialogDispose (dialogRef);
				DisposeNavEventUPP (eventUPP);
				return vstFileSelect->nbReturnPath;
			}
			if (defSaveName)
				CFRelease (defSaveName);
		}
		else if (vstFileSelect->command == kVstDirectorySelect)
		{
			NavDialogCreationOptions dialogOptions;
			NavGetDefaultDialogCreationOptions (&dialogOptions);
			dialogOptions.windowTitle = CFStringCreateWithCString (NULL, vstFileSelect->title[0] ? vstFileSelect->title : "Select Directory", kCFStringEncodingUTF8);
			NavDialogRef dialogRef;
			if (NavCreateChooseFolderDialog (&dialogOptions, eventUPP, NULL, this, &dialogRef) == noErr)
			{
			    AEDesc defaultLocation;   
			    AEDesc* defLocPtr = 0;   
				if (vstFileSelect->initialPath)
				{
					if (unixPathMode)
					{
						FSRef fsRef;
						if (FSPathMakeRef ((const unsigned char*)vstFileSelect->initialPath, &fsRef, NULL) == noErr)
						{
				            if (AECreateDesc (typeFSRef, &fsRef, sizeof(FSRef), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
						}
					}
					else
					{
						FSSpec* defaultSpec = (FSSpec*)vstFileSelect->initialPath;
				        if (defaultSpec->parID && defaultSpec->vRefNum)       
				            if (AECreateDesc (typeFSS, defaultSpec, sizeof(FSSpec), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
			        }
				}
		        if (defLocPtr)
		            NavCustomControl (dialogRef, kNavCtlSetLocation, (void*)defLocPtr);
				NavDialogRun (dialogRef);
				if (defLocPtr)
		            AEDisposeDesc (defLocPtr);
				NavReplyRecord navReply;
				if (NavDialogGetReply (dialogRef, &navReply) == noErr)
				{
					FSRef parentFSRef;
					AEKeyword theAEKeyword;
					DescType typeCode;
					Size actualSize;
				    if (AEGetNthPtr(&navReply.selection, 1, typeFSRef,
		        		&theAEKeyword, &typeCode, &parentFSRef, sizeof(FSRef), &actualSize) == noErr)
					{
						if (unixPathMode)
						{
							vstFileSelect->nbReturnPath = 1;
							if (vstFileSelect->returnPath == 0)
							{
								vstFileSelect->reserved = 1;
								vstFileSelect->returnPath = new char [PATH_MAX];
							}
							if (FSRefMakePath (&parentFSRef, (unsigned char*)vstFileSelect->returnPath, PATH_MAX) != noErr)
							{
								vstFileSelect->nbReturnPath = 0;
								if (vstFileSelect->reserved)
									delete [] vstFileSelect->returnPath;
							}
							else
								vstFileSelect->future[0] = 0;
						}
						else
						{
							FSSpec spec;
							FSCatalogInfoBitmap infoBitmap = kFSCatInfoNone;
							FSGetCatalogInfo (&parentFSRef, infoBitmap, NULL, NULL, &spec, NULL);
							vstFileSelect->nbReturnPath = 1;
							if (!vstFileSelect->returnPath)
							{
								vstFileSelect->reserved = 1;
								vstFileSelect->returnPath = new char [sizeof (FSSpec)];
							}
							memcpy (vstFileSelect->returnPath, &spec, sizeof (FSSpec));
						}
					}
					
					NavDisposeReply (&navReply);
				}
				NavDialogDispose (dialogRef);
				DisposeNavEventUPP (eventUPP);
				return vstFileSelect->nbReturnPath;
			}
		}
		else // FileLoad
		{
			NavDialogCreationOptions dialogOptions;
			NavGetDefaultDialogCreationOptions (&dialogOptions);
			if (vstFileSelect->command == kVstFileLoad)
			{
				dialogOptions.windowTitle = CFStringCreateWithCString (NULL, vstFileSelect->title[0] ? vstFileSelect->title : "Select a File to Open", kCFStringEncodingUTF8);
				dialogOptions.optionFlags &= ~kNavAllowMultipleFiles;
			}
			else
			{
				dialogOptions.windowTitle = CFStringCreateWithCString (NULL, vstFileSelect->title[0] ? vstFileSelect->title : "Select Files to Open", kCFStringEncodingUTF8);
				dialogOptions.optionFlags |= kNavAllowMultipleFiles;
			}
			NavObjectFilterUPP objectFilterUPP = NewNavObjectFilterUPP (CFileSelector::navObjectFilterProc);
			NavDialogRef dialogRef;
			if (NavCreateGetFileDialog (&dialogOptions, NULL, eventUPP, NULL, objectFilterUPP, this, &dialogRef) == noErr)
			{
			    AEDesc defaultLocation;   
			    AEDesc* defLocPtr = 0;   
				if (vstFileSelect->initialPath)
				{
					if (unixPathMode)
					{
						FSRef fsRef;
						if (FSPathMakeRef ((const unsigned char*)vstFileSelect->initialPath, &fsRef, NULL) == noErr)
						{
				            if (AECreateDesc (typeFSRef, &fsRef, sizeof(FSRef), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
						}
					}
					else
					{
						FSSpec* defaultSpec = (FSSpec*)vstFileSelect->initialPath;
				        if (defaultSpec->parID && defaultSpec->vRefNum)       
				            if (AECreateDesc (typeFSS, defaultSpec, sizeof(FSSpec), &defaultLocation) == noErr)
				                defLocPtr = &defaultLocation;
			        }
				}
		        if (defLocPtr)
		            NavCustomControl (dialogRef, kNavCtlSetLocation, (void*)defLocPtr);

				NavDialogRun (dialogRef);

				if (defLocPtr)
		            AEDisposeDesc (defLocPtr);

				NavReplyRecord navReply;
				if (NavDialogGetReply (dialogRef, &navReply) == noErr)
				{
					FSRef parentFSRef;
					AEKeyword theAEKeyword;
					DescType typeCode;
					Size actualSize;
					if (vstFileSelect->command == kVstFileLoad)
					{
					    if (AEGetNthPtr(&navReply.selection, 1, typeFSRef,
			        		&theAEKeyword, &typeCode, &parentFSRef, sizeof(FSRef), &actualSize) == noErr)
						{
							if (unixPathMode)
							{
								vstFileSelect->nbReturnPath = 1;
								if (vstFileSelect->returnPath == 0)
								{
									vstFileSelect->reserved = 1;
									vstFileSelect->returnPath = new char [PATH_MAX];
								}
								if (FSRefMakePath (&parentFSRef, (unsigned char*)vstFileSelect->returnPath, PATH_MAX) != noErr)
								{
									vstFileSelect->nbReturnPath = 0;
									if (vstFileSelect->reserved)
										delete [] vstFileSelect->returnPath;
								}
								else
									vstFileSelect->future[0] = 0;
							}
							else
							{
								FSSpec spec;
								FSCatalogInfoBitmap infoBitmap = kFSCatInfoNone;
								FSGetCatalogInfo (&parentFSRef, infoBitmap, NULL, NULL, &spec, NULL);
								vstFileSelect->nbReturnPath = 1;
								if (!vstFileSelect->returnPath)
								{
									vstFileSelect->reserved = 1;
									vstFileSelect->returnPath = new char [sizeof (FSSpec)];
								}
								memcpy (vstFileSelect->returnPath, &spec, sizeof (FSSpec));
							}
						}
					}
					else
					{
						long count;
						AECountItems (&navReply.selection, &count);
						vstFileSelect->nbReturnPath = count;
						vstFileSelect->returnMultiplePaths = new char* [vstFileSelect->nbReturnPath];
						int index = 1;
					    while (AEGetNthPtr(&navReply.selection, index++, typeFSRef,
			        		&theAEKeyword, &typeCode, &parentFSRef, sizeof(FSRef), &actualSize) == noErr)
						{
							if (unixPathMode)
							{
								vstFileSelect->returnMultiplePaths[index-2] = new char[PATH_MAX];
								FSRefMakePath (&parentFSRef, (unsigned char*)vstFileSelect->returnMultiplePaths[index-2], PATH_MAX);
								vstFileSelect->future[0] = 0;
							}
							else
							{
								FSSpec spec;
								FSCatalogInfoBitmap infoBitmap = kFSCatInfoNone;
								FSGetCatalogInfo (&parentFSRef, infoBitmap, NULL, NULL, &spec, NULL);
								vstFileSelect->returnMultiplePaths[index-2] = new char[sizeof (FSSpec)];
								memcpy (vstFileSelect->returnMultiplePaths[index-2], &spec, sizeof (FSSpec));
							}
						}
					}
				}
				DisposeNavObjectFilterUPP (objectFilterUPP);
				DisposeNavEventUPP (eventUPP);
				NavDialogDispose (dialogRef);
				return vstFileSelect->nbReturnPath;
			}
			DisposeNavObjectFilterUPP (objectFilterUPP);
		}
		DisposeNavEventUPP (eventUPP);
#else
		//CAlert::alert ("The current Host application doesn't support FileSelector !", "Warning");
#endif
	}
	return 0;
}

#if MAC && !__LP64__
//-----------------------------------------------------------------------------
pascal void CFileSelector::navEventProc (const NavEventCallbackMessage callBackSelector, NavCBRecPtr callBackParms, NavCallBackUserData callBackUD) 
{
	switch (callBackSelector)
	{
		case kNavCBEvent:
		{
			#if ENABLE_VST_EXTENSION_IN_VSTGUI
			CFileSelector* fs = (CFileSelector*)callBackUD;
			AudioEffectX* effect = (AudioEffectX*)fs->ptr;
			if (effect && callBackParms->eventData.eventDataParms.event->what == nullEvent)
				effect->masterIdle ();
			#endif
			break;
		}
	}
}

//-----------------------------------------------------------------------------
pascal Boolean CFileSelector::navObjectFilterProc (AEDesc *theItem, void *info, void *callBackUD, NavFilterModes filterMode)
{
    Boolean result = false;
	CFileSelector* fs = (CFileSelector*)callBackUD;
    NavFileOrFolderInfo *theInfo = (NavFileOrFolderInfo*)info;

	if (theInfo->isFolder || fs->vstFileSelect->nbFileTypes == 0)
		result = true;
	else
	{
	    FSRef ref;
		AECoerceDesc (theItem, typeFSRef, theItem);
		if (AEGetDescData (theItem, &ref, sizeof (FSRef)) == noErr)
		{
			LSItemInfoRecord infoRecord;
			if (LSCopyItemInfoForRef (&ref, kLSRequestExtension | kLSRequestTypeCreator, &infoRecord) == noErr)
			{
				char extension [128];
				extension[0] = 0;
				if (infoRecord.extension)
					CFStringGetCString (infoRecord.extension, extension, 128, kCFStringEncodingUTF8);
				for (long i = 0; i < fs->vstFileSelect->nbFileTypes; i++)
				{
					VstFileType* ft = &fs->vstFileSelect->fileTypes[i];
					if ((OSType)ft->macType == infoRecord.filetype)
					{
						result = true;
						break;
					}
					else if (infoRecord.extension)
					{
						if (!strcasecmp (extension, ft->unixType) || !strcasecmp (extension, ft->dosType))
						{
							result = true;
							break;
						}
					}
				}
				if (infoRecord.extension)
					CFRelease (infoRecord.extension);
			}
		}
	}
	return result;
}
#endif

END_NAMESPACE_VSTGUI

#if WINDOWS
#include <dlgs.h>
//-----------------------------------------------------------------------------
UINT_PTR APIENTRY SelectDirectoryHook (HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_NOTIFY: 
	{
		OFNOTIFY *lpon = (OFNOTIFY *)lParam;
	
		switch (lpon->hdr.code)
		{
		case CDN_FILEOK:
			CommDlg_OpenSave_GetFolderPath (GetParent (hdlg), selDirPath, kPathMax);
			bDidCancel = false;
			break;
		
		case CDN_INITDONE: {
			#define HIDE_ITEMS 4
			int  i;
			UINT hide_items[HIDE_ITEMS] = {edt1, stc3, cmb1, stc2};	

			for (i = 0; i < HIDE_ITEMS; i++)
				CommDlg_OpenSave_HideControl (GetParent (hdlg), hide_items[i]);
			
			CommDlg_OpenSave_SetControlText (GetParent (hdlg), stc4, (char*)(const char*)stringLookIn);
			CommDlg_OpenSave_SetControlText (GetParent (hdlg), IDOK, (char*)(const char*)stringSelect);
			CommDlg_OpenSave_SetControlText (GetParent (hdlg), IDCANCEL, (char*)(const char*)stringCancel);
		} break;
		}
	} break;

	case WM_INITDIALOG:
		fpOldSelectDirectoryButtonProc = /*(FARPROC)*/(WNDPROC)SetWindowLongPtr (
					GetDlgItem (GetParent (hdlg), IDOK), 
					GWLP_WNDPROC, (LONG_PTR)SelectDirectoryButtonProc);
		break;
		
	case WM_DESTROY:
		SetWindowLong (GetDlgItem (GetParent (hdlg), IDOK), 
				GWLP_WNDPROC, (LONG_PTR)fpOldSelectDirectoryButtonProc);
	}
	return false;
}

//-----------------------------------------------------------------------------
LRESULT CALLBACK SelectDirectoryButtonProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SETTEXT: 
		if (! (strcmp ((char *)lParam, stringSelect) == 0))
			return false;
		break;
	
	case WM_LBUTTONUP:
	case WM_RBUTTONUP: {
		TCHAR mode[256];
		GetWindowText (hwnd, mode, 256);
		if (!VSTGUI_STRCMP (mode, TEXT(stringSelect)))
		{
			bFolderSelected = true;
			TCHAR oldDirPath[kPathMax];
			CommDlg_OpenSave_GetFolderPath (GetParent (hwnd), oldDirPath, kPathMax);
			// you need a lot of tricks to get name of currently selected folder:
			// the following call of the original windows procedure causes the
			// selected folder to open and after that you can retrieve its name
			// by calling ..._GetFolderPath (...)
			CallWindowProc ((WNDPROC)fpOldSelectDirectoryButtonProc, hwnd, message, wParam, lParam);
			CommDlg_OpenSave_GetFolderPath (GetParent (hwnd), selDirPath, kPathMax);

			if (1) // consumers like it like this
			{
				if (VSTGUI_STRCMP (oldDirPath, selDirPath) == 0 || selDirPath [0] == 0)
				{
					// the same folder as the old one, means nothing selected: close
					bFolderSelected = true;
					bDidCancel = false;
					PostMessage (GetParent (hwnd), WM_CLOSE, 0, 0);
					return false;
				}
				else
				{
					// another folder is selected: browse into it
					bFolderSelected = false;
					return true;
				}
			}
			else // original code
			{
				if (VSTGUI_STRCMP (oldDirPath, selDirPath) == 0 || selDirPath [0] == 0)
				{
					// the same folder as the old one, means nothing selected: stay open
					bFolderSelected = false;
					return true;
				}
			}
		}

		bDidCancel = false;
		PostMessage (GetParent (hwnd), WM_CLOSE, 0, 0); 
		return false;
	} break;
	} // end switch

	return CallWindowProc ((WNDPROC)fpOldSelectDirectoryButtonProc, hwnd, message, wParam, lParam);
}

//-----------------------------------------------------------------------------
static void showPathInWindowTitle (HWND hParent, LPOFNOTIFY lpon)
{
	#define WINDOWTEXTSIZE 260 + 64
	OPENFILENAME *ofn = lpon->lpOFN;
	TCHAR text[WINDOWTEXTSIZE];
	TCHAR *p;
	size_t len;

	// Put the path into the Window Title
	if (lpon->lpOFN->lpstrTitle)
		VSTGUI_STRCPY (text, lpon->lpOFN->lpstrTitle);
	else
	{
		TCHAR *pp;

		GetWindowText (hParent, text, WINDOWTEXTSIZE);
		pp = VSTGUI_STRRCHR (text, '-');
		if (pp)
			*--pp = 0;
	}

	p = VSTGUI_STRCAT (text, TEXT(" - ["));
	p = text;
	len = VSTGUI_STRLEN (text); 
	p += len;
	len = WINDOWTEXTSIZE - len - 2;
	CommDlg_OpenSave_GetFolderPath (hParent, p, len);
	VSTGUI_STRCAT (text, TEXT("]"));
	SetWindowText (hParent, text);
}

//------------------------------------------------------------------------
UINT_PTR APIENTRY WinSaveHook (HWND hdlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_NOTIFY: {
		LPOFNOTIFY lpon = (LPOFNOTIFY)lParam; 
		if (!lpon)
			break;

		switch (lpon->hdr.code)
		{
		case CDN_FOLDERCHANGE: 
			showPathInWindowTitle (GetParent (hdlg), lpon);
			break;
		}
	} break;
	} // end switch

	return 0;
}
#endif

#endif // !__LP64__
