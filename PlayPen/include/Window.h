#ifndef WINDOW_H
#define WINDOW_H

#include "PlayPen.h"

#include "OgreEntity.h"
#include "OgreRenderSystem.h"
#include "OgreRenderWindow.h"
#include "OgreRoot.h"
#include "OgreStringConverter.h"
#include "OgreWindowEventUtilities.h"

#include <OIS/OIS.h>

#include "QuickGUI.h"

class Window :
	public Ogre::WindowEventListener,
	public OIS::KeyListener,
	public OIS::MouseListener
{
public:
	Window(PlayPen* e, Ogre::RenderWindow* w);
	virtual ~Window();

	/* KeyListener Callbacks */
	bool keyPressed(const OIS::KeyEvent &arg);
	bool keyReleased(const OIS::KeyEvent &arg);

	/* MouseListener Callbacks */
	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	/* Window Event Callbacks */
	void windowMoved(Ogre::RenderWindow* rw);
	virtual void windowResized(Ogre::RenderWindow* rw);
	virtual void windowClosed(Ogre::RenderWindow* rw);
	void windowFocusChange(Ogre::RenderWindow* rw);

	void update(float timeSinceLastFrame);

protected:
	PlayPen*				mSkinSetEditor;

	Ogre::Root*					mOgreRoot;
	Ogre::RenderSystem*			mRenderSystem;
	Ogre::RenderWindow*			mRenderWindow;
	Ogre::SceneManager*			mSceneManager;
	Ogre::Camera*				mCamera;
	Ogre::Viewport*				mViewport;

	OIS::InputManager*			mInputManager;
	OIS::Keyboard*				mKeyboard;
	OIS::Mouse*					mMouse;

	QuickGUI::GUIManager*		mGUIManager;

private:
	void _initializeOIS();

};

#endif
