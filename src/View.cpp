#include "View.h"
#include "Controller.h"

using namespace NoMVC;

void View::render()
{
	for (auto model : game->models)
	{
		model->render();
	}
}

void View::run()
{
//	update();
	render();
}

WindowConfig View::getWindow()
{
	
	return config;
}

Vector2 View::getRes()
{
	
	return (Vector2){config.width, config.height};
}

int View::getTargetFPS()
{
	
	return config.fps;
}

unsigned int View::getFlags()
{
	
	return config.flags;
}

bool View::getAA()
{
	
	return (config.flags & FLAG_MSAA_4X_HINT);
}

bool View::isFull()
{
	
	return (config.flags & FLAG_FULLSCREEN_MODE);
}

bool View::isSynced()
{
	
	return (config.flags & FLAG_VSYNC_HINT);
}

Color View::getCol()
{
	
	return config.backCol;
}

std::vector< std::shared_ptr< NoMVC::Model > > NoMVC::View::getModels()
{
	
	return game->models;
}

std::shared_ptr< NoMVC::Model > NoMVC::View::getModel(size_t index)
{
	
	return getModels().at(index);
}


void View::setWindow(const WindowConfig& conf)
{
	setRes(conf.width, conf.height);
	setFPS(conf.fps);
	setFlags(conf.flags);
	setCol(conf.backCol);
}

void View::setRes(int x, int y)
{
	config.width = x;
	config.height = y;
	SetWindowSize(config.width, config.height);
}

void View::setRes(const Vector2& res)
{
	setRes(res.x, res.y);
}

void View::setFPS(int fps)
{
	config.fps = fps;
	SetTargetFPS(config.fps);
}

void View::setFlags(unsigned int flags)
{
	config.flags = flags;
	SetWindowState(config.flags);
}

void View::setAA(bool AA)
{
	if ( AA )
	{
		config.flags |= FLAG_MSAA_4X_HINT;
		SetWindowState(config.flags);
	}
	else
	{
		config.flags &= ~FLAG_MSAA_4X_HINT;
		SetWindowState(config.flags);
	}
}

void View::setFull(bool full)
{
	if ( full )
	{
		config.flags |= FLAG_FULLSCREEN_MODE;
		SetWindowState(config.flags);
	}
	else
	{
		config.flags &= ~FLAG_FULLSCREEN_MODE;
		SetWindowState(config.flags);
	}
}

void View::setSync(bool sync)
{
	if ( sync )
	{
		config.flags |= FLAG_VSYNC_HINT;
		SetWindowState(config.flags);
	}
	else
	{
		config.flags &= ~FLAG_VSYNC_HINT;
		SetWindowState(config.flags);
	}
}

void View::setCol(const Color& col)
{
	config.backCol = col;
}