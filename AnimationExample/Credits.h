#pragma once
#include "Background.h"
#include "Globals.h"


class CreditsPage 
{
	
	CreditsBG creditsBG;
	Back back;
	
public:
	void creditsPG()
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

	}
	void draw()
	{
		creditsBG.draw();
		back.draw();
		
		sfw::drawTexture(getTexture("Crosshair"), sfw::getMouseX(), sfw::getMouseY(), 64, 64, 0, true, 0, WHITE);
	}
};