/**
@page tutorial_getting_started Getting Started Tutorial

This tutorial should give you a brief overview on how to get started using VSTGUI.

- @ref vstintegration @n
- @ref addingviewsandcontrols @n
- @ref controllistener @n

@section vstintegration VST Integration

To add a user interface to a VST Plug-In with VSTGUI is quiet simple.

Create a new class which inherits from AEffGUIEditor. Overwrite AEffGUIEditor::open and AEffGUIEditor::close.
@code
class MyEditor : public AEffGUIEditor
{
public:
	MyEditor (void* ptr) : AEffGUIEditor (ptr) {}

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

Now you just need to set the editor of your VST Plug-In to a new instance of MyEditor.
@code
// somewhere in the constructor of your VST Plug-In
setEditor (new MyEditor (this));
@endcode

So you have your own editor for a VST Plug-In. Now you need to add controls to it.

@section addingviewsandcontrols Adding views and controls
- @ref loading_bitmaps @n
- @ref adding_views @n
- @ref adding_knob @n
@subsection loading_bitmaps Loading images
Most controls provided with VSTGUI use images. So you need to know how to load and use images in VSTGUI.
To load an image, you just need to use the CBitmap class.
@code
CBitmap* bitmap = new CBitmap ("MyBitmap.png");
@endcode
The image "MyBitmap.png" must be defined in the .rc file on Windows like this :
@code
MyBitmap.png        DATA  DISCARDABLE     "MyBitmap.png"
@endcode
On Mac OS X the image must be inside the Resources folder of the vst bundle.
@subsection adding_views Creating views and adding them to the frame
Now that we have loaded an image, we want this image to be shown in our editor.
The simplest way is to use the CView class, which is the base of all view and control classes.
@code
CView* myView = new CView (CRect (0, 0, bitmap->getWidth (), bitmap->getHeight ()));
myView->setBackground (bitmap);
@endcode
To actually get this shown, we need to add this view to the CFrame object created earlier.
@code
frame->addView (myView);
@endcode
So after we have setup all views we can get rid of our image as all views will remember the image by its own.
@code
bitmap->forget ();
@endcode
Now lets see how this looks as a complete example :
@code
bool MyEditor::open (void* ptr)
{
	CRect frameSize (0, 0, 300, 300);
	frame = new CFrame (frameSize, ptr, this);
	CBitmap* bitmap = new CBitmap ("MyBitmap.png");
	CView* myView = new CView (CRect (0, 0, bitmap->getWidth (), bitmap->getHeight ()));
	myView->setBackground (bitmap);
	frame->addView (myView);
	bitmap->forget ();
	return true;
}
@endcode

To only have an image shown in our editor is a little bit lame. We want to have some controls the user can interact with.

@subsection adding_knob Creating a knob control

VSTGUI provides some basic controls you can use. As an example we use the CKnob control. The CKnob control takes two images, the background and the handle. The background as its name suggest is always drawn as the background of this control, while the handle is drawn at the position of the value of this control. See VSTGUI::CKnob for more info.

Now lets see how to create such a knob:
@code
CKnob* knob = new CKnob (r, 0, 0, background, handle, CPoint (0, 0));
@endcode

As you can see there are some parameters set to zero. Ignore them for a moment. I will talk about it later. 
If you add this knob to the frame and test the interface you will see that if you press the mouse button over this control and move the mouse, the handle of the knob is also moving. Great, we have something to play with in the editor.

The complete example :
@code
bool MyEditor::open (void* ptr)
{
	CRect frameSize (0, 0, 300, 300);
	frame = new CFrame (frameSize, ptr, this);
	CBitmap* background = new CBitmap ("KnobBackground.png");
	CBitmap* handle = new CBitmap ("KnobHandle.png");
	CRect r (0, 0, background->getWidth (), background->getHeight ());
	CKnob* knob = new CKnob (r, 0, 0, background, handle, CPoint (0, 0));
	background->forget ();
	handle->forget ();
	frame->addView (knob);
	return true;
}
@endcode

@section controllistener Getting notification of control changes 

So now we have a knob in our editor. We'd like to know when the user uses this control.

@subsection TheCControlListener The CControlListener
This is done with the CControlListener interface. Every control in VSTGUI can have one listener. When the value of the control has changed the listener is notified.

First we need a CControlListener. The easiest way is to inherit our editor not only from AEffGUIEditor but also from CControlListener :
@code
class MyEditor : public AEffGUIEditor, public CControlListener
{
public:
	MyEditor (void* ptr) : AEffGUIEditor (ptr) {}

	// from AEffGUIEditor
	bool open (void* ptr);
	void close ();

	// from CControlListener
	void valueChanged (CControl* pControl);
};
@endcode

Now we can use our editor as the listener parameter in the CKnob constructor.
@code
CKnob* knob = new CKnob (r, this, 0, background, handle, CPoint (0, 0));
@endcode

We only need to implement the valueChanged method and we know when the user twiddles our knob.
@code
void MyEditor::valueChanged (CControl* pControl)
{
	// pControl is our knob in this example
}
@endcode

@subsection ControlIdentification Control identification

With one control it's fairly easy to know which control was used by the user. If there are more controls in our editor, to know which control was used is done by the tag of the control. So if we add two knobs to the frame we gave them different tags :
@code
CKnob* knob1 = new CKnob (r, this, 0, background, handle, CPoint (0, 0));
CKnob* knob2 = new CKnob (r, this, 1, background, handle, CPoint (0, 0));
@endcode
Now in our valueChanged method we can differentiate between the controls :
@code
void MyEditor::valueChanged (CControl* pControl)
{
	long tag = pControl->getTag ();
	if (tag == 0)
	{
		// the first knob
	}
	else if (tag == 1)
	{
		// the second knob
	}
}
@endcode

For a complete example have a look at the tutorial project included with VSTGUI.

*/
