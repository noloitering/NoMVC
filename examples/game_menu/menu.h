#include "../../src/Controller.h"
#include "../include/NoGUI/src/GUI.h"
#include "../include/NoECS/src/System.h"

#include "assets.h"
#include "characters.h"

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
	{"5120 x 2160 UHD", (Vector2){5120, 2160}},
	{"3440 x 1440 HD", (Vector2){3440, 1440}},
	{"2560 x 1080 HD", (Vector2){2560, 1080}},
};

const std::map< std::string, Vector2 > map1610 = {
	{"1920 x 1200 HD", (Vector2){1920, 1200}},
	{"1680 x 1050 HD", (Vector2){1680, 1050}},
	{"1440 x 900 HD", (Vector2){1440, 900}},
	{"1280 x 800 HD", (Vector2){1280, 800}},
	{"1152 x 720 HD", (Vector2){1152, 720}},
	{"1024 x 640 SD", (Vector2){1024, 640}},
	{" 768 x 480 SD", (Vector2){768, 480}},
	{" 640 x 400 SD", (Vector2){640, 400}},
	{" 320 x 200 LD", (Vector2){320, 200}},
};

const std::map< std::string, Vector2 > map43 = {
	{"1920 x 1440 HD", (Vector2){1920, 1440}},
	{"1600 x 1200 HD", (Vector2){1600, 1200}},
	{"1440 x 1080 HD", (Vector2){1440, 1080}},
	{"1280 x 960 HD", (Vector2){1280, 960}},
	{"1024 x 768 HD", (Vector2){1024, 768}},
	{" 960 x 720 HD", (Vector2){960, 720}},
	{" 800 x 600 SD", (Vector2){800, 600}},
	{" 640 x 480 SD", (Vector2){640, 480}},
	{" 400 x 300 SD", (Vector2){400, 300}},
	{" 320 x 240 LD", (Vector2){320, 240}},
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
	bool flipSwitch(std::shared_ptr< NoGUI::Element > toggleS, std::shared_ptr< Sound > sound=nullptr);
	Menu(NoMVC::Controller* g, NoMVC::WindowConfig conf)
		: NoMVC::View(g, conf) {}
};

bool Menu::flipSwitch(std::shared_ptr< NoGUI::Element > toggleS, std::shared_ptr< Sound > sound)
{
	if ( sound )
	{
		game->sfx->play(sound);
	}
	if ( toggleS->getFocus() )
	{
		toggleS->recol(GREEN, LIME);
		if ( toggleS->components )
		{
			toggleS->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = toggleS->styling().radius.x;
		}
		
		return true;
	}
	else
	{
		toggleS->recol(RED, MAROON);
		if ( toggleS->components )
		{
			toggleS->components->getComponent< NoGUI::CMultiStyle >().styles.at(0).pos.x = toggleS->styling().radius.x * -1;
		}
		
		return false;
	}
}

void Menu::onNotify(std::shared_ptr< NoGUI::Element > elem)
{
	NoGUI::GUIManager* overlay = dynamic_cast< NoGUI::GUIManager* >(models[0].get());
	if ( dynamic_cast< NoGUI::Button* >(elem.get()) )
	{
		if (elem->getFocus())
		{
			game->sfx->play(game->assets->get< Sound >("click"));
		}
		// Navigation
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
			game->sfx->stopTrack();
			config.backCol = BLACK;
			std::shared_ptr< NoGUI::Element > aspectR = overlay->getPage(6)->getElements("AspectR").at(0);
			std::shared_ptr< NoGUI::Element > res = overlay->getPage(6)->getElements("Res").at(0);
			const std::string&  aspectVal = aspectR->getInner();
			SetTargetFPS(config.fps);
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
			std::shared_ptr< CharSelect > newMenu = std::make_shared< CharSelect >(game, config);
			std::shared_ptr< CharGUI > GUI = std::make_shared< CharGUI >();
			GUI->initialize(game->assets, newMenu);
			newMenu->addModel(GUI);
			update();
			game->changeScene(newMenu);
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
		// Settings
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
	}
	else if ( dynamic_cast< NoGUI::Toggle* >(elem.get()) )
	{
		if ( elem->getInner() == "Anti Aliasing" )
		{
			if ( flipSwitch(elem, game->assets->get< Sound >("switch")) )
			{
				config.flags |= FLAG_MSAA_4X_HINT;
			}
			else
			{
				config.flags &= ~FLAG_MSAA_4X_HINT;
			}
		}
		else if ( elem->getInner() == "Fullscreen" )
		{
			if ( flipSwitch(elem, game->assets->get< Sound >("switch")) )
			{
				config.flags |= FLAG_FULLSCREEN_MODE;
			}
			else
			{
				config.flags &= ~FLAG_FULLSCREEN_MODE;
			}
		}
		else if ( elem->getInner() == "Vsync" )
		{
			if ( flipSwitch(elem, game->assets->get< Sound >("switch")) )
			{
				config.flags |= FLAG_VSYNC_HINT;
			}
			else
			{
				config.flags &= ~FLAG_VSYNC_HINT;
			}
		}
		else if ( elem->getTag() == "ToggleFF" )
		{
			flipSwitch(elem, game->assets->get< Sound >("switch"));
		}
	}
}

class MenuGUI : public NoGUI::GUIManager
{
public:
	MenuGUI()
		: GUIManager(false) {}
	void initialize(std::shared_ptr< NoMEM::MEMManager > assets,  std::shared_ptr< Menu > menu)
	{
		addListener(menu);
		
		Vector2 center = {menu->getWindow().width / 2, menu->getWindow().height / 2};
		Color INVISIBLE = (Color){0, 0, 0, 1};
		Color BACKGROUND = (Color){100, 100, 100, 255};
		
		std::shared_ptr< Font > font = assets->get< Font >("jupiter_crash");
		std::shared_ptr< Texture2D > mainImg = assets->get< Texture2D >("mainBack");
		std::shared_ptr< Texture2D > settingsImg = assets->get< Texture2D >("setBack");
		std::shared_ptr< Texture2D > joinImg = assets->get< Texture2D >("joinBack");
		std::shared_ptr< Texture2D > hostImg = assets->get< Texture2D >("hostBack");
		// image
		NoGUI::CImage mainBack = NoGUI::CImage(mainImg);
		mainBack.cropping = NoGUI::Crop::NONE;
		NoGUI::CImage settingsBack = NoGUI::CImage(settingsImg);
		settingsBack.cropping = NoGUI::Crop::NONE;
		NoGUI::CImage joinBack = NoGUI::CImage(joinImg);
		NoGUI::CImage hostBack = NoGUI::CImage(hostImg);
		// text
		NoGUI::CText titleStyle = NoGUI::CText(font);
		titleStyle.col = PURPLE;
		titleStyle.align = NoGUI::TextAlign::CENTER;
		titleStyle.size = 60;
		NoGUI::CText labelStyle = NoGUI::CText(font);
		labelStyle.col = MAROON;
		labelStyle.align = NoGUI::TextAlign::RIGHT;
		labelStyle.wrap = NoGUI::TextWrap::DOWN;
		labelStyle.margin = (Vector2){0, 0};
		labelStyle.spacing = (Vector2){2, 0};
		labelStyle.size = 35;
		labelStyle.shadow.draw = true;
		labelStyle.shadow.offset = {2, -2};
		NoGUI::CText inputStyle = labelStyle;
		inputStyle.shadow.draw = false;
		inputStyle.size = 30;
		NoGUI::CText buttonStyle = inputStyle; // copy
		buttonStyle.align = NoGUI::TextAlign::CENTER;
		NoGUI::CText dropStyle = buttonStyle; // copy
		dropStyle.spacing = {1, 0};
		dropStyle.col = BLACK;
		NoGUI::CText joinText = inputStyle; // copy
		joinText.align = NoGUI::TextAlign::TOP;
		joinText.margin = (Vector2){0, 0};
		NoGUI::CText hostText = joinText; // copy
		hostText.margin = (Vector2){3, 0};
		NoGUI::CText hostLabelStyle = labelStyle; // copy
		hostLabelStyle.align = NoGUI::TextAlign::LEFT;
		
		// Page 0 (main menu)
		std::shared_ptr< NoGUI::Page > pg = addPage(true);
		pg->addComponents("Label", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Button", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("ALabel", std::make_shared< NoGUI::CContainer >());
		
		pg->getComponents("Label")->addComponent< NoGUI::CText >(titleStyle);
		pg->getComponents("Button")->addComponent< NoGUI::CText >(buttonStyle);
		pg->getComponents("ALabel")->addComponent< NoGUI::CImage >(mainBack);
		
		NoGUI::Style mainBackStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
		NoGUI::Style title = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 280}, (Vector2){115, 50}, 4, 0, 0};
		NoGUI::Style onlineStyle = {LIGHTGRAY, BLACK, (Vector2){center.x, center.y - 175}, (Vector2){115, 50}, 4, 1, 0};
		NoGUI::Style offlineStyle = {LIGHTGRAY, BLACK, (Vector2){onlineStyle.pos.x, onlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
		NoGUI::Style settingsStyle = {LIGHTGRAY, BLACK, (Vector2){offlineStyle.pos.x, offlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
		NoGUI::Style exitStyle = {LIGHTGRAY, BLACK, (Vector2){settingsStyle.pos.x, settingsStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
		
		std::shared_ptr< NoGUI::Element > mainBackground = addElement< NoGUI::Element >(mainBackStyle, "ALabel", "");
		std::shared_ptr< NoGUI::Element > titleLabel = addElement< NoGUI::Element >(title, "Label", "ANDOR");
		std::shared_ptr< NoGUI::Element > onlineButton = addElement< NoGUI::Button >(onlineStyle, "Button", "Play Online");
		std::shared_ptr< NoGUI::Element > offlineButton = addElement< NoGUI::Button >(offlineStyle, "Button", "Play Offline");
		std::shared_ptr< NoGUI::Element > settingsButton = addElement< NoGUI::Button >(settingsStyle, "Button", "Settings");
		std::shared_ptr< NoGUI::Element > exitButton = addElement< NoGUI::Button >(exitStyle, "Button", "Exit");
		// Page 1 (online navbar)
		pg = addPage();

		pg->addComponents("AButton", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Join", std::make_shared< NoGUI::CContainer >());
		
		pg->getComponents("Join")->addComponent< NoGUI::CText >(joinText);
		pg->getComponents("AButton")->addComponent< NoGUI::CText >(hostText);
		
		NoGUI::Style joinStyle = {BACKGROUND, BLACK, (Vector2){25, 50}, (Vector2){25, 30}, 4, 0, 0};
		NoGUI::Style hostStyle = {BACKGROUND, BLACK, (Vector2){joinStyle.pos.x + joinStyle.radius.x * 2 - 4, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
		NoGUI::Style returnStyle = {BACKGROUND, BLACK, (Vector2){menu->getWindow().width - joinStyle.radius.x, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
		std::shared_ptr< NoGUI::Element > hostButton = pg->addElement< NoGUI::Button >(hostStyle, "AButton", "Host");
		std::shared_ptr< NoGUI::Element > joinButton = pg->addElement< NoGUI::Button >(joinStyle, "Join", "Join");
		std::shared_ptr< NoGUI::Element > returnButton = pg->addElement< NoGUI::Button >(returnStyle, "AButton", "Back");
		// Page 2 (join)
		pg = addPage();
		
		NoGUI::Style backStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y + 25}, (Vector2){center.x, center.y - 25}, 4, 0, 0};
		NoGUI::Style IPStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style portStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style nameStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style msgStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y + 50}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style connectStyle = {GRAY, BLACK, (Vector2){center.x, center.y + 225}, (Vector2){115, 50}, 4, 1, 0};
		NoGUI::Style sendStyle = {GREEN, BLACK, (Vector2){center.x - msgStyle.radius.x - 25, msgStyle.pos.y + 30}, (Vector2){25, 25}, 4, 1, 0};
		NoGUI::Style IPInStyle = {LIGHTGRAY, BLACK, (Vector2){IPStyle.pos.x, IPStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
		NoGUI::Style portInStyle = {LIGHTGRAY, BLACK, (Vector2){portStyle.pos.x, portStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
		NoGUI::Style nameInStyle = {LIGHTGRAY, BLACK, (Vector2){nameStyle.pos.x, nameStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
		NoGUI::Style msgInStyle = {LIGHTGRAY, BLACK, (Vector2){msgStyle.pos.x, sendStyle.pos.y}, (Vector2){112, 25}, 4, 2, 0};
		
		// components
		pg->addComponents("AImage", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Button", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Label", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Input", std::make_shared< NoGUI::CContainer >());
		
		pg->getComponents("Label")->addComponent< NoGUI::CText >(labelStyle);
		pg->getComponents("Button")->addComponent< NoGUI::CText >(buttonStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CText >(inputStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CInput >(200);
		pg->getComponents("AImage")->addComponent< NoGUI::CImage >(joinBack);
		
		// elements
		std::shared_ptr< NoGUI::Element > imgLabel = pg->addElement< NoGUI::Element >(backStyle, "AImage", "Background");
		std::shared_ptr< NoGUI::Element > connectButton = pg->addElement< NoGUI::Button >(connectStyle, "Button", "Connect");
		std::shared_ptr< NoGUI::Element > sendButton = pg->addElement< NoGUI::Button >(sendStyle, "Button", "SEND");
		std::shared_ptr< NoGUI::Element > IPLabel = pg->addElement< NoGUI::Element >(IPStyle, "Label", "IP Address:");
		std::shared_ptr< NoGUI::Element > portLabel = pg->addElement< NoGUI::Element >(portStyle, "Label", "Port:");
		std::shared_ptr< NoGUI::Element > nameLabel = pg->addElement< NoGUI::Element >(nameStyle, "Label", "Username:");
		std::shared_ptr< NoGUI::Element > msgLabel = pg->addElement< NoGUI::Element >(msgStyle, "Label", "Message:");
		std::shared_ptr< NoGUI::Element > IPInput = pg->addElement< NoGUI::Input >(IPInStyle, "Input", "");
		std::shared_ptr< NoGUI::Element > portInput = pg->addElement< NoGUI::Input >(portInStyle, "Input", "");
		std::shared_ptr< NoGUI::Element > nameInput = pg->addElement< NoGUI::Input >(nameInStyle, "Input", "");
		std::shared_ptr< NoGUI::Element > msgInput = pg->addElement< NoGUI::Input >(msgInStyle, "Input", "");
		// Page 3 (host)
		pg = addPage();
		
		NoGUI::Style FFStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style FFSStyle = {RED, BLACK, (Vector2){FFStyle.pos.x - 170, center.y - 265}, (Vector2){25, 5}, 0, 0, 0};
		NoGUI::Style lootStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style playerStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style cheatStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style cheatInStyle = {LIGHTGRAY, BLACK, (Vector2){cheatStyle.pos.x, cheatStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
		NoGUI::Style enterStyle = {GREEN, BLACK, (Vector2){center.x - cheatStyle.radius.x - 25, cheatStyle.pos.y + 30}, (Vector2){25, 25}, 4, 1, 0};
		NoGUI::Style serverStyle = {GRAY, BLACK, (Vector2){center.x, center.y + 225}, (Vector2){115, 50}, 4, 1, 0};
		NoGUI::Style lootDStyle = {GRAY, BLACK, (Vector2){lootStyle.pos.x - 170, lootStyle.pos.y - 15}, (Vector2){40, 20}, 4, 1, 0};
		NoGUI::Style playerDStyle = {GRAY, BLACK, (Vector2){playerStyle.pos.x - 170, playerStyle.pos.y - 15}, (Vector2){40, 20}, 4, 1, 0};
		NoGUI::Style FFToggle = {LIGHTGRAY, BLACK, (Vector2){FFSStyle.radius.x * -1, 0}, (Vector2){5, 5}, 0, 1, 0};
		
		// components
		pg->addComponents("AImage", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Button", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Label", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Input", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("ToggleFF", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Loot", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Player", std::make_shared< NoGUI::CContainer >());
		
		pg->getComponents("Label")->addComponent< NoGUI::CText >(hostLabelStyle);
		pg->getComponents("Button")->addComponent< NoGUI::CText >(buttonStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CText >(inputStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CInput >(50);
		pg->getComponents("AImage")->addComponent< NoGUI::CImage >(hostBack);
		pg->getComponents("ToggleFF")->addComponent< NoGUI::CMultiStyle >(FFToggle);
		pg->getComponents("Loot")->addComponent< NoGUI::CText >(dropStyle);
		pg->getComponents("Player")->addComponent< NoGUI::CText >(dropStyle);
		
		// elements
		std::shared_ptr< NoGUI::Element > hostImgLabel = pg->addElement< NoGUI::Element >(backStyle, "AImage", "Background");
		std::shared_ptr< NoGUI::Element > serverButton = pg->addElement< NoGUI::Button >(serverStyle, "Button", "Host");
		std::shared_ptr< NoGUI::Element > enterButton = pg->addElement< NoGUI::Button >(enterStyle, "Button", "ENTER");
		std::shared_ptr< NoGUI::Element > FFLabel = pg->addElement< NoGUI::Element >(FFStyle, "Label", "Friendly Fire");
		std::shared_ptr< NoGUI::Element > FFSwitch = pg->addElement< NoGUI::Toggle >(FFSStyle, "ToggleFF", "Friendly Fire");
		std::shared_ptr< NoGUI::Element > cheatInput = pg->addElement< NoGUI::Input >(cheatInStyle, "Input", "");
		std::shared_ptr< NoGUI::Element > lootLabel = pg->addElement< NoGUI::Element >(lootStyle, "Label", "Loot Style");
		std::shared_ptr< NoGUI::Element > playerLabel = pg->addElement< NoGUI::Element >(playerStyle, "Label", "Character");
		std::shared_ptr< NoGUI::Element > cheatLabel = pg->addElement< NoGUI::Element >(cheatStyle, "Label", "Cheat Codes:");
		std::shared_ptr< NoGUI::Element > lootDrop = pg->addElement< NoGUI::Button >(lootDStyle, "Loot", "FFA");
		std::shared_ptr< NoGUI::Element > playerDrop = pg->addElement< NoGUI::Button >(playerDStyle, "Player", "Sniper");
		// Page 4 (loot dropdown)
		std::shared_ptr< NoGUI::DropDown > lootDown = addDropDown(lootDrop, NoGUI::TextWrap::DOWN);
		lootDown->addComponents("LootOption", std::make_shared< NoGUI::CContainer >());
		lootDown->getComponents("LootOption")->addComponent< NoGUI::CText >(dropStyle);
		lootDown->addElement< NoGUI::Button >("LootOption", "FFA");
		lootDown->addElement< NoGUI::Button >("LootOption", "Share");
		lootDown->addElement< NoGUI::Button >("LootOption", "Host");
		lootDown->addElement< NoGUI::Button >("LootOption", "Unique");
		// Page 5 (character dropdown)
		std::shared_ptr< NoGUI::DropDown > playerDown = addDropDown(playerDrop, NoGUI::TextWrap::DOWN);
		playerDown->addComponents("PlayerOption", std::make_shared< NoGUI::CContainer >());
		playerDown->getComponents("PlayerOption")->addComponent< NoGUI::CText >(dropStyle);
		playerDown->addElement< NoGUI::Button >("PlayerOption", "Sniper");
		playerDown->addElement< NoGUI::Button >("PlayerOption", "Rifler");
		playerDown->addElement< NoGUI::Button >("PlayerOption", "Bruiser");
		playerDown->addElement< NoGUI::Button >("PlayerOption", "Shotgun");
		playerDown->addElement< NoGUI::Button >("PlayerOption", "Akimbo");
		// Page 6 (settings)
		pg = addPage();
		
		NoGUI::Style setBackStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
		NoGUI::Style vsyncStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style vsyncSStyle = {GRAY, BLACK, (Vector2){vsyncStyle.pos.x - 170, center.y - 260}, (Vector2){25, 5}, 0, 0, 0};
		NoGUI::Style fullStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style fullSStyle = {GRAY, BLACK, (Vector2){fullStyle.pos.x - 170, center.y - 210}, (Vector2){25, 5}, 0, 0, 0};
		NoGUI::Style AAStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style AASStyle = {GRAY, BLACK, (Vector2){AAStyle.pos.x - 170, center.y - 150}, (Vector2){25, 5}, 0, 0, 0};
		NoGUI::Style resStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
		NoGUI::Style mainStyle = {BACKGROUND, BLACK, (Vector2){menu->getWindow().width - 25,  20}, (Vector2){25, 18}, 4, 0, 0};
		NoGUI::Style resDStyle = {GRAY, BLACK, (Vector2){resStyle.pos.x + 110, resStyle.pos.y - 10}, (Vector2){100, 20}, 4, 1, 0};
		NoGUI::Style aspectDStyle = {GRAY, BLACK, (Vector2){resStyle.pos.x - 170, resStyle.pos.y - 10}, (Vector2){30, 20}, 4, 1, 0};
		NoGUI::Style fpsDStyle = {GRAY, BLACK, (Vector2){vsyncStyle.pos.x + 110, vsyncStyle.pos.y - 10}, (Vector2){100, 20}, 4, 1, 0};
		NoGUI::Style vToggle = {LIGHTGRAY, BLACK, (Vector2){0, 0}, (Vector2){5, 5}, 0, 1, 0};
		NoGUI::Style fsToggle = {LIGHTGRAY, BLACK, (Vector2){0, 0}, (Vector2){5, 5}, 0, 1, 0};
		NoGUI::Style AAToggle = {LIGHTGRAY, BLACK, (Vector2){0, 0}, (Vector2){5, 5}, 0, 1, 0};
		
		// components
		pg->addComponents("ALabel", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Button", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Label", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Input", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("ToggleAA", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("ToggleV", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("ToggleFS", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("FPS", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("Res", std::make_shared< NoGUI::CContainer >());
		pg->addComponents("AspectR", std::make_shared< NoGUI::CContainer >());
		
		
		pg->getComponents("Label")->addComponent< NoGUI::CText >(hostLabelStyle);
		pg->getComponents("Button")->addComponent< NoGUI::CText >(buttonStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CText >(inputStyle);
		pg->getComponents("Input")->addComponent< NoGUI::CInput >(50);
		pg->getComponents("ALabel")->addComponent< NoGUI::CImage >(settingsBack);
		pg->getComponents("ToggleAA")->addComponent< NoGUI::CMultiStyle >(AAToggle);
		pg->getComponents("ToggleV")->addComponent< NoGUI::CMultiStyle >(vToggle);
		pg->getComponents("ToggleFS")->addComponent< NoGUI::CMultiStyle >(fsToggle);
		pg->getComponents("FPS")->addComponent< NoGUI::CText >(dropStyle);
		pg->getComponents("Res")->addComponent< NoGUI::CText >(dropStyle);
		pg->getComponents("AspectR")->addComponent< NoGUI::CText >(dropStyle);
		
		// elements
		std::shared_ptr< NoGUI::Element > setBackground = pg->addElement< NoGUI::Element >(mainBackStyle, "ALabel", "");
		std::shared_ptr< NoGUI::Element > vsyncLabel = pg->addElement< NoGUI::Element >(vsyncStyle, "Label", "Vsync");
		std::shared_ptr< NoGUI::Element > vsyncSwitch = pg->addElement< NoGUI::Toggle >(vsyncSStyle, "ToggleV", "Vsync");
		std::shared_ptr< NoGUI::Element > fullLabel = pg->addElement< NoGUI::Element >(fullStyle, "Label", "Fullscreen");
		std::shared_ptr< NoGUI::Element > fullSwitch = pg->addElement< NoGUI::Toggle >(fullSStyle, "ToggleFS", "Fullscreen");
		std::shared_ptr< NoGUI::Element > AALabel = pg->addElement< NoGUI::Element >(AAStyle, "Label", "Anti Aliasing");
		std::shared_ptr< NoGUI::Element > AASwitch = pg->addElement< NoGUI::Toggle >(AASStyle, "ToggleAA", "Anti Aliasing");
		std::shared_ptr< NoGUI::Element > resDrop = pg->addElement< NoGUI::Button >(resDStyle, "Res", "1920 x 1080 HD");
		std::shared_ptr< NoGUI::Element > aspectDrop = pg->addElement< NoGUI::Input >(aspectDStyle, "AspectR", "16:9");
		std::shared_ptr< NoGUI::Element > fpsDrop = pg->addElement< NoGUI::Button >(fpsDStyle, "FPS", "60fps HD Gaming");
		std::shared_ptr< NoGUI::Element > resLabel = pg->addElement< NoGUI::Element >(resStyle, "Label", "Resolution");
		std::shared_ptr< NoGUI::Element > mainButton = pg->addElement< NoGUI::Button >(mainStyle, "Button", "Back");
		std::shared_ptr< NoGUI::DropDown > fpsDown = addDropDown(fpsDrop, NoGUI::TextWrap::DOWN);
		// Page 7 (fps dropdown)
		fpsDown->addComponents("FPSOption", std::make_shared< NoGUI::CContainer >());
		fpsDown->getComponents("FPSOption")->addComponent< NoGUI::CText >(dropStyle);
		for (auto i = mapFPS.rbegin(); i != mapFPS.rend(); ++i) 
		{
			fpsDown->addElement< NoGUI::Button >("FPSOption", i->first);
		}
		// Page 8 (resolution dropdown)
		std::shared_ptr< NoGUI::DropDown > resDown = addDropDown(resDrop, NoGUI::TextWrap::DOWN);
		resDown->addComponents("ResOption", std::make_shared< NoGUI::CContainer >());
		resDown->getComponents("ResOption")->addComponent< NoGUI::CText >(dropStyle);
		for (auto i = map169.rbegin(); i != map169.rend(); ++i)
		{
			resDown->addElement< NoGUI::Button >("ResOption", i->first);
		}
		// Page 9 (aspect ratio dropdown)
		std::shared_ptr< NoGUI::DropDown > aspectDown = addDropDown(aspectDrop, NoGUI::TextWrap::DOWN);
		aspectDown->addComponents("AspectOption", std::make_shared< NoGUI::CContainer >());
		aspectDown->getComponents("AspectOption")->addComponent< NoGUI::CText >(dropStyle);
		aspectDown->addElement< NoGUI::Button >("AspectOption", "32:9");
		aspectDown->addElement< NoGUI::Button >("AspectOption", "21:9");
		aspectDown->addElement< NoGUI::Button >("AspectOption", "16:9");
		aspectDown->addElement< NoGUI::Button >("AspectOption", "16:10");
		aspectDown->addElement< NoGUI::Button >("AspectOption", "4:3");
	}
};