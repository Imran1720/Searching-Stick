#include "../../include/Gameplay/GameplayView.h"
#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"


namespace Gameplay
{
	using namespace Global;

	GameplayView::GameplayView()
	{
		gameplay_controller = nullptr;
		background_image = new ImageView();
	}

	GameplayView::~GameplayView()
	{
		destroy();
	}

	void GameplayView::initialize(GameplayController* controller)
	{
		gameplay_controller = controller;

		initializeBackground();
	}

	void GameplayView::update()
	{
		background_image->update();
	}

	void GameplayView::render()
	{
		background_image->render();
	}

	void GameplayView::initializeBackground()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		background_image->initialize(Config::background_texture_path, game_window->getSize().x,
			game_window->getSize().y, sf::Vector2f(0, 0));

		background_image->setImageAlpha(background_image_alpha);
	}

	void GameplayView::destroy()
	{
		delete gameplay_controller;
	}
}