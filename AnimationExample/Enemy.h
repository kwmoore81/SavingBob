#pragma once
#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "projectiles.h"
#include "eProjectiles.h"



class Enemy : public Player
{
public:
	float eVelx, eVely;
	float eLifetime;

	Enemy(float e_x, float e_y, float ex, float ey, float eLifespan)
	{

		x = e_x;
		y = e_y;

		eVelx = ex;
		eVely = ey;

		eLifetime = eLifespan;
		currentFrame = 0;
		animTimer = 0.25f;
		width = 128; height = 128; centered = true; color = WHITE;
		textureName = "Enemy";
		animationName = "eThrusters";

	}


	virtual void onCollision(GameObject &go, float distance)
	{

		width = 128; height = 128; centered = true; color = WHITE;
		currentFrame = 0;
		animTimer = 0.25f;
		animationName = "Boom";
		textureName = "Explosion";

	}
	virtual void update();
};