#ifndef QUICKGUIEXCEPTION_H
#define QUICKGUIEXCEPTION_H

#include "QuickGUIExportDLL.h"

#include "OgreException.h"
#include "OgrePrerequisites.h"

namespace QuickGUI
{
	class _QuickGUIExport Exception :
		public Ogre::Exception
	{
	public:
		enum ExceptionCodes {
			ERR_FACTORY_NOT_FOUND = (Ogre::Exception::ERR_NOT_IMPLEMENTED + 1),
			ERR_DUPLICATE_FACTORY,
			ERR_INVALID_RENDER_TARGET,
			ERR_INVALID_CHILD,
			ERR_NO_ACTIVE_SHEET,
			ERR_WIDGET_ALREADY_ADDED,
			ERR_INVALID_DESC,
			ERR_UNSUPPORTED_WIDGET,
			ERR_SERIALIZATION,
			ERR_TEXT,
			ERR_SCRIPT_PARSING,
			ERR_SCRIPT_WRITING,
			ERR_SKINNING,
			ERR_FACTORY
/*          ERR_INVALID_STATE,
            ERR_INVALIDPARAMS,
            ERR_RENDERINGAPI_ERROR,
            ERR_DUPLICATE_ITEM,
            ERR_ITEM_NOT_FOUND,
            ERR_FILE_NOT_FOUND,
            ERR_INTERNAL_ERROR,
            ERR_RT_ASSERTION_FAILED, 
			ERR_NOT_IMPLEMENTED
*/        };

		Exception( int number, const Ogre::String& description, const Ogre::String& source );

	protected:
	private:
	};
}

#endif
