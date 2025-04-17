#pragma once
#include "UI/UIElement/ImageView.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
	using namespace UI::UIElement;

	class GameplayController;
	class GameplayView
	{
	private:
		GameplayController* gameplay_controller;
		ImageView* background_image;
		const float background_image_alpha = 55;

		sf::Font text_font;
		
		void initializeBackground();
		void destroy();

	public:
		GameplayView();
		~GameplayView();

		void initialize(GameplayController* controller);
		void update();
		void render();

	};
}