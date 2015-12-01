#include "Background.h"
#include "Menu.h"

#include "Globals.h"

void MenuState::update()
{
		space1.update();
		space2.update();
		asteroid1.update();
		asteroid2.update();
		nebula1.update();
		nebula2.update();
		play.update();
		exit.update();
		credits.update();
		planetBob.update();
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < play.x + 64 && sfw::getMouseX() > play.x - 64 && sfw::getMouseY() < play.y + 64 && sfw::getMouseY() > play.y - 64)
			{
				menuSelection = 2;
			}
		}

		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < exit.x + 64 && sfw::getMouseX() > exit.x - 64 && sfw::getMouseY() < exit.y + 64 && sfw::getMouseY() > exit.y - 64)
			{
				menuSelection = 4;
			}
		}
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < credits.x + 64 && sfw::getMouseX() > credits.x - 64 && sfw::getMouseY() < credits.y + 64 && sfw::getMouseY() > credits.y - 64)
			{
				menuSelection = 3;
			}
		}

	}