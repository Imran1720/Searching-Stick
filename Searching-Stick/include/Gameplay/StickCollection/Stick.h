#pragma once
#include "UI/UIElement/RectangleShapeView.h"

namespace Gameplay
{
	namespace Collections
	{
		using namespace UI::UIElement;

		struct Stick
		{
			int data;
			RectangleShapeView* stick_view;

			Stick() {}
			Stick(int data)
			{
				this->data = data;
				stick_view = new RectangleShapeView();
			}
			~Stick()
			{
				delete stick_view;
			}
		};
	}
}