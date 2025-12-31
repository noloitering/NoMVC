#include "Controller.h"

NoMVC::Controller::Controller(std::shared_ptr< NoMEM::MEMManager > mem, std::shared_ptr< NoSFX::AudioManager > sound, bool start)
{
	assets = mem;
	sfx = sound;
	if ( start )
	{
		startup();
	}
}

NoMVC::Controller::Controller(const NoMVC::WindowConfig& config, std::shared_ptr< NoMEM::MEMManager > mem, std::shared_ptr< NoSFX::AudioManager > sound, bool start)
{
	changeWindow(config, false);
	assets = mem;
	sfx = sound;
	if ( start )
	{
		startup();
	}
}

void NoMVC::Controller::startup(const char* title)
{
	InitWindow(window.width, window.height, title);
	SetTargetFPS(window.fps);

	if ( assets == nullptr )
	{
		assets = std::make_shared< NoMEM::MEMManager >();
	}
	if ( sfx == nullptr )
	{
		sfx = std::make_shared< NoSFX::AudioManager >();
	}
	if ( scene == nullptr )
	{
		scene = std::make_shared< View >(this, window);
	}
}

int NoMVC::Controller::run()
{
	while ( !WindowShouldClose() )
	{
		sfx->update();
		for (int i=0; i < models.size(); i++)
		{
			models.at(i)->update();
		}
		BeginDrawing();
		ClearBackground(window.backCol);
		scene->run();
		EndDrawing();
	}
	quit();
	
	return 0;
}

std::shared_ptr< NoMVC::View > NoMVC::Controller::currentScene()
{
	
	return scene;
}

void NoMVC::Controller::changeScene(std::shared_ptr< NoMVC::View > newScene)
{
	scene = newScene;
}

int NoMVC::Controller::quit()
{
	if ( !WindowShouldClose() )
	{
		assets->clear();
		CloseWindow();
	}
	
	return 0;
}

NoMVC::WindowConfig NoMVC::Controller::getWindow()
{
	
	return window;
}

void NoMVC::Controller::changeWindow(const NoMVC::WindowConfig& newWindow, bool set)
{
	window = newWindow;
	if ( set )
	{
		SetWindowSize(newWindow.width, newWindow.height);
	}
}

int NoMVC::Controller::removeModel(size_t index)
{
	models.erase(models.begin() + index);
	
	return models.size();
}

void NoMVC::Controller::addModel(std::shared_ptr< Model > newModel)
{
	models.push_back(newModel);
}