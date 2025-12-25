#pragma once

#include "View.h"
#include "../NoMEM/src/NoMEM.h"
#include "../NoSFX/src/Audio.h"

namespace NoMVC
{ 
	class Controller
	{
	friend class View;
	friend std::vector< std::shared_ptr< Model > > NoMVC::View::getModels();
	friend std::shared_ptr< Model > NoMVC::View::getModel(size_t index);
	private:
		std::shared_ptr< View > scene;
		WindowConfig window;
	protected:
		std::vector< std::shared_ptr< Model > > models;
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
		virtual int removeModel(size_t index);
		virtual void addModel(std::shared_ptr< Model > newModel);
	};
}