#include "../../src/Controller.h"
#include "../NoGUI/src/GUI.h"

//GameEngine::GameEngine()
//{
//	InitWindow(window.width, window.height, "Client App");
//	SetTargetFPS(window.fps);
//	Color INVISIBLE = (Color){0, 0, 0, 1};
//	Color BACKGROUND = (Color){100, 100, 100, 255};
//	Vector2 center = (Vector2){window.width/2, window.height/2};
//	scene = std::make_shared< Level >(this, window);
//	scene->overlay.addListener(scene);
//	std::shared_ptr< Font > font = assets.addFont("jupiter_crash", "../fonts/jupiter_crash.png");
//	std::shared_ptr< Texture2D > mainImg = assets.addTexture("mainBack", "../imgs/space2.png");
//	CImage mainBack = CImage(mainImg);
//	mainBack.cropping = Crop::NONE;
//	std::shared_ptr< Texture2D > settingsImg = assets.addTexture("setBack", "../imgs/pond1.png");
//	CImage settingsBack = CImage(settingsImg);
//	settingsBack.cropping = Crop::NONE;
//	std::shared_ptr< Texture2D > joinImg = assets.addTexture("joinBack", "../imgs/background.png");
//	CImage joinBack = CImage(joinImg);
//	std::shared_ptr< Texture2D > hostImg = assets.addTexture("hostBack", "../imgs/background2.png");
//	CImage hostBack = CImage(hostImg);
	// text
//	CText titleStyle = CText(font);
//	titleStyle.col = PURPLE;
//	titleStyle.align = TextAlign::CENTER;
//	titleStyle.size = 50;
//	CText labelStyle = CText(font);
//	labelStyle.col = MAROON;
//	labelStyle.align = TextAlign::RIGHT;
//	labelStyle.wrap = TextWrap::DOWN;
//	labelStyle.margin = (Vector2){0, 0};
//	labelStyle.spacing = (Vector2){2, 0};
//	labelStyle.size = 25;
//	labelStyle.shadow.draw = true;
//	labelStyle.shadow.offset = {2, -2};
//	CText inputStyle = labelStyle;
//	inputStyle.shadow.draw = false;
//	CText buttonStyle = inputStyle; // copy
//	buttonStyle.align = TextAlign::CENTER;
//	CText joinText = inputStyle; // copy
//	joinText.align = TextAlign::TOP;
//	joinText.margin = (Vector2){0, 0};
//	CText hostText = joinText; // copy
//	hostText.margin = (Vector2){3, 0};
//	CText hostLabelStyle = labelStyle; // copy
//	hostLabelStyle.align = TextAlign::LEFT;
	
	// TODO: load these from a file
	// Page 0 (main menu)
//	Style mainBackStyle = (Style){BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
//	Style title = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 280}, (Vector2){115, 50}, 4, 0, 0};
//	Style onlineStyle = {LIGHTGRAY, BLACK, (Vector2){center.x, center.y - 175}, (Vector2){115, 50}, 4, 1, 0};
//	Style offlineStyle = {LIGHTGRAY, BLACK, (Vector2){onlineStyle.pos.x, onlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
//	Style settingsStyle = {LIGHTGRAY, BLACK, (Vector2){offlineStyle.pos.x, offlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
//	Style exitStyle = {LIGHTGRAY, BLACK, (Vector2){settingsStyle.pos.x, settingsStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
	
//	std::shared_ptr< Element > titleLabel = scene->overlay.addElement< Element >(title, "ANDOR", "Label");
//	std::shared_ptr< Element > onlineButton = scene->overlay.addElement< Button >(onlineStyle, "Play Online", "Button");
//	std::shared_ptr< Element > offlineButton = scene->overlay.addElement< Button >(offlineStyle, "Play Offline", "Button");
//	std::shared_ptr< Element > settingsButton = scene->overlay.addElement< Button >(settingsStyle, "Settings", "Button");
//	std::shared_ptr< Element > exitButton = scene->overlay.addElement< Button >(exitStyle, "Exit", "Button");
//	std::shared_ptr< Element > mainBackground = scene->overlay.addElement< Element >(mainBackStyle, "", "ALabel");
	
//	titleLabel->addComponent< CText >(titleStyle);
//	onlineButton->addComponent< CText >(buttonStyle);
//	offlineButton->addComponent< CText >(buttonStyle);
//	settingsButton->addComponent< CText >(buttonStyle);
//	exitButton->addComponent< CText >(buttonStyle);
//	mainBackground->addComponent< CImage >(mainBack);
	
	// Page 1 (online navbar)
//	scene->overlay.addPage();
//	std::shared_ptr< Page > pg = scene->overlay.getPage(1);
	
//	Style joinStyle = (Style){BACKGROUND, BLACK, (Vector2){25, 50}, (Vector2){25, 30}, 4, 0, 0};
//	Style hostStyle = (Style){BACKGROUND, BLACK, (Vector2){joinStyle.pos.x + joinStyle.radius.x * 2 - 4, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
//	Style returnStyle = (Style){BACKGROUND, BLACK, (Vector2){window.width - joinStyle.radius.x, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
//	std::shared_ptr< Element > hostButton = pg->addElement< Button >(hostStyle, "Host", "AButton");
//	std::shared_ptr< Element > joinButton = pg->addElement< Button >(joinStyle, "Join", "AButton");
//	std::shared_ptr< Element > returnButton = pg->addElement< Button >(returnStyle, "Back", "AButton");
//	joinButton->addComponent< CText >(joinText);
//	hostButton->addComponent< CText >(hostText);
//	returnButton->addComponent< CText >(hostText);
	
	// Page 2 (join)
//	scene->overlay.addPage();
//	pg = scene->overlay.getPage(2);
	
//	Style backStyle = (Style){BACKGROUND, BLACK, (Vector2){center.x, center.y + 25}, (Vector2){center.x, center.y - 25}, 4, 0, 0};
//	Style IPStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
//	Style portStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
//	Style nameStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
//	Style msgStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y + 50}, (Vector2){112, 25}, 4, 0, 0};
//	Style connectStyle = {GRAY, BLACK, (Vector2){center.x, center.y + 225}, (Vector2){115, 50}, 4, 1, 0};
//	Style sendStyle = {GREEN, BLACK, (Vector2){center.x - msgStyle.radius.x - 25, msgStyle.pos.y + 30}, (Vector2){25, 25}, 4, 1, 0};
//	Style IPInStyle = {LIGHTGRAY, BLACK, (Vector2){IPStyle.pos.x, IPStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
//	Style portInStyle = {LIGHTGRAY, BLACK, (Vector2){portStyle.pos.x, portStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
//	Style nameInStyle = {LIGHTGRAY, BLACK, (Vector2){nameStyle.pos.x, nameStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
//	Style msgInStyle = {LIGHTGRAY, BLACK, (Vector2){msgStyle.pos.x, sendStyle.pos.y}, (Vector2){112, 25}, 4, 2, 0};
	// elements
//	std::shared_ptr< Element > imgLabel = pg->addElement< Element >(backStyle, "Background", "AImage");
//	std::shared_ptr< Element > connectButton = pg->addElement< Button >(connectStyle, "Connect", "Button");
//	std::shared_ptr< Element > sendButton = pg->addElement< Button >(sendStyle, "SEND", "Button");
//	std::shared_ptr< Element > IPLabel = pg->addElement< Element >(IPStyle, "IP Address:", "Label");
//	std::shared_ptr< Element > portLabel = pg->addElement< Element >(portStyle, "Port:", "Label");
//	std::shared_ptr< Element > nameLabel = pg->addElement< Element >(nameStyle, "Username:", "Label");
//	std::shared_ptr< Element > msgLabel = pg->addElement< Element >(msgStyle, "Message:", "Label");
//	std::shared_ptr< Element > IPInput = pg->addElement< Element >(IPInStyle, "", "Input");
//	std::shared_ptr< Element > portInput = pg->addElement< Element >(portInStyle, "", "Input");
//	std::shared_ptr< Element > nameInput = pg->addElement< Element >(nameInStyle, "", "Input");
//	std::shared_ptr< Element > msgInput = pg->addElement< Element >(msgInStyle, "", "Input");
	// components
//	IPLabel->addComponent< CText >(labelStyle);
//	portLabel->addComponent< CText >(labelStyle);
//	nameLabel->addComponent< CText >(labelStyle);
//	msgLabel->addComponent< CText >(labelStyle);
//	connectButton->addComponent< CText >(buttonStyle);
//	sendButton->addComponent< CText >(buttonStyle);
//	joinButton->addComponent< CText >(joinText);
//	hostButton->addComponent< CText >(hostText);
//	imgLabel->addComponent< CImage >(joinBack);
//	IPInput->addComponent< CText >(inputStyle);
//	portInput->addComponent< CText >(inputStyle);
//	nameInput->addComponent< CText >(inputStyle);
//	msgInput->addComponent< CText >(inputStyle);
//	IPInput->addComponent< CInput >();
//	portInput->addComponent< CInput >();
//	nameInput->addComponent< CInput >();
//	msgInput->addComponent< CInput >();
	
	// Page 3 (host)
//	scene->overlay.addPage();
//	pg = scene->overlay.getPage(3);
	
//	Style FFStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
//	Style lootStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
//	Style playerStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
//	Style cheatStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
//	Style cheatInStyle = {LIGHTGRAY, BLACK, (Vector2){cheatStyle.pos.x, cheatStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
//	Style enterStyle = {GREEN, BLACK, (Vector2){center.x - cheatStyle.radius.x - 25, cheatStyle.pos.y + 30}, (Vector2){25, 25}, 4, 1, 0};
//	Style serverStyle = {GRAY, BLACK, (Vector2){center.x, center.y + 225}, (Vector2){115, 50}, 4, 1, 0};
	// elements
//	std::shared_ptr< Element > hostImgLabel = pg->addElement< Element >(backStyle, "Background", "AImage");
//	std::shared_ptr< Element > serverButton = pg->addElement< Button >(serverStyle, "Host", "Button");
//	std::shared_ptr< Element > enterButton = pg->addElement< Button >(enterStyle, "ENTER", "Button"); // TODO: fix alignment bug
//	std::shared_ptr< Element > FFLabel = pg->addElement< Element >(FFStyle, "Friendly Fire", "Label");
//	std::shared_ptr< Element > lootLabel = pg->addElement< Element >(lootStyle, "Loot Style", "Label");
//	std::shared_ptr< Element > playerLabel = pg->addElement< Element >(playerStyle, "Character", "Label");
//	std::shared_ptr< Element > cheatLabel = pg->addElement< Element >(cheatStyle, "Cheat Codes:", "Label");
//	std::shared_ptr< Element > cheatInput = pg->addElement< Element >(cheatInStyle, "", "Input");
	// components
//	hostImgLabel->addComponent< CImage >(hostBack);
//	FFLabel->addComponent< CText >(hostLabelStyle);
//	lootLabel->addComponent< CText >(hostLabelStyle);
//	playerLabel->addComponent< CText >(hostLabelStyle);
//	cheatLabel->addComponent< CText >(hostLabelStyle);
//	serverButton->addComponent<CText>(buttonStyle);
//	enterButton->addComponent<CText>(buttonStyle);
//	cheatInput->addComponent< CText >(inputStyle);
//	cheatInput->addComponent< CInput >();
	
	// Page 4 (settings)
//	scene->overlay.addPage();
//	pg = scene->overlay.getPage(4);
	
//	Style setBackStyle = (Style){BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
//	Style vsyncStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
//	Style fullStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
//	Style AAStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
//	Style resStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
//	Style mainStyle = (Style){BACKGROUND, BLACK, (Vector2){window.width - 25,  20}, (Vector2){25, 18}, 4, 0, 0};
	
//	std::shared_ptr< Element > vsyncLabel = pg->addElement< Element >(vsyncStyle, "Vsync", "Label");
//	std::shared_ptr< Element > fullLabel = pg->addElement< Element >(fullStyle, "Fullscreen", "Label");
//	std::shared_ptr< Element > AALabel = pg->addElement< Element >(AAStyle, "Anti Aliasing", "Label");
//	std::shared_ptr< Element > resLabel = pg->addElement< Element >(resStyle, "Resolution", "Label");
//	std::shared_ptr< Element > mainButton = pg->addElement< Button >(mainStyle, "Back", "Button");
//	std::shared_ptr< Element > setBackground = pg->addElement< Element >(mainBackStyle, "", "ALabel");
	
//	vsyncLabel->addComponent< CText >(hostLabelStyle);
//	fullLabel->addComponent< CText >(hostLabelStyle);
//	AALabel->addComponent< CText >(hostLabelStyle);
//	resLabel->addComponent< CText >(hostLabelStyle);
//	mainButton->addComponent< CText >(buttonStyle);
//	setBackground->addComponent< CImage >(settingsBack);
//	
//	scene->overlay.update();
//}

class Menu : public NoMVC::View, public NoGUI::Listener
{
public:
	void update();
	void render();
	void run();
	void cleanup() {}
	void onNotify(std::shared_ptr< NoGUI::Element > elem) {};
	
	Menu(Controller* g, WindowConfig conf)
		: View(g, conf) {}
};

//void Menu::onNotify(std::shared_ptr< Element > elem)
//{
//	if ( elem->hasComponent< CInput >() )
//	{
//		CInput& input = elem->getComponent< CInput >();
//		int key = GetCharPressed();
		// Check if more characters have been pressed on the same frame
//		while (key > 0)
//		{
			// NOTE: Only allow keys in range [32..125]
//			if ( (key >= 32) && (key <= 125) && (input.i < input.cap) )
//			{
//				std::string inner = elem->getInner();
//				inner.push_back((char)key);
//				elem->setInner(inner);
//				input.i++;
//			}
//			key = GetCharPressed();  // Check next character in the queue
//		}
//		if ( IsKeyPressed(KEY_BACKSPACE) )
//		{
//			if ( input.i > 0 )
//			{
//				input.i--;
//				std::string inner = elem->getInner();
//				inner.pop_back();
//				elem->setInner(inner);
//			}
//			else
//			{
//				input.i = 0;
//			}
//		}
//	}
//	else if ( elem->getInner() == "Join" )
//	{
//		overlay.getPage(3)->setActive(false);
//		overlay.getPage(2)->setActive(true);
//		elem->repos((Vector2){elem->styling().pos.x, 50});
//		overlay.getPage(1)->getElement(0)->repos((Vector2){overlay.getPage(1)->getElement(0)->styling().pos.x, elem->styling().pos.y + 8});
//	}
//	else if ( elem->getInner() == "Play Online" )
//	{
//		overlay.getPage(0)->setActive(false);
//		overlay.getPage(1)->setActive(true);
//		overlay.getPage(2)->setActive(true);
//	}
//	else if ( elem->getInner() == "Settings" )
//	{
//		overlay.getPage(0)->setActive(false);
//		overlay.getPage(4)->setActive(true);
//	}
//	else if ( elem->getInner() == "Host" )
//	{
//		overlay.getPage(2)->setActive(false);
//		overlay.getPage(3)->setActive(true);
//		elem->repos((Vector2){elem->styling().pos.x, 50});
//		overlay.getPage(1)->getElement(1)->repos((Vector2){overlay.getPage(1)->getElement(1)->styling().pos.x, elem->styling().pos.y + 8});
//	}
//	else if ( elem->getInner() == "Back" )
//	{
//		overlay.setActive(0);
//	}
//	else if ( elem->getInner() == "Exit" )
//	{
//		game->quit();
//	}
//}

int main(int argc, char ** argv)
{	
	Color INVISIBLE = (Color){0, 0, 0, 1};
	Color BACKGROUND = (Color){100, 100, 100, 255};
	
	NoMVC::Controller game = NoMVC::Controller();
	Menu menu = Menu(game, game.getWindow());
	NoGUI::GUIManager GUIModel = GUIManager();
	
	Vector2 center = (Vector2){window.width/2, window.height/2};
	// TODO: load this from a file
	std::shared_ptr< Font > font = game.assets.addFont("jupiter_crash", "../fonts/jupiter_crash.png");
	std::shared_ptr< Texture2D > mainImg = game.assets.addTexture("mainBack", "../imgs/space2.png");
	NoGUI::CImage mainBack = NoGUI::CImage(mainImg);
	mainBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > settingsImg = game.assets.addTexture("setBack", "../imgs/pond1.png");
	NoGUI::CImage settingsBack = NoGUI::CImage(settingsImg);
	settingsBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > joinImg = game.assets.addTexture("joinBack", "../imgs/background.png");
	NoGUI::CImage joinBack = NoGUI::CImage(joinImg);
	std::shared_ptr< Texture2D > hostImg = game.assets.addTexture("hostBack", "../imgs/background2.png");
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
	buttonStyle.align = TextAlign::CENTER;
	NoGUI::CText joinText = inputStyle; // copy
	joinText.align = TextAlign::TOP;
	joinText.margin = (Vector2){0, 0};
	NoGUI::CText hostText = joinText; // copy
	hostText.margin = (Vector2){3, 0};
	NoGUI::CText hostLabelStyle = labelStyle; // copy
	hostLabelStyle.align = NoGUI::TextAlign::LEFT;
	
	// Page 0 (main menu)
	NoGUI::Style mainBackStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
	NoGUI::Style title = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 280}, (Vector2){115, 50}, 4, 0, 0};
	NoGUI::Style onlineStyle = {LIGHTGRAY, BLACK, (Vector2){center.x, center.y - 175}, (Vector2){115, 50}, 4, 1, 0};
	NoGUI::Style offlineStyle = {LIGHTGRAY, BLACK, (Vector2){onlineStyle.pos.x, onlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
	NoGUI::Style settingsStyle = {LIGHTGRAY, BLACK, (Vector2){offlineStyle.pos.x, offlineStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
	NoGUI::Style exitStyle = {LIGHTGRAY, BLACK, (Vector2){settingsStyle.pos.x, settingsStyle.pos.y + 150}, (Vector2){115, 50}, 4, 1, 0};
	
	std::shared_ptr< NoGUI::Element > titleLabel = GUIModel.addElement< NoGUI::Element >(title, "ANDOR", "Label");
	std::shared_ptr< NoGUI::Element > onlineButton = GUIModel.addElement< NoGUI::Button >(onlineStyle, "Play Online", "Button");
	std::shared_ptr< NoGUI::Element > offlineButton = GUIModel.addElement< NoGUI::Button >(offlineStyle, "Play Offline", "Button");
	std::shared_ptr< NoGUI::Element > settingsButton = GUIModel.addElement< NoGUI::Button >(settingsStyle, "Settings", "Button");
	std::shared_ptr< NoGUI::Element > exitButton = GUIModel.addElement< NoGUI::Button >(exitStyle, "Exit", "Button");
	std::shared_ptr< NoGUI::Element > mainBackground = GUIModel.addElement< NoGUI::Element >(mainBackStyle, "", "ALabel");
	
	titleLabel->addComponent< NoGUI::CText >(titleStyle);
	onlineButton->addComponent< NoGUI::CText >(buttonStyle);
	offlineButton->addComponent< NoGUI::CText >(buttonStyle);
	settingsButton->addComponent< NoGUI::CText >(buttonStyle);
	exitButton->addComponent< NoGUI::CText >(buttonStyle);
	mainBackground->addComponent< NoGUI::CImage >(mainBack);
	
	menu.addModel(model);
	game.changeScene(menu);
	game.currentScene().update();
	int res = game.run();

	return res;
}