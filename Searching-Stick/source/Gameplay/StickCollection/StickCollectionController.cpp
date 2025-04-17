#include "../../include/Gameplay/StickCollection/StickCollectionController.h"
#include "../../include/Gameplay/StickCollection/StickCollectionModel.h"
#include "../../include/Gameplay/StickCollection/StickCollectionView.h"

namespace Gameplay
{
	namespace Collections
	{

		StickCollectionController::StickCollectionController()
		{
		}

		StickCollectionController::~StickCollectionController()
		{
			destroy();
		}

		void StickCollectionController::initializeSticks()
		{
		}
		float StickCollectionController::calculateStickWidth()
		{
			return 0.0f;
		}
		void StickCollectionController::updateSticksPosition()
		{
		}
		void StickCollectionController::resetSticksColor()
		{
		}
		void StickCollectionController::initializeSticksArray()
		{
		}
		float StickCollectionController::calculateStickHeight(int array_pos)
		{
			return 0.0f;
		}
		void StickCollectionController::destroy()
		{
			delete stick_collection_model;
			delete stick_collection_view;

			for (Stick* s : sticks)
			{
				delete s;
			}
		}
		
		void StickCollectionController::initialize()
		{
		}
		void StickCollectionController::update()
		{
			
		}
		void StickCollectionController::render()
		{
		}
		SearchType StickCollectionController::getSearchType()
		{
			return search_type;
		}
		int StickCollectionController::getNumberOfSticks()
		{
			return sticks.size();
		}
	}
}
