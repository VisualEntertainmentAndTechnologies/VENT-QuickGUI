#ifndef QUICKGUIRADIOBUTTON_H
#define QUICKGUIRADIOBUTTON_H

#include "QuickGUIWidget.h"

namespace QuickGUI
{
	class _QuickGUIExport RadioButtonDesc :
			public WidgetDesc
	{
	public:
		friend class DescFactory;
	protected:
		RadioButtonDesc();
		virtual ~RadioButtonDesc() {}
	public:

		bool			radiobutton_selected;
		Ogre::String	radiobutton_userHandlers[RADIOBUTTON_EVENT_COUNT];

		/**
		* Returns the class of Desc object this is.
		*/
		virtual Ogre::String getClass() { return "RadioButtonDesc"; }
		/**
		* Returns the class of Widget this desc object is meant for.
		*/
		virtual Ogre::String getWidgetClass() { return "RadioButton"; }

		/**
		* Restore properties to default values
		*/
		virtual void resetToDefault();

		/**
		* Outlines how the desc class is written to XML and read from XML.
		*/
		virtual void serialize(SerialBase* b);
	};

	class _QuickGUIExport RadioButton :
		public Widget
	{
	public:
		// Skin Constants
		static const Ogre::String SELECTED;
		static const Ogre::String SELECTED_DOWN;
		static const Ogre::String SELECTED_OVER;
		static const Ogre::String UNSELECTED;
		static const Ogre::String UNSELECTED_DOWN;
		static const Ogre::String UNSELECTED_OVER;
		// Define Skin Structure
		static void registerSkinDefinition();
	public:
		// This class needs to be able to unselect other RadioButtons in other nodes.
		friend class TreeViewRadioButtonNode;

		friend class WidgetFactory;
	public:

		/**
		* Internal function, do not use.
		*/
		virtual void _initialize(WidgetDesc* d);

		/**
		* Adds a user-defined event handler to this widget.  The difference between this function and the addWidgetEventHandler
		* is that the handlerName gets serialized with the Widget. This means you can defined handlers outside the creation of the
		* GUI Layout, and when the sheet is loaded from disk, all of the handlers will work properly.
		* NOTE: Only 1 user defined Event Handler can be assigned to an Event. Old values will be overwritten.
		* NOTE: A handler of "" essentially removes the handler.
		* NOTE: If no eventHandler exists with the name provided, nothing will happen.
		*/
		void addUserDefinedRadioButtonEventHandler(RadioButtonEvent EVENT, const Ogre::String& handlerName);
		/** Adds an event handler to this widget
			@param
				EVENT Defined widget events, for example: WIDGET_EVENT_SIZE_CHANGED, WIDGET_EVENT_MOUSE_WHEEL, etc.
            @param
                function member function assigned to handle the event.  Given in the form of myClass::myFunction.
				Function must return bool, and take QuickGUI::EventArgs as its parameters.
            @param
                obj particular class instance that defines the handler for this event.  Here is an example:
				addWidgetEventHandler(QuickGUI::WIDGET_EVENT_MOUSE_BUTTON_DOWN,myClass::myFunction,this);
			@note
				Multiple user defined event handlers can be defined for an event.  All added event handlers will be called
				whenever the event is fired.
			@note
				You may see Visual Studio give an error warning such as "error C2660: 'QuickGUI::Widget::addWidgetEventHandler' : function does not take 3 arguments".
				This is an incorrect error message.  Make sure your function pointer points to a function which returns void, and takes parameter "const EventArgs&".
        */
		template<typename T> void addRadioButtonEventHandler(RadioButtonEvent EVENT, void (T::*function)(const EventArgs&), T* obj)
		{
			addRadioButtonEventHandler(EVENT, OGRE_NEW_T(EventHandlerPointer<T>,Ogre::MEMCATEGORY_GENERAL)(function,obj));
		}
		void addRadioButtonEventHandler(RadioButtonEvent EVENT, EventHandlerSlot* function);

		/**
		* Clears the user defined handler associated with the EVENT given. (sets the handlerName to "")
		*/
		void clearUserDefinedRadioButtonEventHandler(RadioButtonEvent EVENT);

		/**
		* Event Handler that executes the appropriate User defined Event Handlers for a given event.
		* Returns true if the event was handled, false otherwise.
		*/
		bool fireRadioButtonEvent(RadioButtonEvent e, EventArgs& args);

		/**
		* Returns true if checked, false otherwise.
		*/
		bool getSelected();
		/**
		* Returns the class name of this Widget.
		*/
		virtual Ogre::String getClass();

		/**
		* Selects the RadioButton.
		*/
		void select();

	public:
		// Here we have to call out any protected Widget set accesors we want to expose

		using Widget::drag;
		using Widget::resize;
		using Widget::setConsumeKeyboardEvents;
		using Widget::setDimensions;
		using Widget::setDragable;
		using Widget::setHeight;
		using Widget::setHorizontalAnchor;
		using Widget::setMaxSize;
		using Widget::setMinSize;
		using Widget::setPosition;
		using Widget::setPositionRelativeToParentClientDimensions;
		using Widget::setResizeFromAllSides;
		using Widget::setResizeFromBottom;
		using Widget::setResizeFromLeft;
		using Widget::setResizeFromRight;
		using Widget::setResizeFromTop;
		using Widget::setScrollable;
		using Widget::setSerialize;
		using Widget::setSize;
		using Widget::setTransparencyPicking;
		using Widget::setVerticalAnchor;
		using Widget::setVisible;
		using Widget::setWidth;

	protected:
		RadioButton(const Ogre::String& name);
		virtual ~RadioButton();

		RadioButtonDesc* mDesc;

		// Event handlers! One List per event per widget
		std::vector<EventHandlerSlot*> mRadioButtonEventHandlers[CHECKBOX_EVENT_COUNT];

		/**
		* Outlines how the widget is drawn to the current render target
		*/
		virtual void onDraw();

		/**
		* Handler defined to implement the button's default natural behavior. (BUTTON_STATE_OVER)
		*/
		void onMouseEnter(const EventArgs& args);
		/**
		* Handler defined to implement the button's default natural behavior. (BUTTON_STATE_DEFAULT)
		*/
		void onMouseLeave(const EventArgs& args);
		/**
		* Handler defined to implement the button's default natural behavior. (BUTTON_STATE_DOWN)
		*/
		void onMouseLeftButtonDown(const EventArgs& args);
		/**
		* Handler defined to implement the button's default natural behavior. (BUTTON_STATE_OVER)
		*/
		void onMouseLeftButtonUp(const EventArgs& args);

		// Updates the SkinElement used for border detection and client area calculations.
		virtual void updateSkinElement();

	private:
	};
}

#endif
