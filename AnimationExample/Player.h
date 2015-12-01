#pragma once
#include "GameObject.h"
#include "time.h"


class Player : public GameObject
{
public:
	float speed;
	float fireDelay;
	float rateOfFire;
	float eRateOfFire;
	float eFireDelay;
	float eBRateOfFire;
	float eBFireDelay;
	float sdt;
	
	Player() : speed(100), rateOfFire(0.4f), fireDelay(0.f), eRateOfFire(1.5f), eFireDelay(0.f), eBRateOfFire(3.f), eBFireDelay(0.f)
	{
		x = 150; y = 300; width = 128; height = 128; centered = true; color = WHITE;
		animationName = "Thrusters";
		textureName	  = "Player";
		srand(time(NULL));
	}
	
	virtual void onCollision(GameObject &go, float distance)
	{
		if (x > 745){x = 744;}
		if (x < 50 ){x = 51; }
		if (y < 45 ){y = 44; }
		if (y > 550){y = 549;}

		if (go.textureName == "eBullet")
		{
			width = 128; height = 128; centered = true; color = WHITE;
			currentFrame = 0;
			animTimer = 0.25f;
			animationName = "Boom";
			textureName = "Explosion";
		}
	}


	virtual void update();

	
};
