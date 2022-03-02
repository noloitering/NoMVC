#include "Controller.h"

NoMVC::Controller::Controller(std::shared_ptr< NoMEM::MEMManager > mem, std::shared_ptr< NoSFX::AudioManager > sound, bool start)
{
	assets = mem;
	sfx = sound;
	if ( start )
	{
		init();
	}
}

NoMVC::Controller::Controller(const NoMVC::WindowConfig& config, std::shared_ptr< NoMEM::MEMManager > mem, std::shared_ptr< NoSFX::AudioManager > sound, bool start)
{
	changeWindow(config, false);
	assets = mem;
	sfx = sound;
	if ( start )
	{
		init();
	}
}

void NoMVC::Controller::init(const std::string& title)
{
	InitWindow(window.width, window.height, title.c_str());
	SetTargetFPS(window.fps);

	if ( assets == nullptr )
	{
		assets = std::make_shared< NoMEM::MEMManager >();
	}
	if ( sfx == nullptr )
	{
		sfx = std::make_shared< NoSFX::AudioManager >();
	}
	scene = std::make_shared< View >(this, window);
	scene->update();
}

int NoMVC::Controller::run()
{
	while ( !WindowShouldClose() )
	{
		sfx->update();
		scene->run();
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
	scene->cleanup();
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