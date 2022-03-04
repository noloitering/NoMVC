#include "menu.h"

int main(int argc, char ** argv)
{
	// Controller
	std::shared_ptr< NoMVC::Controller > game = std::make_shared< NoMVC::Controller >();
	loadAssets(game);
	// View
	std::shared_ptr< Menu > menu = std::make_shared< Menu >(game.get(), game->getWindow());
	game->changeScene(menu);
	// GUI
	std::shared_ptr< MenuGUI > GUI = std::make_shared< MenuGUI >();
	GUI->initialize(game->assets, menu);
	menu->addModel(GUI);
	// Run
	game->sfx->stream(game->assets->get< Music >("title"), false);
	int res = game->run();

	return res;
}