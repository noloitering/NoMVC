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

int main(int argc, char ** argv)
{	
	Color INVISIBLE = (Color){0, 0, 0, 1};
	Color BACKGROUND = (Color){100, 100, 100, 255};
	
	std::shared_ptr< NoMVC::Controller > game = std::make_shared< NoMVC::Controller >(NoMVC::Controller());
	std::shared_ptr< Menu > menu = std::make_shared< Menu >(game.get(), game->getWindow());
	std::shared_ptr< NoGUI::GUIManager > GUIModel = std::make_shared< NoGUI::GUIManager >(NoGUI::GUIManager());
	GUIModel->addListener(menu);
	
	Vector2 center = (Vector2){game->getWindow().width/2, game->getWindow().height/2};
	// TODO: load this from a file
	std::shared_ptr< Font > font = game->assets.addFont("jupiter_crash", "../fonts/jupiter_crash.png");
	std::shared_ptr< Texture2D > mainImg = game->assets.addTexture("mainBack", "../imgs/space2.png");
	NoGUI::CImage mainBack = NoGUI::CImage(mainImg);
	mainBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > settingsImg = game->assets.addTexture("setBack", "../imgs/pond1.png");
	NoGUI::CImage settingsBack = NoGUI::CImage(settingsImg);
	settingsBack.cropping = NoGUI::Crop::NONE;
	std::shared_ptr< Texture2D > joinImg = game->assets.addTexture("joinBack", "../imgs/background.png");
	NoGUI::CImage joinBack = NoGUI::CImage(joinImg);
	std::shared_ptr< Texture2D > hostImg = game->assets.addTexture("hostBack", "../imgs/background2.png");
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
	NoGUI::CText joinText = inputStyle; // copy
	joinText.align = NoGUI::TextAlign::TOP;
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
	
	std::shared_ptr< NoGUI::Element > titleLabel = GUIModel->addElement< NoGUI::Element >(title, "ANDOR", "Label");
	std::shared_ptr< NoGUI::Element > onlineButton = GUIModel->addElement< NoGUI::Button >(onlineStyle, "Play Online", "Button");
	std::shared_ptr< NoGUI::Element > offlineButton = GUIModel->addElement< NoGUI::Button >(offlineStyle, "Play Offline", "Button");
	std::shared_ptr< NoGUI::Element > settingsButton = GUIModel->addElement< NoGUI::Button >(settingsStyle, "Settings", "Button");
	std::shared_ptr< NoGUI::Element > exitButton = GUIModel->addElement< NoGUI::Button >(exitStyle, "Exit", "Button");
	std::shared_ptr< NoGUI::Element > mainBackground = GUIModel->addElement< NoGUI::Element >(mainBackStyle, "", "ALabel");
	
	titleLabel->addComponent< NoGUI::CText >(titleStyle);
	onlineButton->addComponent< NoGUI::CText >(buttonStyle);
	offlineButton->addComponent< NoGUI::CText >(buttonStyle);
	settingsButton->addComponent< NoGUI::CText >(buttonStyle);
	exitButton->addComponent< NoGUI::CText >(buttonStyle);
	mainBackground->addComponent< NoGUI::CImage >(mainBack);
	
	// Page 1 (online navbar)
	GUIModel->addPage();
	std::shared_ptr< NoGUI::Page > pg = GUIModel->getPage(1);
	
	NoGUI::Style joinStyle = {BACKGROUND, BLACK, (Vector2){25, 50}, (Vector2){25, 30}, 4, 0, 0};
	NoGUI::Style hostStyle = {BACKGROUND, BLACK, (Vector2){joinStyle.pos.x + joinStyle.radius.x * 2 - 4, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
	NoGUI::Style returnStyle = {BACKGROUND, BLACK, (Vector2){menu->getWindow().width - joinStyle.radius.x, joinStyle.pos.y + 8}, (Vector2){25, 30}, 4, 0, 0};
	std::shared_ptr< NoGUI::Element > hostButton = pg->addElement< NoGUI::Button >(hostStyle, "Host", "AButton");
	std::shared_ptr< NoGUI::Element > joinButton = pg->addElement< NoGUI::Button >(joinStyle, "Join", "AButton");
	std::shared_ptr< NoGUI::Element > returnButton = pg->addElement< NoGUI::Button >(returnStyle, "Back", "AButton");
	joinButton->addComponent< NoGUI::CText >(joinText);
	hostButton->addComponent< NoGUI::CText >(hostText);
	returnButton->addComponent< NoGUI::CText >(hostText);
	
	// Page 2 (join)
	GUIModel->addPage();
	pg = GUIModel->getPage(2);
	
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
	// elements
	std::shared_ptr< NoGUI::Element > imgLabel = pg->addElement< NoGUI::Element >(backStyle, "Background", "AImage");
	std::shared_ptr< NoGUI::Element > connectButton = pg->addElement< NoGUI::Button >(connectStyle, "Connect", "Button");
	std::shared_ptr< NoGUI::Element > sendButton = pg->addElement< NoGUI::Button >(sendStyle, "SEND", "Button");
	std::shared_ptr< NoGUI::Element > IPLabel = pg->addElement< NoGUI::Element >(IPStyle, "IP Address:", "Label");
	std::shared_ptr< NoGUI::Element > portLabel = pg->addElement< NoGUI::Element >(portStyle, "Port:", "Label");
	std::shared_ptr< NoGUI::Element > nameLabel = pg->addElement< NoGUI::Element >(nameStyle, "Username:", "Label");
	std::shared_ptr< NoGUI::Element > msgLabel = pg->addElement< NoGUI::Element >(msgStyle, "Message:", "Label");
	std::shared_ptr< NoGUI::Element > IPInput = pg->addElement< NoGUI::Input >(IPInStyle, "", "Input");
	std::shared_ptr< NoGUI::Element > portInput = pg->addElement< NoGUI::Input >(portInStyle, "", "Input");
	std::shared_ptr< NoGUI::Element > nameInput = pg->addElement< NoGUI::Input >(nameInStyle, "", "Input");
	std::shared_ptr< NoGUI::Element > msgInput = pg->addElement< NoGUI::Input >(msgInStyle, "", "Input");
	// components
	IPLabel->addComponent< NoGUI::CText >(labelStyle);
	portLabel->addComponent< NoGUI::CText >(labelStyle);
	nameLabel->addComponent< NoGUI::CText >(labelStyle);
	msgLabel->addComponent< NoGUI::CText >(labelStyle);
	connectButton->addComponent< NoGUI::CText >(buttonStyle);
	sendButton->addComponent< NoGUI::CText >(buttonStyle);
	joinButton->addComponent< NoGUI::CText >(joinText);
	hostButton->addComponent< NoGUI::CText >(hostText);
	imgLabel->addComponent< NoGUI::CImage >(joinBack);
	IPInput->addComponent< NoGUI::CText >(inputStyle);
	portInput->addComponent< NoGUI::CText >(inputStyle);
	nameInput->addComponent< NoGUI::CText >(inputStyle);
	msgInput->addComponent< NoGUI::CText >(inputStyle);
	IPInput->addComponent< NoGUI::CInput >(50);
	portInput->addComponent< NoGUI::CInput >(10);
	nameInput->addComponent< NoGUI::CInput >(50);
	msgInput->addComponent< NoGUI::CInput >(200);
	
	// Page 3 (host)
	GUIModel->addPage();
	pg = GUIModel->getPage(3);
	
	NoGUI::Style FFStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style lootStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style playerStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style cheatStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style cheatInStyle = {LIGHTGRAY, BLACK, (Vector2){cheatStyle.pos.x, cheatStyle.pos.y + 30}, (Vector2){112, 25}, 4, 2, 0};
	NoGUI::Style enterStyle = {GREEN, BLACK, (Vector2){center.x - cheatStyle.radius.x - 25, cheatStyle.pos.y + 30}, (Vector2){25, 25}, 4, 1, 0};
	NoGUI::Style serverStyle = {GRAY, BLACK, (Vector2){center.x, center.y + 225}, (Vector2){115, 50}, 4, 1, 0};
	// elements
	std::shared_ptr< NoGUI::Element > hostImgLabel = pg->addElement< NoGUI::Element >(backStyle, "Background", "AImage");
	std::shared_ptr< NoGUI::Element > serverButton = pg->addElement< NoGUI::Button >(serverStyle, "Host", "Button");
	std::shared_ptr< NoGUI::Element > enterButton = pg->addElement< NoGUI::Button >(enterStyle, "ENTER", "Button"); // TODO: fix alignment bug
	std::shared_ptr< NoGUI::Element > FFLabel = pg->addElement< NoGUI::Element >(FFStyle, "Friendly Fire", "Label");
	std::shared_ptr< NoGUI::Element > lootLabel = pg->addElement< NoGUI::Element >(lootStyle, "Loot Style", "Label");
	std::shared_ptr< NoGUI::Element > playerLabel = pg->addElement< NoGUI::Element >(playerStyle, "Character", "Label");
	std::shared_ptr< NoGUI::Element > cheatLabel = pg->addElement< NoGUI::Element >(cheatStyle, "Cheat Codes:", "Label");
	std::shared_ptr< NoGUI::Element > cheatInput = pg->addElement< NoGUI::Input >(cheatInStyle, "", "Input");
	// components
	hostImgLabel->addComponent< NoGUI::CImage >(hostBack);
	FFLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	lootLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	playerLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	cheatLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	serverButton->addComponent<NoGUI::CText>(buttonStyle);
	enterButton->addComponent<NoGUI::CText>(buttonStyle);
	cheatInput->addComponent< NoGUI::CText >(inputStyle);
	cheatInput->addComponent< NoGUI::CInput >(50);
	
	// Page 4 (settings)
	GUIModel->addPage();
	pg = GUIModel->getPage(4);
	
	NoGUI::Style setBackStyle = {BACKGROUND, BLACK, (Vector2){center.x, center.y}, (Vector2){center.x, center.y}, 4, 0, 0};
	NoGUI::Style vsyncStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 250}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style fullStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 200}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style AAStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 150}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style resStyle = {INVISIBLE, BLACK, (Vector2){center.x, center.y - 50}, (Vector2){112, 25}, 4, 0, 0};
	NoGUI::Style mainStyle = {BACKGROUND, BLACK, (Vector2){menu->getWindow().width - 25,  20}, (Vector2){25, 18}, 4, 0, 0};
	
	std::shared_ptr< NoGUI::Element > vsyncLabel = pg->addElement< NoGUI::Element >(vsyncStyle, "Vsync", "Label");
	std::shared_ptr< NoGUI::Element > fullLabel = pg->addElement< NoGUI::Element >(fullStyle, "Fullscreen", "Label");
	std::shared_ptr< NoGUI::Element > AALabel = pg->addElement< NoGUI::Element >(AAStyle, "Anti Aliasing", "Label");
	std::shared_ptr< NoGUI::Element > resLabel = pg->addElement< NoGUI::Element >(resStyle, "Resolution", "Label");
	std::shared_ptr< NoGUI::Element > mainButton = pg->addElement< NoGUI::Button >(mainStyle, "Back", "Button");
	std::shared_ptr< NoGUI::Element > setBackground = pg->addElement< NoGUI::Element >(mainBackStyle, "", "ALabel");
	
	vsyncLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	fullLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	AALabel->addComponent< NoGUI::CText >(hostLabelStyle);
	resLabel->addComponent< NoGUI::CText >(hostLabelStyle);
	mainButton->addComponent< NoGUI::CText >(buttonStyle);
	setBackground->addComponent< NoGUI::CImage >(settingsBack);
	
	std::shared_ptr< NoMVC::Model > model = GUIModel;
	std::shared_ptr< NoMVC::View > view = menu;
	menu->addModel(model);
	game->changeScene(menu);
	game->currentScene()->update();
	int res = game->run();

	return res;
}