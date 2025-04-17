#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Gameplay/GameplayController.h"
#include "../../include/Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay
{
	using namespace Collections;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		stick_collection_controller = new StickCollectionController();
	}

	GameplayService::~GameplayService()
	{
		destroy();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		stick_collection_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
		stick_collection_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		stick_collection_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		//stick_collection_controller->reset();
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
		delete stick_collection_controller;
	}
}