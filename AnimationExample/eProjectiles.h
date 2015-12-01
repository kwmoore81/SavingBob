#pragma once
#include "GameObject.h"
#include "GameState.h"

//Enemy Bullet Logic
class eProjectile : public Player

{
public:
	float velx, vely; 
	float lifetime; 

	eProjectile(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		x = a_x;
		y = a_y;

		velx = dx;
		vely = dy;

		lifetime = lifespan;

		width = 64; height = 64; centered = true; color = WHITE;
		textureName = "eBullet";

	}

	//Bullet Collision
	virtual void onCollision(GameObject &go, float distance)
	{
		isActive = false;
	}

	virtual void update()
	{

		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; 

		x += velx * sfw::getDeltaTime();
		y += vely * sfw::getDeltaTime();

	}

	//Draw the Bullets
	virtual void draw()
	{

		sfw::drawTexture(getTexture("eBullet"), x + 50, y + 4, 64, 64, 0, true, 0, WHITE);

	}

};
