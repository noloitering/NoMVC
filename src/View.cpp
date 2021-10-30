#include "View.h"
#include "Controller.h"

void NoMVC::View::update()
{
	for (auto model : models)
	{
		model->update();
	}
}

void NoMVC::View::render()
{
	BeginDrawing();
		ClearBackground(config.backCol);
		for (auto model : models)
		{
			model->render();
		}
    EndDrawing();
}

void NoMVC::View::run()
{
	update();
	render();
}

void NoMVC::View::cleanup()
{
	for (auto model : models )
	{
		model = nullptr;
	}
}

void NoMVC::View::addModel(std::shared_ptr< Model > newModel)
{
	models.push_back(newModel);
}

std::shared_ptr< NoMVC::Model > NoMVC::View::getModel(size_t index)
{
	
	return models[index];
}

int NoMVC::View::removeModel(size_t index)
{
	models.erase(models.begin() + index);
	
	return models.size();
}