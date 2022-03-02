#pragma once

#include "View.h"
#include "../NoMEM/src/NoMEM.h"
#include "../NoSFX/src/Audio.h"

namespace NoMVC
{ 
	class Controller
	{
	private:
		std::shared_ptr< View > scene;
		WindowConfig window;
	public:
		std::shared_ptr< NoMEM::MEMManager > assets;
		std::shared_ptr< NoSFX::AudioManager > sfx;
		Controller(std::shared_ptr< NoMEM::MEMManager > mem=nullptr, std::shared_ptr< NoSFX::AudioManager > sound=nullptr, bool start=true);
		Controller(const WindowConfig& config, std::shared_ptr< NoMEM::MEMManager > mem=nullptr, std::shared_ptr< NoSFX::AudioManager > sound=nullptr, bool start=true);
		void init(const std::string& title="Client App");
		MouseCursor cursor = MOUSE_CURSOR_DEFAULT;
		std::shared_ptr< View > currentScene();
		void changeScene(std::shared_ptr< NoMVC::View > newScene);
		WindowConfig getWindow();
		int run();
		int quit();
		void changeWindow(const WindowConfig& newWindow, bool set=true);
	};
}