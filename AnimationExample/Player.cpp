#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

void Player::update()

	{
		float randY = 64 + (rand() % (600 - 128));
		
		fireDelay -= sfw::getDeltaTime();
		eFireDelay -= sfw::getDeltaTime();
		
		// example of switching between animations
		if (sfw::getKey(257) && fireDelay < 0)
		{
			fireDelay = rateOfFire;
			gs()->makeBullet(x, y, 800, 0, 4.f); // Now we can use this to draw stuff!
		}
		if (eFireDelay < 0)
		{
			eFireDelay = eRateOfFire;
			gs()->makeEnemy(850, randY , -100, 0, 10.f); // Now we can use this to draw stuff!
		}
		

		animTimer += sfw::getDeltaTime();
		currentFrame = sampleAnimation(textureName, animationName, animTimer);
		//GameObject::update();
		/*if (animTimer > getAnimationDuration(textureName, animationName))
		{
			animTimer = 0;
			animationName = "Thrusters";
		}*/
		

		sdt = sfw::getDeltaTime() * speed;
		if (sfw::getKey('W')) y += sdt * 3;
		if (sfw::getKey('S')) y -= sdt * 3;
		if (sfw::getKey('A')) x -= sdt * 3;
		if (sfw::getKey('D')) x += sdt * 3;

		}
