#include "../../include/UI/GameplayUI/GameplayUIController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Global/Config.h"
#include "../../include/Main/GameService.h"
#include <iostream>

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace Main;

		GameplayUIController::GameplayUIController()
		{
			createTexts();
			menu_button = new ButtonView();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			initializeTextViews();
			setTextValues();
			initializeMenuButton();
			registerButtonCallback();
		}
		void GameplayUIController::update()
		{
			updateTexts();
			menu_button->update();
		}
		void GameplayUIController::render()
		{
			renderTexts();
			menu_button->render();
		}
		void GameplayUIController::show()
		{
			showTexts();
			menu_button->show();
		}

		void GameplayUIController::initializeTextViews()
		{
			search_type_text->initialize("search_type_text",
				sf::Vector2f(search_type_text_x_position,text_y_position),
				FontType::BUBBLE_BOBBLE,
				font_size, 
				sf::Color::White);
			
			
			number_of_comparisons_text->initialize("number_of_comparisons_text",
				sf::Vector2f(comparisons_text_x_position, text_y_position),
				FontType::BUBBLE_BOBBLE,
				font_size,
				sf::Color::White);
			
			number_of_array_access_text->initialize("number_of_array_accesstext",
				sf::Vector2f(array_access_text_x_position, text_y_position),
				FontType::BUBBLE_BOBBLE, 
				font_size, 
				sf::Color::White);

			num_sticks_text->initialize("num_stickstext",
				sf::Vector2f(num_sticks_text_x_position, text_y_pos2), 
				FontType::BUBBLE_BOBBLE,
				font_size,
				sf::Color::White);

			delay_text->initialize("delay_text",
				sf::Vector2f(delay_text_x_position, text_y_pos2),
				FontType::BUBBLE_BOBBLE, 
				font_size, 
				sf::Color::White);

			time_complexity_text->initialize("time_complexity_text",
				sf::Vector2f(time_complexity_text_x_position, text_y_pos2),
				FontType::BUBBLE_BOBBLE, 
				font_size, 
				sf::Color::White);
		}

		void GameplayUIController::updateTexts()
		{
			search_type_text->update();
			updateComarisionText();
			updateArrayAccessText();
			num_sticks_text->update();
			delay_text->update();
			time_complexity_text->update();

		}

		void GameplayUIController::renderTexts()
		{
			search_type_text->render();
			number_of_comparisons_text->render();
			number_of_array_access_text->render();
			num_sticks_text->render();
			delay_text->render();
			time_complexity_text->render();
		}

		void GameplayUIController::showTexts()
		{
			search_type_text->show();
			number_of_comparisons_text->show();
			number_of_array_access_text->show();
			num_sticks_text->show();
			delay_text->show();
			time_complexity_text->show();
		}

		void GameplayUIController::setTextValues()
		{
			GameplayService* gameplay_service = ServiceLocator::getInstance()->getGameplayService();
			search_type_text->setText("Linear Search");
			number_of_comparisons_text->setText("Comparisions : 0");
			number_of_array_access_text->setText("Array Access : 0");
			num_sticks_text->setText("Number of Sticks : "+ std::to_string(gameplay_service->getNumberOfSticks()));
			delay_text->setText("Delay : "+ std::to_string(gameplay_service->getDelay()));
			time_complexity_text->setText("Time Compexity : "+ gameplay_service->getTimeComplexity());

		}

		void GameplayUIController::updateComarisionText()
		{
			int count = ServiceLocator::getInstance()->getGameplayService()->getNumberOfComparisions();
			number_of_comparisons_text->setText("Comparisions : "+std::to_string(count));
			number_of_comparisons_text->update();

		}

		void GameplayUIController::updateArrayAccessText()
		{
			int count = ServiceLocator::getInstance()->getGameplayService()->getNumberOfArrayAccess();
			number_of_array_access_text->setText("Array Access  : " + std::to_string(count));
			number_of_array_access_text->update();
		}

		void GameplayUIController::createTexts()
		{
			search_type_text = new TextView();
			number_of_comparisons_text = new TextView();
			number_of_array_access_text = new TextView();
			num_sticks_text = new TextView();
			delay_text = new TextView();
			time_complexity_text = new TextView();
		}

		void GameplayUIController::initializeMenuButton()
		{
			menu_button->initialize("Menu Button",
				Config::menu_button_texture_path,
				menu_button_width,
				menu_button_height,
				sf::Vector2f(menu_button_x_position, menu_button_y_position));

		}

		void GameplayUIController::MenuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGameplayService()->reset();
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void GameplayUIController::registerButtonCallback()
		{
			menu_button->registerCallbackFuntion(std::bind(&GameplayUIController::MenuButtonCallback, this));
		}

		void GameplayUIController::destroy()
		{
			delete search_type_text;
			delete number_of_comparisons_text;
			delete number_of_array_access_text;
			delete num_sticks_text;
			delete delay_text;
			delete time_complexity_text;
		}
	}
}