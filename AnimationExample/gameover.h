#pragma once

#include "Background.h"
#include "Menu.h"


class GameOverPG
{

	GameOverBG gameoverBG;
	Back back;
	Exit exit;

public:
	void gameOverPG()
	{


	}

	void update()
	{
		back.update();
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < back.x + 64 && sfw::getMouseX() > back.x - 64 && sfw::getMouseY() < back.y + 64 && sfw::getMouseY() > back.y - 64)
			{
				menuSelection = 1;
			}
		}
		if (sfw::getMouseButton(MOUSE_BUTTON_LEFT))
		{
			if (sfw::getMouseX() < exit.x + 64 && sfw::getMouseX() > exit.x - 64 && sfw::getMouseY() < exit.y + 64 && sfw::getMouseY() > exit.y - 64)
			{
				menuSelection = 4;
			}
		}
		
	}
	
	
	virtual void draw()
	{
		gameoverBG.draw();
		back.draw();
		exit.draw();

		sfw::drawTexture(getTexture("Crosshair"), sfw::getMouseX(), sfw::getMouseY(), 64, 64, 0, true, 0, WHITE);
	}
};