#include "../../src/Controller.h"
#include "../include/NoGUI/src/GUI.h"

class Menu : public NoMVC::View, public NoGUI::Listener
{
public:
	void addModel(std::shared_ptr< NoMVC::Model > newModel) {NoMVC::View::addModel(newModel);}
	void cleanup() {NoMVC::View::cleanup();}
	int removeModel(size_t index) {NoMVC::View::removeModel(index);}
	void update() {NoMVC::View::update();}
	void render() {NoMVC::View::render();}
	void run() {NoMVC::View::run();}
	void onNotify(std::shared_ptr< NoGUI::Element > elem);
	Menu(NoMVC::Controller* g, NoMVC::WindowConfig conf)
		: NoMVC::View(g, conf) {}
};

void Menu::onNotify(std::shared_ptr< NoGUI::Element > elem)
{
	NoGUI::GUIManager* overlay = dynamic_cast< NoGUI::GUIManager* >(models[0].get());
	if ( elem->getInner() == "Join" )
	{
		overlay->getPage(3)->setActive(false);
		overlay->getPage(2)->setActive(true);
		elem->repos((Vector2){elem->styling().pos.x, 50});
		overlay->getPage(1)->getElement(0)->repos((Vector2){overlay->getPage(1)->getElement(0)->styling().pos.x, elem->styling().pos.y + 8});
	}
	else if ( elem->getInner() == "Play Online" )
	{
		overlay->getPage(0)->setActive(false);
		overlay->getPage(1)->setActive(true);
		overlay->getPage(2)->setActive(true);
	}
	else if ( elem->getInner() == "Settings" )
	{
		overlay->getPage(0)->setActive(false);
		overlay->getPage(4)->setActive(true);
	}
	else if ( elem->getInner() == "Host" )
	{
		overlay->getPage(2)->setActive(false);
		overlay->getPage(3)->setActive(true);
		elem->repos((Vector2){elem->styling().pos.x, 50});
		overlay->getPage(1)->getElement(1)->repos((Vector2){overlay->getPage(1)->getElement(1)->styling().pos.x, elem->styling().pos.y + 8});
	}
	else if ( elem->getInner() == "Back" )
	{
		overlay->setActive(0);
	}
	else if ( elem->getInner() == "Exit" )
	{
		game->quit();
	}
}