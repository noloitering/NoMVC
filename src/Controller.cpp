#include "Controller.h"

NoMVC::Controller::Controller()
{
	InitWindow(window.width, window.height, "Client App");
	SetTargetFPS(window.fps);

	scene = std::make_shared< View >(this, window);
//	scene->overlay.addListener(scene);
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
		assets.clear();
		CloseWindow();
	}
	
	return 0;
}

NoMVC::WindowConfig NoMVC::Controller::getWindow()
{
	
	return window;
}

void NoMVC::Controller::changeWindow(const NoMVC::WindowConfig& newWindow)
{
	window = newWindow;
}