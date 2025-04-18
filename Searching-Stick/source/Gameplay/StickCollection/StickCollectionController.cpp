#pragma once
#include "../../include/Gameplay/StickCollection/StickCollectionController.h"
#include "../../include/Gameplay/StickCollection/StickCollectionModel.h"
#include "../../include/Gameplay/StickCollection/StickCollectionView.h"
#include "../../include/Gameplay/StickCollection/Stick.h"
#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Global/ServiceLocator.h"
#include <random>


namespace Gameplay
{
	namespace Collections
	{
		using namespace Global;
		using namespace std;

		StickCollectionController::StickCollectionController()
		{
			stick_collection_model = new StickCollectionModel();
			stick_collection_view = new StickCollectionView();

			initializeSticksArray();
		}

		StickCollectionController::~StickCollectionController()
		{
			destroy();
		}

		void StickCollectionController::initializeSticks()
		{
			float rectangle_width = calculateStickWidth();

			for (int i = 0; i < stick_collection_model->number_of_elements; i++)
			{
				float rectangle_height = calculateStickHeight(i);

				sf::Vector2f rectangle_size = sf::Vector2f(rectangle_width, rectangle_height);

				sticks[i]->stick_view->initialize(rectangle_size, sf::Vector2f(0, 0), 0, stick_collection_model->element_color);
			}
		}

		float StickCollectionController::calculateStickWidth()
		{

			float total_space = static_cast<float>(ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);

			float total_spacing = stick_collection_model->space_percentage * total_space;

			float space_between = total_spacing / (stick_collection_model->number_of_elements - 1);
			stick_collection_model->setElementSpacing(space_between);

			float remaining_space = total_space - total_spacing;

			float rectangle_width = remaining_space / stick_collection_model->number_of_elements;

			return rectangle_width;
		}

		void StickCollectionController::updateSticksPosition()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				float x_position = (i * sticks[i]->stick_view->getSize().x) + ((i + 1) * stick_collection_model->elements_spacing);
				float y_position = stick_collection_model->element_y_position - sticks[i]->stick_view->getSize().y;

				sticks[i]->stick_view->setPosition(sf::Vector2f(x_position, y_position));
			}
		}
		
		void StickCollectionController::resetSticksColor()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->setFillColor(stick_collection_model->element_color);
			}
		}
		void StickCollectionController::initializeSticksArray()
		{

			for (int i = 0; i < stick_collection_model->number_of_elements; i++)
			{
				sticks.push_back( new Stick(i));
			}
		}
		float StickCollectionController::calculateStickHeight(int array_pos)
		{
			return (static_cast<float>(array_pos+1)/stick_collection_model->number_of_elements)*stick_collection_model->max_element_height;

		}
		
		void StickCollectionController::resetSearchStick()
		{
			stick_to_search = sticks[rand() % sticks.size()];
			stick_to_search->stick_view->setFillColor(stick_collection_model->search_element_color);
		}

		void StickCollectionController::shuffleSticks()
		{
			random_device device;
			mt19937 default_random_engine(device());

			shuffle(sticks.begin(), sticks.end(), default_random_engine);
		}

		void StickCollectionController::resetVariables()
		{
			number_of_comparisons = 0;
			number_of_array_access = 0;
		}

		void StickCollectionController::destroy()
		{
			if (search_thread.joinable()) search_thread.join();

			for (Stick* s : sticks)
			{
				delete s;
			}
			sticks.clear();
			delete stick_collection_model;
			delete stick_collection_view;
		}

		void StickCollectionController::joinThreads()
		{
			search_thread.join();
		}
		
		void StickCollectionController::initialize()
		{
			stick_collection_model->initialize();

			initializeSticks();
			reset();
		}
		void StickCollectionController::update()
		{
			processSearchThreadState();

			stick_collection_view->update();

			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->update();
			}
		}
		void StickCollectionController::render()
		{

			stick_collection_view->render();

			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->render();
			}
		}
		
		void StickCollectionController::reset()
		{
			current_operation_delay = 0;

			if (search_thread.joinable()) search_thread.join();

			shuffleSticks();
			updateSticksPosition();
			resetSticksColor();
			resetSearchStick();
			resetVariables();
		}

		int StickCollectionController::getNumberOfComparision()
		{
			return number_of_comparisons;
		}

		int StickCollectionController::getNumberOfArrayAccess()
		{
			return number_of_array_access;
		}

		void StickCollectionController::processLinearSearch()
		{
			Sound::SoundService *sound_service = ServiceLocator::getInstance()->getSoundService();
			
			for (int i = 0; i < sticks.size(); i++)
			{
				number_of_array_access++;
				number_of_comparisons++;

				sound_service->playSound(Sound::SoundType::COMPARE_SFX);

				if (sticks[i] == stick_to_search)
				{
					stick_to_search->stick_view->setFillColor(stick_collection_model->found_element_color);
					stick_to_search = nullptr;
					return;
				}
				
				sticks[i]->stick_view->setFillColor(stick_collection_model->processing_element_color);
				
				std::this_thread::sleep_for(std::chrono::milliseconds(current_operation_delay));

				sticks[i]->stick_view->setFillColor(stick_collection_model->element_color);

			}

		}

		void StickCollectionController::processSearchThreadState()
		{
			if (search_thread.joinable() && stick_to_search == nullptr)
			{
				joinThreads();
			}
		}

		void StickCollectionController::searchElement(SearchType search_type)
		{
				this->search_type = search_type;
			switch (search_type)
			{
			case Gameplay::Collections::SearchType::LINEAR_SEARCH:
				
				//time_complexity = "O(n)";
				current_operation_delay = stick_collection_model->linear_search_delay;
				search_thread = std::thread(&StickCollectionController::processLinearSearch, this);
				break;
			case Gameplay::Collections::SearchType::BINARY_SEARCH:
				break;
			default:
				break;
			}
		}

		SearchType StickCollectionController::getSearchType()
		{
			return search_type;
		}
		int StickCollectionController::getNumberOfSticks()
		{
			return sticks.size();
		}
		sf::String StickCollectionController::getTimeComplexity()
		{
			return time_complexity;
		}
		int StickCollectionController::getDelayMillseconds()
		{
			return current_operation_delay;
		}
	}
}
