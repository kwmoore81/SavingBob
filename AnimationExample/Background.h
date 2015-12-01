#pragma once
#include "GameObject.h"
#include"Player.h"


class Space : public GameObject
{
public:

	Space()
	{
		x = 0; y = 600; width = 800; height = 600; centered = false; color = WHITE;
		textureName = "Space";

	}
	virtual void update()
	{

		x -= 1;

		if (x <= -width)
		{
			x = width;
		}
	}
	};
class CreditsBG : public GameObject
{
public:

	CreditsBG()
	{
		x = 400; y = 300; width = 800; height = 600; centered = true; color = WHITE;
		textureName = "CreditsPage";

	}
	virtual void update()
	{

		
	}
};
class PlanetBob : public GameObject
{
public:

	PlanetBob()
	{
		x = 275; y = 350; width = 128; height = 128;  centered = true; color = WHITE;
		
		textureName = "PlanetBob";
		animationName = "Rotation";

	}
	virtual void update()
	{
		GameObject::update();
		if (animTimer > getAnimationDuration(textureName, animationName))
		{
			animTimer = 0;
			animationName = "Rotation";
		}
		
	}
};

class Asteroid : public GameObject
{
public:

	Asteroid()
	{
		x = 0; y = 600; width = 2024; height = 600; centered = false; color = 0x777700ff;
		textureName = "Asteroid Belt";

	}
	virtual void update()
	{

		x -= 3;

		if (x <= -width)
		{
			x = 800;
		}
	}
};

class Nebula : public GameObject
{
public:

	Nebula()
	{
		x = 0; y = 600; width = 1250; height = 600; centered = false; color = 0xffffff22;
		textureName = "Nebula";

	}
	virtual void update()
	{

		x -= 8;

		if (x <= -width)
		{
			x = width;
		}
	}
};

class Border : public GameObject
{
public:

	Border()
	{
		width = 800; height = 600; centered = true;
	}

};

class Play : public GameObject
{
public:

	Play()
	{
		x = 400; y = 150; width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Play";

	}
	virtual void update()
	{

		
	}
};

class Exit : public GameObject
{
public:

	Exit()
	{
		x = 740; y = 50; width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Exit";

	}
	virtual void update()
	{
		

	}
};

class Credits : public GameObject
{
public:

	Credits()
	{
		x = 60; y = 50; width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Credits";

	}
	virtual void update()
	{


	}
};
class GameOverBG : public GameObject
{
public:

	GameOverBG()
	{
		x = 400; y = 300; width = 800; height = 600; centered = true; color = WHITE;
		textureName = "GameOver";

	}
	virtual void update()
	{


	}
};
class SavingTitle : public GameObject
{
public:

	SavingTitle()
	{
		x = 400; y = 500; width = 600; height = 142; centered = true; color = WHITE;
		textureName = "SavingTitle";

	}
	virtual void update()
	{


	}
};

class BobTitle : public GameObject
{
public:

	BobTitle()
		{
			x = 580; y = 350; width = 349; height = 179; centered = true; color = WHITE;
			textureName = "BobTitle";

		}
		virtual void update()
		{


		}
};

class Back : public GameObject
{
public:

	Back()
	{
		x = 90; y = 570; width = 177; height = 50; centered = true; color = WHITE;
		textureName = "Back";

	}
	virtual void update()
	{


	}
};
