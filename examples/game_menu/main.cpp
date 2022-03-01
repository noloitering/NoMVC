#include "event.h"

int main(int argc, char ** argv)
{	
	Color INVISIBLE = (Color){0, 0, 0, 1};
	Color BACKGROUND = (Color){100, 100, 100, 255};
	
	std::shared_ptr< NoMVC::Controller > game = std::make_shared< NoMVC::Controller >();
	std::shared_ptr< Menu > menu = std::make_shared< Menu >(game.get(), game->getWindow());
	std::shared_ptr< NoGUI::GUIManager > GUIModel = std::make_shared< NoGUI::GUIManager >(NoGUI::GUIManager());
	std::shared_ptr< NoGUI::Page > pg = GUIModel->getPage();
	GUIModel->addListener(menu);
	
	Vector2 center = (Vector2){game->getWindow().width/2, game->getWindow().height/2};
	// TODO: load this from a file
	std::shared_ptr< Font > font = game->assets->addFont("jupiter_crash", "../fonts/jupiter_crash.png");
	std::shared_ptr< Texture2D > mainImg = game->assets->addTexture("mainBack", "../imgs/space2.png");
	NoGUI::CImage mainBack = NoGUI::CImage(mainImg);
	mainBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > settingsImg = game->assets->addTexture("setBack", "../imgs/pond1.png");
	NoGUI::CImage settingsBack = NoGUI::CImage(settingsImg);
	settingsBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > joinImg = game->assets->addTexture("joinBack", "../imgs/background.png");
	NoGUI::CImage joinBack = NoGUI::CImage(joinImg);
	std::shared_ptr< Texture2D > hostImg = game->assets->addTexture("hostBack", "../imgs/background2.png");
	NoGUI::CImage hostBack = NoGUI::CImage(hostImg);
	// text
	NoGUI::CText titleStyle = NoGUI::CText(font);
	titleStyle.col = PURPLE;
	titleStyle.align = NoGUI::TextAlign::CENTER;
	titleStyle.size = 50;
	NoGUI::CText labelStyle = NoGUI::CText(font);
	labelStyle.col = MAROON;
	labelStyle.align = NoGUI::TextAlign::RIGHT;
	labelStyle.wrap = NoGUI::TextWrap::DOWN;
	labelStyle.margin = (Vector2){0, 0};
	labelStyle.spacing = (Vector2){2, 0};
	labelStyle.size = 25;
	labelStyle.shadow.draw = true;
	labelStyle.shadow.offset = {2, -2};
	NoGUI::CText inputStyle = labelStyle;
	inputStyle.shadow.draw = false;
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
	
	std::shared_ptr< NoGUI::Element > mainBackground = GUIModel->addElement< NoGUI::Element >(mainBackStyle, "ALabel", "");
	std::shared_ptr< NoGUI::Element > titleLabel = GUIModel->addElement< NoGUI::Element >(title, "Label", "ANDOR");
	std::shared_ptr< NoGUI::Element > onlineButton = GUIModel->addElement< NoGUI::Button >(onlineStyle, "Button", "Play Online");
	std::shared_ptr< NoGUI::Element > offlineButton = GUIModel->addElement< NoGUI::Button >(offlineStyle, "Button", "Play Offline");
	std::shared_ptr< NoGUI::Element > settingsButton = GUIModel->addElement< NoGUI::Button >(settingsStyle, "Button", "Settings");
	std::shared_ptr< NoGUI::Element > exitButton = GUIModel->addElement< NoGUI::Button >(exitStyle, "Button", "Exit");
	
	// Page 1 (online navbar)
	pg = GUIModel->addPage();

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
	pg = GUIModel->addPage();
	
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
	pg = GUIModel->addPage();
	
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
	std::shared_ptr< NoGUI::Element > enterButton = pg->addElement< NoGUI::Button >(enterStyle, "Button", "ENTER"); // TODO: fix alignment bug
	std::shared_ptr< NoGUI::Element > FFLabel = pg->addElement< NoGUI::Element >(FFStyle, "Label", "Friendly Fire");
	std::shared_ptr< NoGUI::Element > FFSwitch = pg->addElement< NoGUI::Toggle >(FFSStyle, "ToggleFF", "Friendly Fire");
	std::shared_ptr< NoGUI::Element > cheatInput = pg->addElement< NoGUI::Input >(cheatInStyle, "Input", "");
	std::shared_ptr< NoGUI::Element > lootLabel = pg->addElement< NoGUI::Element >(lootStyle, "Label", "Loot Style");
	std::shared_ptr< NoGUI::Element > playerLabel = pg->addElement< NoGUI::Element >(playerStyle, "Label", "Character");
	std::shared_ptr< NoGUI::Element > cheatLabel = pg->addElement< NoGUI::Element >(cheatStyle, "Label", "Cheat Codes:");
	std::shared_ptr< NoGUI::Element > lootDrop = pg->addElement< NoGUI::Button >(lootDStyle, "Loot", "FFA");
	std::shared_ptr< NoGUI::Element > playerDrop = pg->addElement< NoGUI::Button >(playerDStyle, "Player", "Sniper");
	std::shared_ptr< NoGUI::DropDown > lootDown = GUIModel->addDropDown(lootDrop, NoGUI::TextWrap::DOWN);
	lootDown->addComponents("LootOption", std::make_shared< NoGUI::CContainer >());
	lootDown->getComponents("LootOption")->addComponent< NoGUI::CText >(dropStyle);
	lootDown->addElement< NoGUI::Button >("LootOption", "FFA");
	lootDown->addElement< NoGUI::Button >("LootOption", "Share");
	lootDown->addElement< NoGUI::Button >("LootOption", "Host");
	lootDown->addElement< NoGUI::Button >("LootOption", "Unique");
	std::shared_ptr< NoGUI::DropDown > playerDown = GUIModel->addDropDown(playerDrop, NoGUI::TextWrap::DOWN);
	playerDown->addComponents("PlayerOption", std::make_shared< NoGUI::CContainer >());
	playerDown->getComponents("PlayerOption")->addComponent< NoGUI::CText >(dropStyle);
	playerDown->addElement< NoGUI::Button >("PlayerOption", "Sniper");
	playerDown->addElement< NoGUI::Button >("PlayerOption", "Rifler");
	playerDown->addElement< NoGUI::Button >("PlayerOption", "Bruiser");
	playerDown->addElement< NoGUI::Button >("PlayerOption", "Shotgun");
	playerDown->addElement< NoGUI::Button >("PlayerOption", "Akimbo");
	
	// Page 4 (settings)
	pg = GUIModel->addPage();
	
	NoGUI::Style setBackStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
	NoGUI::Style vsyncStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style vsyncSStyle = {GRAY, BLACK, (Vector2){vsyncStyle.pos.x - 170, center.y - 265}, (Vector2){25, 5}, 0, 0, 0};
	NoGUI::Style fullStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style fullSStyle = {GRAY, BLACK, (Vector2){fullStyle.pos.x - 170, center.y - 215}, (Vector2){25, 5}, 0, 0, 0};
	NoGUI::Style AAStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style AASStyle = {GRAY, BLACK, (Vector2){AAStyle.pos.x - 170, center.y - 165}, (Vector2){25, 5}, 0, 0, 0};
	NoGUI::Style resStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style mainStyle = {BACKGROUND, BLACK, (Vector2){menu->getWindow().width - 25,  20}, (Vector2){25, 18}, 4, 0, 0};
	NoGUI::Style resDStyle = {GRAY, BLACK, (Vector2){resStyle.pos.x + 100, resStyle.pos.y - 15}, (Vector2){100, 20}, 4, 1, 0};
	NoGUI::Style aspectDStyle = {GRAY, BLACK, (Vector2){resStyle.pos.x - 170, resStyle.pos.y - 15}, (Vector2){30, 20}, 4, 1, 0};
	NoGUI::Style fpsDStyle = {GRAY, BLACK, (Vector2){vsyncStyle.pos.x + 100, vsyncStyle.pos.y - 15}, (Vector2){100, 20}, 4, 1, 0};
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
	std::shared_ptr< NoGUI::DropDown > fpsDown = GUIModel->addDropDown(fpsDrop, NoGUI::TextWrap::DOWN);
	fpsDown->addComponents("FPSOption", std::make_shared< NoGUI::CContainer >());
	fpsDown->getComponents("FPSOption")->addComponent< NoGUI::CText >(dropStyle);
	for (auto i = mapFPS.rbegin(); i != mapFPS.rend(); ++i) 
	{
		fpsDown->addElement< NoGUI::Button >("FPSOption", i->first);
	}
	std::shared_ptr< NoGUI::DropDown > resDown = GUIModel->addDropDown(resDrop, NoGUI::TextWrap::DOWN);
	resDown->addComponents("ResOption", std::make_shared< NoGUI::CContainer >());
	resDown->getComponents("ResOption")->addComponent< NoGUI::CText >(dropStyle);
	for (auto i = map169.rbegin(); i != map169.rend(); ++i)
	{
		resDown->addElement< NoGUI::Button >("ResOption", i->first);
	}
	std::shared_ptr< NoGUI::DropDown > aspectDown = GUIModel->addDropDown(aspectDrop, NoGUI::TextWrap::DOWN);
	aspectDown->addComponents("AspectOption", std::make_shared< NoGUI::CContainer >());
	aspectDown->getComponents("AspectOption")->addComponent< NoGUI::CText >(dropStyle);
	aspectDown->addElement< NoGUI::Button >("AspectOption", "32:9");
	aspectDown->addElement< NoGUI::Button >("AspectOption", "21:9");
	aspectDown->addElement< NoGUI::Button >("AspectOption", "16:9");
	aspectDown->addElement< NoGUI::Button >("AspectOption", "16:10");
	aspectDown->addElement< NoGUI::Button >("AspectOption", "4:3");
	
	
	std::shared_ptr< NoMVC::Model > model = GUIModel;
	std::shared_ptr< NoMVC::View > view = menu;
	menu->addModel(model);
	game->changeScene(menu);
	game->currentScene()->update();
	int res = game->run();

	return res;
}