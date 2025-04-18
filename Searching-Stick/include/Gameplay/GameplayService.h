#pragma once
#include "StickCollection/StickCollectionController.h"
#include "StickCollection/StickCollectionModel.h"

namespace Gameplay
{
	using namespace Collections;

	class GameplayController;
	
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		StickCollectionController* stick_collection_controller;
		void destroy();

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void reset();

		void initializeRandomSeed();

		void searchElement(SearchType search_type);

		SearchType getCurrentSearchType();

		int getNumberOfSticks();
	};
}