#ifndef __vstkeycode__
#define __vstkeycode__

#ifndef __aeffectx__
// define VstKeyCode for non VST useage

//---Structure and enum used for keyUp/keyDown-----
struct VstKeyCode
{
	long character;
	unsigned char virt;     // see enum VstVirtualKey
	unsigned char modifier; // see enum VstModifierKey
};

//---Used by member virt of VstKeyCode-------------
enum VstVirtualKey 
{
	VKEY_BACK = 1, 
	VKEY_TAB, 
	VKEY_CLEAR, 
	VKEY_RETURN, 
	VKEY_PAUSE, 
	VKEY_ESCAPE, 
	VKEY_SPACE, 
	VKEY_NEXT, 
	VKEY_END, 
	VKEY_HOME, 

	VKEY_LEFT, 
	VKEY_UP, 
	VKEY_RIGHT, 
	VKEY_DOWN, 
	VKEY_PAGEUP, 
	VKEY_PAGEDOWN, 

	VKEY_SELECT, 
	VKEY_PRINT, 
	VKEY_ENTER, 
	VKEY_SNAPSHOT, 
	VKEY_INSERT, 
	VKEY_DELETE, 
	VKEY_HELP, 
	VKEY_NUMPAD0, 
	VKEY_NUMPAD1, 
	VKEY_NUMPAD2, 
	VKEY_NUMPAD3, 
	VKEY_NUMPAD4, 
	VKEY_NUMPAD5, 
	VKEY_NUMPAD6, 
	VKEY_NUMPAD7, 
	VKEY_NUMPAD8, 
	VKEY_NUMPAD9, 
	VKEY_MULTIPLY, 
	VKEY_ADD, 
	VKEY_SEPARATOR, 
	VKEY_SUBTRACT, 
	VKEY_DECIMAL, 
	VKEY_DIVIDE, 
	VKEY_F1, 
	VKEY_F2, 
	VKEY_F3, 
	VKEY_F4, 
	VKEY_F5, 
	VKEY_F6, 
	VKEY_F7, 
	VKEY_F8, 
	VKEY_F9, 
	VKEY_F10, 
	VKEY_F11, 
	VKEY_F12, 
	VKEY_NUMLOCK, 
	VKEY_SCROLL,

	VKEY_SHIFT,
	VKEY_CONTROL,
	VKEY_ALT,

	VKEY_EQUALS
};

//---Used by member modifier of VstKeyCode---------
enum VstModifierKey
{
	MODIFIER_SHIFT     = 1<<0, // Shift
	MODIFIER_ALTERNATE = 1<<1, // Alt
	MODIFIER_COMMAND   = 1<<2, // Control on Mac
	MODIFIER_CONTROL   = 1<<3  // Ctrl on PC, Apple on Mac
};
#endif

#endif
