#pragma once
#include "../Interface/IUIController.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/TextView.h"
#include "../UIElement/ImageView.h"
#include "../../Gameplay/GameplayService.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace UI::UIElement;
		using namespace Gameplay;

		class GameplayUIController : public Interface::IUIController
		{
		private:

			const float font_size = 40.f;

			const float text_y_position = 36.f;
			const float text_y_pos2 = 76.f;

			const float search_type_text_x_position = 60.f;
			const float comparisons_text_x_position = 687.f;
			const float array_access_text_x_position = 1250.f;
			const float num_sticks_text_x_position = 60.f;
			const float delay_text_x_position = 687.f;
			const float time_complexity_text_x_position = 1250.f;

			const float menu_button_x_position = 1700.f;
			const float menu_button_y_position = 33.f;

			const float menu_button_width = 200.f;
			const float menu_button_height = 100.f;

			TextView* search_type_text;
			TextView* number_of_comparisons_text;
			TextView* number_of_array_access_text;
			TextView* num_sticks_text;
			TextView* delay_text;
			TextView* time_complexity_text;

			ButtonView* menu_button;

			sf::Color font_color = sf::Color::White;

			void setTextValues();
			void updateComarisionText();
			void updateArrayAccessText();
			void updateSearchText();
			void updateDelayText();
			void updateTimeComplexityText();

			void createTexts();
			void initializeMenuButton();
			void MenuButtonCallback();
			void registerButtonCallback();
			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();
			
			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void initializeTextViews();
			void updateTexts();
			void renderTexts();
			void showTexts();
		};

	}
}