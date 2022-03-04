class Characters : public NoECS::EntitySystem
{
public:
	Characters()
		: EntitySystem() {}
	void initialize(std::shared_ptr< NoMEM::MEMManager > assets, std::shared_ptr< NoMVC::View > menu)
	{
		std::shared_ptr< NoECS::Entity > pc = entities.addEntity("Select");
		Vector2 center = {menu->getWindow().width / 2, menu->getWindow().height / 2};
		pc->addComponent< NoECS::CTransform >(center);
		std::shared_ptr< Texture2D > sniperTex = assets->get< Texture2D >("sniper");	
		Rectangle ra = {0, 0, sniperTex->width, sniperTex->height};
		pc->addComponent< NoECS::CSprite >(sniperTex, ra);
	}
};

class CharSelect : public NoMVC::View, public NoGUI::Listener
{
public:
	void addModel(std::shared_ptr< NoMVC::Model > newModel) {NoMVC::View::addModel(newModel);}
	void cleanup() {NoMVC::View::cleanup();}
	int removeModel(size_t index) {NoMVC::View::removeModel(index);}
	void update() {NoMVC::View::update();}
	void render() {NoMVC::View::render();}
	void run() {NoMVC::View::run();}
	void onNotify(std::shared_ptr< NoGUI::Element > elem);
	CharSelect(NoMVC::Controller* g, NoMVC::WindowConfig conf)
		: NoMVC::View(g, conf) 
	{
		std::shared_ptr< Characters > EntityModel = std::make_shared< Characters >();
		EntityModel->initialize(game->assets, game->currentScene());
		addModel(EntityModel);
	}
};

void CharSelect::onNotify(std::shared_ptr< NoGUI::Element > elem)
{
	std::cout << models.size() << std::endl;
	if ( elem->getFocus() )
	{
		NoECS::EntitySystem* world = dynamic_cast< NoECS::EntitySystem* >(models[0].get());
//		std::shared_ptr< NoECS::Entity > entity = world->entities.getEntities().at(0); TODO: causes segfault.
		std::shared_ptr< NoECS::Entity > entity = world->entities.getEntities("Select").at(0);
		NoECS::CSprite& sprite = entity->getComponent< NoECS::CSprite >();
		if ( sprite.texture != game->assets->get< Texture2D >("sniper") )
		{
			sprite.texture = game->assets->get< Texture2D >("sniper");
		}
		else
		{
			sprite.texture = game->assets->get< Texture2D >("akimbo");
		}
	}
}

class CharGUI : public NoGUI::GUIManager
{
public:
	CharGUI()
		: GUIManager(false) {}
	void initialize(std::shared_ptr< NoMEM::MEMManager > assets,  std::shared_ptr< CharSelect > menu)
	{
		addListener(menu);
		
		std::shared_ptr< Texture2D > sniperTex = assets->get< Texture2D >("sniper");
		Vector2 center = {menu->getWindow().width / 2, menu->getWindow().height / 2};
		Vector2 rRadius = {50, 25};
		Vector2 aRadius = {35, 15};
		Vector2 rightPos = {menu->getWindow().width - (sniperTex->width / 4), center.y};
		Vector2 leftPos = {sniperTex->width / 4, center.y};

		std::shared_ptr< NoGUI::Page > elements = addPage(true);
		NoGUI::Style rArrowStyle = {RAYWHITE, BLACK, (Vector2){rRadius.x - 5, 0}, aRadius, 6, 0, 270};
		NoGUI::Style lArrowStyle = {RAYWHITE, BLACK, (Vector2){-1 * rRadius.x + 5, 0}, aRadius, 6, 0, 270};
		NoGUI::Style leftStyle;
		if ( leftPos.x < center.x )
		{
			leftStyle = (NoGUI::Style){RAYWHITE, BLACK, leftPos, rRadius, 4, 0, 0};
		}
		else
		{
			leftStyle = (NoGUI::Style){RAYWHITE, BLACK, (Vector2){rRadius.x * 1.5, center.y}, rRadius, 4, 0, 0};
		}
		NoGUI::Style rightStyle;
		if ( rightPos.x > center.x )
		{
			rightStyle = (NoGUI::Style){RAYWHITE, BLACK, rightPos, rRadius, 4, 0, 0};
		}
		else
		{
			rightStyle = (NoGUI::Style){RAYWHITE, BLACK, (Vector2){menu->getWindow().width - rRadius.x * 1.5, center.y}, rRadius, 4, 0, 0};
		}
//		elements->addComponents("CharArrow", std::make_shared< NoGUI::CContainer >());
//		elements->getComponents("CharArrow")->addComponent< NoGUI::CMultiStyle >(arrowStyle);
		std::shared_ptr< NoGUI::Element > rightArrow = elements->addElement< NoGUI::Button >(rightStyle, "CharArrow", "Right");
		std::shared_ptr< NoGUI::Element > leftArrow = elements->addElement< NoGUI::Button >(leftStyle, "CharArrow", "Left");
		//leftArrow->rotate(180);
		leftArrow->components->addComponent< NoGUI::CMultiStyle >(lArrowStyle);
		rightArrow->components->addComponent< NoGUI::CMultiStyle >(rArrowStyle);
	}
};