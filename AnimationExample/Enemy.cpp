#include "GameObject.h"
#include "GameState.h"
#include "Player.h"
#include "projectiles.h"
#include "eProjectiles.h"


void Enemy::update()
{
	eBFireDelay -= sfw::getDeltaTime();

	eLifetime -= sfw::getDeltaTime();
	isActive = eLifetime > 0;


	x += eVelx * sfw::getDeltaTime();
	y += eVely * sfw::getDeltaTime();

	animTimer += sfw::getDeltaTime();
	currentFrame = sampleAnimation(textureName, animationName, animTimer);


	x--;

	if (eBFireDelay < 0 && textureName != "Explosion")
	{
		
		eBFireDelay = eBRateOfFire;
		gs()->makeEBullet(x - 100, y - 4, -400, 0, 4.f); // Now we can use this to draw stuff!
	}
}


