#pragma once
#include <string>
#include "sfwdraw.h"
#include "AssetLibrary.h"

//Main GameObject
class GameState;

class GameObject
{
public:
	
	static GameState *&gs()
	{
		static GameState *game;
		return game;
	}
	
	std::string textureName; 
	float x, y, width, height, angle; 
	bool isActive;
	bool centered;
	int color;
	std::string animationName;		
	float animTimer;	
	unsigned currentFrame;

	GameObject() :x(400), y(300), width(60),height(60), angle(0),
					currentFrame(0), animTimer(0), isActive(true) {}
	
	
	virtual void draw() 
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, angle, centered, currentFrame, color);
	}

	//Animation Update
	virtual void update()
	{
		animTimer += sfw::getDeltaTime();
		currentFrame = sampleAnimation(textureName, animationName, animTimer);
	}
	//Collision
	virtual void onCollision(GameObject &go, float distance) { }
};

float doCollision(GameObject &go1, GameObject &go2);