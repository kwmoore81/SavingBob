#pragma once
#include "GameObject.h"
#include "GameState.h"

//Player Bullet Logic
class Projectile : public Player
{
public:
	float velx, vely; 
	float lifetime; 

	Projectile(float a_x, float a_y, float dx, float dy, float lifespan)
	{
		x = a_x;
		y = a_y;

		velx = dx;
		vely = dy;

		lifetime = lifespan;

		width = 64; height = 64; centered = true; color = WHITE;
		textureName = "Bullet";

	}
	
	//What happens to the bullet on collision
	virtual void onCollision(GameObject &go, float distance)
	{
		isActive = false;
	}
	
	//bullet movement
	virtual void update()
	{
		
		lifetime -= sfw::getDeltaTime();
		isActive = lifetime > 0; 

								 
		x += velx * sfw::getDeltaTime();
		y += vely * sfw::getDeltaTime();
		
	}

	//Draw the bullet
	virtual void draw()
	{
	
		sfw::drawTexture( getTexture("Bullet") , x + 50, y + 4, 64, 64, 0, true, 0, WHITE);
		
	}
	
};
