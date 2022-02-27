#include "Controller.h"

NoMVC::Controller::Controller(std::shared_ptr< NoMEM::MEMManager > mem, bool start)
{
	if ( mem == nullptr )
	{
		assets = std::make_shared< NoMEM::MEMManager >();
	}
	else
	{
		assets = mem;
	}
	if ( start )
	{
		init();
	}
}

NoMVC::Controller::Controller(const NoMVC::WindowConfig& config, std::shared_ptr< NoMEM::MEMManager > mem, bool start)
{
	changeWindow(config, false);
	if ( mem == nullptr )
	{
		assets = std::make_shared< NoMEM::MEMManager >();
	}
	else
	{
		assets = mem;
	}
	if ( start )
	{
		init();
	}
}

void NoMVC::Controller::init(const std::string& title)
{
	InitWindow(window.width, window.height, title.c_str());
	SetTargetFPS(window.fps);

	scene = std::make_shared< View >(this, window);
	scene->update();
}

int NoMVC::Controller::run()
{
	while ( !WindowShouldClose() )
	{
		scene->run();
	}
	quit();
	
	return 0;
}

std::shared_ptr< NoMVC::View > NoMVC::Controller::currentScene()
{
	
	return scene;
}

std::shared_ptr< NoMVC::View > NoMVC::Controller::changeScene(std::shared_ptr< NoMVC::View > newScene)
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