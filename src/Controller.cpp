#include "Controller.h"

NoMVC::Controller::Controller(const WindowConfig& config, std::shared_ptr< NoMEM::MEMManager > mem, std::shared_ptr< NoSFX::AudioManager > sound, bool start)
{
	scene = std::make_shared< View >(this, config);
	assets = mem;
	sfx = sound;
	if ( start )
	{
		startup();
	}
}

void NoMVC::Controller::startup(const char* title)
{
	if ( scene == nullptr )
	{
		scene = std::make_shared< View >(this, WindowConfig());
	}
	const WindowConfig& config = scene->getWindow();
	InitWindow(config.width, config.height, title);
	SetTargetFPS(config.fps);
	
	if ( assets == nullptr )
	{
		assets = std::make_shared< NoMEM::MEMManager >();
	}
	if ( sfx == nullptr )
	{
		sfx = std::make_shared< NoSFX::AudioManager >();
	}
}

int NoMVC::Controller::run()
{
	while ( !WindowShouldClose() )
	{
		sfx->update();
		for (std::shared_ptr< Model > model : models)
		{
			model->update();
		}
		BeginDrawing();
		ClearBackground(scene->getWindow().backCol);
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

int NoMVC::Controller::removeModel(size_t index)
{
	models.erase(models.begin() + index);
	
	return models.size();
}

void NoMVC::Controller::addModel(std::shared_ptr< Model > newModel)
{
	models.push_back(newModel);
}