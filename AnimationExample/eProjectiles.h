#pragma once
#include "GameObject.h"
#include "GameState.h"


class eProjectile : public Player

{
public:
	float velx, vely; // velocity of our bullet
	float lifetime; // how long it lasts

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

	virtual void onCollision(GameObject &go, float distance)
	{
		isActive = false;
	}

	virtual void update()
	{

		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; // the bullet is no longer active when the lifetime reduces to 0

								 // Euler Integration to move our bullet
		x += velx * sfw::getDeltaTime();
		y += vely * sfw::getDeltaTime();

	}

	virtual void draw()
	{

		sfw::drawTexture(getTexture("eBullet"), x + 50, y + 4, 64, 64, 0, true, 0, WHITE);

	}

};
