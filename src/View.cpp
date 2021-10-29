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
		ClearBackground(RAYWHITE);
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

std::shared_ptr< Model > NoMVC::View::addModel()
{
	models.push_back(std::make_shared< Model >(newModel));
	
	return models[models.size--];
}

std::shared_ptr< Model > NoMVC::View::getModel(size_t index)
{
	
	return models[index];
}

int NoMVC::View::removeModel(size_t index)
{
	models[index] = nullptr;
	
	return models.size();
}