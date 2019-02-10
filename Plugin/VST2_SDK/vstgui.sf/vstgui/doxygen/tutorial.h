/**
@page tutorial Tutorial

This tutorial should give you a brief overview on how to get started using VSTGUI.

- @ref vstintegration @n
- @ref addingviewsandcontrols @n
- @ref Getting notification of control changes @n
- @ref Creating custom controls and views @n

@section vstintegration VST Integration

To add a user interface to a VST Plug-In with VSTGUI is quiet simple.

Create a new class which inherite from AEffGUIEditor. Overwrite AEffGUIEditor::open and AEffGUIEditor::close.
@code
class MyEditor : public AEffGUIEditor
{
public:
	bool open (void* ptr);
	void close ();
};
@endcode

In MyEditor::open you create the CFrame.
@code
bool MyEditor::open (void* ptr)
{
	CRect frameSize (0, 0, 300, 300);
	frame = new CFrame (frameSize, ptr, this);
	return true;
}
@endcode

In MyEditor::close you need to delete the CFrame
@code
void MyEditor::close ()
{
	delete frame;
	frame = 0;
}
@endcode

Now you have your own editor for a VST Plug-In. Now you need to add controls to it.

@section addingviewsandcontrols Adding views and controls

Most controls provided with VSTGUI use bitmaps. So you need to know how to load and use bitmaps in VSTGUI.
To load a bitmap, you just need to use the CBitmap class.

*/
