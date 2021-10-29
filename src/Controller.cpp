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
		scene->update();
		BeginDrawing();
			scene->overlay.render();
			ClearBackground(RAYWHITE);
		EndDrawing();
	}
	quit();
	
	return 0;
}

std::shared_ptr< View > NoMVC::Controller::changeScene(View newScene)
{
	scene = std::make_shared< View >(newScene);
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

NoMVC::WindowConfig getWindow()
{
	
	return window;
}

void NoMVC::changeWindow(const NoMVC::WindowConfig newWindow)
{
	window = newWindow;
}