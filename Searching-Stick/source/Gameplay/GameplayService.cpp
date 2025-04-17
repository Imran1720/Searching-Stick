#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Gameplay/GameplayController.h"

namespace Gameplay
{
	

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		destroy();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
	}

	void GameplayService::searchElement(SearchType search_type)
	{

	}

	SearchType GameplayService::getCurrentSearchType()
	{
		return stick_collection_controller->getSearchType();
	}

	int GameplayService::getNumberOfSticks()
	{
		return stick_collection_controller->getNumberOfSticks();
	}

	void GameplayService::destroy()
	{
		delete gameplay_controller;
	}
}