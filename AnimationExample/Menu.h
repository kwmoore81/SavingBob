#pragma once
#include "Background.h"

class MenuState 
{
	Space space1;
	Space space2;
	Asteroid asteroid1;
	Asteroid asteroid2;
	Nebula nebula1;
	Nebula nebula2;
	Play play;
	Exit exit;
	Credits credits;
	SavingTitle savingTitle;
	BobTitle bobTitle;
	PlanetBob planetBob;


public:
	void menuLayout()
	{
		space2.x = 800;
		asteroid2.x = 2024;
		nebula2.x = 2000;
		nebula2.width = 600;
		nebula2.textureName = "Nebula2";

	}

	virtual void update();

	void draw()
	{
		space1.draw();
		space2.draw();
		planetBob.draw();
		asteroid1.draw();
		asteroid2.draw();
		savingTitle.draw();
		bobTitle.draw();
		nebula1.draw();
		nebula2.draw();
		play.draw();
		exit.draw();
		credits.draw();
	
		sfw::drawTexture(getTexture("Crosshair"), sfw::getMouseX(), sfw::getMouseY(), 64, 64, 0, true, 0, WHITE);
	}
};