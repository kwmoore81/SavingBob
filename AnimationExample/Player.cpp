#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

//Player Update Logic
void Player::update()

	{
		float randY = 64 + (rand() % (600 - 128));
		
		fireDelay -= sfw::getDeltaTime();
		eFireDelay -= sfw::getDeltaTime();
		
		//Fire!!!
		if (sfw::getKey(257) && fireDelay < 0)
		{
			fireDelay = rateOfFire;
			gs()->makeBullet(x, y, 800, 0, 4.f);
		}
		if (eFireDelay < 0)
		{
			eFireDelay = eRateOfFire;
			gs()->makeEnemy(850, randY , -100, 0, 10.f); 
		}
		
		//Player Animation
		animTimer += sfw::getDeltaTime();
		currentFrame = sampleAnimation(textureName, animationName, animTimer);
		

		//Player Movment
		sdt = sfw::getDeltaTime() * speed;
		if (sfw::getKey('W')) y += sdt * 3;
		if (sfw::getKey('S')) y -= sdt * 3;
		if (sfw::getKey('A')) x -= sdt * 3;
		if (sfw::getKey('D')) x += sdt * 3;

		}
