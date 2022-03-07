
void loadAssets(std::shared_ptr< NoMVC::Controller > game)
{
	game->sfx->adjustMaster(1);
	std::shared_ptr< Font > font = game->assets->addFont("jupiter_crash", "../fonts/jupiter_crash.png");
	std::shared_ptr< NoMEM::Sprite > sniperSprite = game->assets->addSprite("sniper", "../sprites/sniper.png", 1);
	std::shared_ptr< NoMEM::Sprite > akimboSprite = game->assets->addSprite("akimbo", "../sprites/akimbo.png", 1);
	std::shared_ptr< Texture2D > mainImg = game->assets->addTexture("mainBack", "../imgs/space2.png");
	std::shared_ptr< Texture2D > settingsImg = game->assets->addTexture("setBack", "../imgs/pond1.png");
	std::shared_ptr< Texture2D > joinImg = game->assets->addTexture("joinBack", "../imgs/background.png");
	std::shared_ptr< Texture2D > hostImg = game->assets->addTexture("hostBack", "../imgs/background2.png");
	std::shared_ptr< Music > titleSong = game->assets->addMusic("title", "../audio/title.wav");
	std::shared_ptr< Sound > focusSound = game->assets->addSound("click", "../audio/click.wav");
	std::shared_ptr< Sound > toggleSound = game->assets->addSound("switch", "../audio/switch.wav");
}