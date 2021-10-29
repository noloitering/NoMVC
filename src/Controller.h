#pragma once

#include "View.h"
//#include "Asset.h"
#include "NoMEM.h"

namespace NoMVC
{ 
	class Controller
	{
	private:
		std::shared_ptr< View > scene;
		WindowConfig window;
	public:
		NoMEM::MEMManager assets;
		GameEngine();
		MouseCursor cursor = MOUSE_CURSOR_DEFAULT;
		std::shared_ptr< View > currentScene();
		std::shared_ptr< View > changeScene(const View& newScene);
		NoMVC::WindowConfig getWindow();
		int run();
		int quit();
		void changeWindow(const WindowConfig& newWindow);
	};
}