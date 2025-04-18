#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Gameplay/GameplayController.h"
#include "../../include/Gameplay/StickCollection/StickCollectionController.h"
#include <random>

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
		initializeRandomSeed();
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
		stick_collection_controller->reset();
	}

	void GameplayService::initializeRandomSeed()
	{

		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}

	void GameplayService::searchElement(SearchType search_type)
	{
		stick_collection_controller->searchElement(search_type);
	}

	SearchType GameplayService::getCurrentSearchType()
	{
		return stick_collection_controller->getSearchType();
	}

	std::string GameplayService::getTimeComplexity()
	{
		if (getCurrentSearchType() == SearchType::LINEAR_SEARCH)
		{
			return "O(n)";
		}
		return "O(log n)";
	}

	int GameplayService::getNumberOfSticks()
	{
		return stick_collection_controller->getNumberOfSticks();
	}

	int GameplayService::getNumberOfComparisions()
	{
		return stick_collection_controller->getNumberOfComparision();
	}

	int GameplayService::getNumberOfArrayAccess()
	{
		return stick_collection_controller->getNumberOfArrayAccess();
	}

	int GameplayService::getDelay()
	{
		return stick_collection_controller->getDelayMillseconds();
	}

	void GameplayService::destroy()
	{
		delete gameplay_controller;
		delete stick_collection_controller;
	}
}