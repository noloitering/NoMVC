#pragma once

#include "View.h"
#include "../NoMEM/src/NoMEM.h"

namespace NoMVC
{ 
	class Controller
	{
	private:
		std::shared_ptr< View > scene;
		WindowConfig window;
	public:
		NoMEM::MEMManager assets;
		Controller();
		MouseCursor cursor = MOUSE_CURSOR_DEFAULT;
		std::shared_ptr< View > currentScene();
		std::shared_ptr< View > changeScene(std::shared_ptr< NoMVC::View > newScene);
		NoMVC::WindowConfig getWindow();
		int run();
		int quit();
		void changeWindow(const WindowConfig& newWindow);
	};
}