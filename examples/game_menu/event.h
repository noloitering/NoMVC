#include "../../src/Controller.h"
#include "../include/NoGUI/src/GUI.h"

// TODO: represent pages and/or events and/or elements as enums
const std::map< std::string, Vector2 > map169 = {
	{"3840 x 2160 UHD", (Vector2){3840, 2160}},
	{"2560 x 1440 HD", (Vector2){2560, 1440}},
	{"1920 x 1080 HD", (Vector2){1920, 1080}},
	{"1280 x 720 HD", (Vector2){1280, 720}},
	{" 854 x 480 SD", (Vector2){854, 480}},
	{" 640 x 360 SD", (Vector2){640, 360}},
	{" 426 x 240 LD", (Vector2){426, 240}},
};

const std::map< std::string, Vector2 > map329 = {
	{"7680 x 2160 UHD", (Vector2){7680, 2160}},
	{"5120 x 1440 HD", (Vector2){5120, 1440}},
	{"3840 x 1080 HD", (Vector2){3840, 1080}},
	{"2560 x 720 HD", (Vector2){2560, 720}},
	{"1708 x 480 SD", (Vector2){1708, 480}},
	{"1280 x 360 SD", (Vector2){1280, 360}},
	{" 852 x 240 LD", (Vector2){852, 240}},
};

const std::map< std::string, Vector2 > map219 = {
	{"5120 x 2160 UHD", (Vector2){7680, 2160}},
	{"3440 x 1440 HD", (Vector2){3440, 1440}},
	{"2560 x 1080 HD", (Vector2){2560, 1080}},
};

const std::map< std::string, Vector2 > map1610 = {
	{"1920 x 1200 HD", (Vector2){7680, 2160}},
	{"1680 x 1050 HD", (Vector2){7680, 2160}},
	{"1440 x 900 HD", (Vector2){7680, 2160}},
	{"1280 x 800 HD", (Vector2){5120, 1440}},
	{"1152 x 720 HD", (Vector2){3840, 1080}},
	{"1024 x 640 SD", (Vector2){1280, 720}},
	{" 768 x 480 SD", (Vector2){1708, 480}},
	{" 640 x 400 SD", (Vector2){1280, 360}},
	{" 320 x 200 LD", (Vector2){852, 240}},
};

const std::map< std::string, Vector2 > map43 = {
	{"1920 x 1440 HD", (Vector2){7680, 2160}},
	{"1600 x 1200 HD", (Vector2){7680, 2160}},
	{"1440 x 1080 HD", (Vector2){7680, 2160}},
	{"1280 x 960 HD", (Vector2){7680, 2160}},
	{"1024 x 768 HD", (Vector2){5120, 1440}},
	{" 960 x 720 HD", (Vector2){3840, 1080}},
	{" 800 x 600 SD", (Vector2){1280, 720}},
	{" 640 x 480 SD", (Vector2){1708, 480}},
	{" 400 x 300 SD", (Vector2){1280, 360}},
	{" 320 x 240 LD", (Vector2){852, 240}},
};

const std::map< std::string, int > mapFPS = {
	{"144fps UHD Gaming", 144},
	{"120fps UHD Gaming", 120},
	{" 90fps HD Gaming", 90},
	{" 72fps UHD Cinema", 72},
	{" 60fps HD Gaming", 60},
	{" 48fps HD Cinema", 48},
	{" 30fps SD Gaming", 30},
	{" 24fps SD Cinema", 24}
};

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
	if ( elem->getInner() == "Anti Aliasing" )
	{
		if ( elem->getFocus() )
		{
			elem->recol(GREEN, LIME);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x;
			}
			config.flags |= FLAG_MSAA_4X_HINT;
		}
		else
		{
			elem->recol(RED, MAROON);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x * -1;
			}
			config.flags &= FLAG_MSAA_4X_HINT;
		}
	}
	else if ( elem->getInner() == "Fullscreen" )
	{
		if ( elem->getFocus() )
		{
			elem->recol(GREEN, LIME);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x;
			}
			config.flags |= FLAG_FULLSCREEN_MODE;
		}
		else
		{
			elem->recol(RED, MAROON);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x * -1;
			}
			config.flags &= ~FLAG_FULLSCREEN_MODE;
		}
	}
	else if ( elem->getInner() == "Vsync" )
	{
		if ( elem->getFocus() )
		{
			elem->recol(GREEN, LIME);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x;
			}
			config.flags |= FLAG_VSYNC_HINT;
		}
		else
		{
			elem->recol(RED, MAROON);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x * -1;
			}
			config.flags &= ~FLAG_VSYNC_HINT;
		}
	}
	else if ( elem->getTag() == "ToggleFF" )
	{
		if ( elem->getFocus() )
		{
			elem->recol(GREEN, LIME);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x;
			}
		}
		else
		{
			elem->recol(RED, MAROON);
			if ( elem->components )
			{
				elem->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = elem->styling().radius.x * -1;
			}
		}
	}
	else if ( elem->getTag() == "FPSOption" )
	{
		config.fps = mapFPS.at(elem->getInner());
	}
	else if ( elem->getTag() == "AspectOption" )
	{
		std::shared_ptr< NoGUI::Element > resDrop = overlay->getPage(6)->getElements("Res").at(0);
		if ( resDrop )
		{
			NoGUI::CDropDown resDown = resDrop->components->getComponent< NoGUI::CDropDown >();
			if ( resDown.options )
			{
				resDown.options->clearElements();
				resDown.options->update();
			
				if ( elem->getInner() == "16:9" )
				{
					for (auto entry = map169.rbegin(); entry != map169.rend(); ++entry)
					{
						resDown.options->addElement< NoGUI::Button >("ResOption", entry->first);
					}
					resDown.options->update();
				}
				else if ( elem->getInner() == "32:9" )
				{
					for (auto entry = map329.rbegin(); entry != map329.rend(); ++entry)
					{
						resDown.options->addElement< NoGUI::Button >("ResOption", entry->first);
					}
					resDown.options->update();
				}
				else if ( elem->getInner() == "21:9" )
				{
					for (auto entry = map219.rbegin(); entry != map219.rend(); ++entry)
					{
						resDown.options->addElement< NoGUI::Button >("ResOption", entry->first);
					}
					resDown.options->update();
				}
				else if ( elem->getInner() == "16:10" )
				{
					for (auto entry = map1610.rbegin(); entry != map1610.rend(); ++entry)
					{
						resDown.options->addElement< NoGUI::Button >("ResOption", entry->first);
					}
					resDown.options->update();
				}
				else if ( elem->getInner() == "4:3" )
				{
					for (auto entry = map43.rbegin(); entry != map43.rend(); ++entry)
					{
						resDown.options->addElement< NoGUI::Button >("ResOption", entry->first);
					}
					resDown.options->update();
				}
			}
		}
	}
	else if ( elem->getInner() == "Join" )
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
		overlay->getPage(6)->setActive(true);
		std::vector< std::shared_ptr< NoGUI::Element > > AAToggles = overlay->getPage(6)->getElements("ToggleAA");
		std::vector< std::shared_ptr< NoGUI::Element > > vToggles = overlay->getPage(6)->getElements("ToggleV");
		std::vector< std::shared_ptr< NoGUI::Element > > fsToggles = overlay->getPage(6)->getElements("ToggleFS");
		for (auto element : AAToggles)
		{
			if ( getAA() )
			{
				element->setFocus(true);
				element->recol(GREEN, LIME);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x;
				}
			}
			else
			{
				element->setFocus(false);
				element->recol(RED, MAROON);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x * -1;
				}
			}
		}
		for (auto element : fsToggles)
		{
			if ( isFull() )
			{
				element->setFocus(true);
				element->recol(GREEN, LIME);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x;
				}
			}
			else
			{
				element->setFocus(false);
				element->recol(RED, MAROON);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x * -1;
				}
			}
		}
		for (auto element : vToggles)
		{
			if ( isSynced() )
			{
				element->setFocus(true);
				element->recol(GREEN, LIME);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x;
				}
			}
			else
			{
				element->setFocus(false);
				element->recol(RED, MAROON);
				if ( element->components )
				{
					element->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = element->styling().radius.x * -1;
				}
			}
		}
	}
	else if ( elem->getInner() == "Play Offline" )
	{
		config.backCol = BLACK;
		SetTargetFPS(config.fps);
		std::shared_ptr< NoGUI::Element > aspectR = overlay->getPage(6)->getElements("AspectR").at(0);
		std::shared_ptr< NoGUI::Element > res = overlay->getPage(6)->getElements("Res").at(0);
		const std::string&  aspectVal = aspectR->getInner();
		if ( aspectVal == "16:9" )
		{
			setRes(map169.at(res->getInner()));
		}
		else if ( aspectVal == "32:9" )
		{
			setRes(map329.at(res->getInner()));
		}
		else if ( aspectVal == "21:9" )
		{
			setRes(map219.at(res->getInner()));
		}
		else if ( aspectVal == "16:10" )
		{
			setRes(map1610.at(res->getInner()));
		}
		else if ( aspectVal == "4:3" )
		{
			setRes(map43.at(res->getInner()));
		}
		setFlags(config.flags);
		for (size_t i=0; i < overlay->size(); i++)
		{
			overlay->getPage(i)->setActive(false);
		}
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