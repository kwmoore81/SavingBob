#pragma once
#include "Player.h"
#include "Enemy.h"
#include "projectiles.h"
#include "eProjectiles.h"
#include "Background.h"
#include <vector>
#include "Menu.h"
#include "Globals.h"

//Main Game State
class GameState
{
	Player player; 	
	Border border;
	Space space1;
	Space space2;
	Asteroid asteroid1;
	Asteroid asteroid2;
	Nebula nebula1;
	Nebula nebula2;
	Player playership;
	PlanetBob planetBob;
	std::vector<Enemy> enemyships;
	std::vector<Projectile> bullets;
	std::vector<eProjectile> eBullets;
	
public:
	void start()
	{
		space2.x = 800;
		asteroid2.x = 2024;
		nebula2.x = 2000;
		nebula2.width = 600;
		nebula2.textureName = "Nebula2";
		
	}

	// Parameters may match the constructor for the bullet
	void makeBullet(float x, float y, float dx, float dy, float lifespan)
	{
		for (int i = 0; i < bullets.size(); ++i)
		{
			if (!bullets[i].isActive) 
			{
				bullets[i] = Projectile(x, y, dx, dy, lifespan);
				return;
			}
		}
		// if there is no empty spot, generate a new bullet into the vector
		bullets.push_back(Projectile(x, y, dx, dy, lifespan));
	}

	void makeEBullet(float x, float y, float dx, float dy, float lifespan)
	{
		for (int i = 0; i < eBullets.size(); ++i)
		{
			if (!eBullets[i].isActive) 
			{
				eBullets[i] = eProjectile(x, y, dx, dy, lifespan);
				return;
			}
		}
		
		eBullets.push_back(eProjectile(x, y, dx, dy, lifespan));
	}
	
	//Spawn Enemy's
	void makeEnemy(float x, float y, float dx, float dy, float lifespan)
	{
		for (int i = 0; i < enemyships.size(); ++i)
		{
			if (!enemyships[i].isActive) 
			{
				enemyships[i] = Enemy(x, y, dx, dy, lifespan);
				return;
			}
		}		
		enemyships.push_back(Enemy(x, y, dx, dy, lifespan));
	}


	
	GameState()
	{
		GameObject::gs() = this;
	}
	
	void update()
	{
		space1.update();
		space2.update();
		asteroid1.update();
		asteroid2.update();
		nebula1.update();
		nebula2.update();
		planetBob.update();

		if (player.isActive)
			playership.update();

		// Player Bullets
		int nBulletsActive = 0;
		int nEBulletsActive = 0;

		for (int i = 0; i < bullets.size(); ++i)
			if (bullets[i].isActive)
			{
				bullets[i].update();

			}
			else nBulletsActive++;

			//Enemy Bullets
			for (int i = 0; i < eBullets.size(); ++i)
				if (eBullets[i].isActive)
				{
					eBullets[i].update();
					if (playership.textureName != "Explosion")
					{
						doCollision(eBullets[i], playership);
					}
				}
				else nEBulletsActive++;

				//Enemy Ships
				int nEnemyshipsActive = 0;

				if (nEnemyshipsActive == 0)
				{
					for (int i = 0; i < enemyships.size(); ++i)
					{
						if (enemyships[i].isActive)
						{
							enemyships[i].update();

							for (int j = 0; j < bullets.size(); ++j)

							{
								if (bullets[j].isActive && enemyships[i].textureName != "Explosion")
								{
									doCollision(enemyships[i], bullets[j]);

								}

							}
						}
					}
				}
				else nEnemyshipsActive++;


				doCollision(border, playership);

	}

	// Draw Stuff
	void draw()
	{
		space1.draw();
		space2.draw();
		planetBob.draw();
		asteroid1.draw();
		asteroid2.draw();
		nebula1.draw();
		nebula2.draw();

		
		
		//Draw Bullets
		for (int i = 0; i < bullets.size(); ++i)
			if (bullets[i].isActive)
				bullets[i].draw();

		//Draw Enemy Ship Explosion
		for (int i = 0; i < enemyships.size(); ++i)
		{
			if (enemyships[i].isActive)
				enemyships[i].draw();

			if (enemyships[i].textureName == "Explosion")
			{
				if (enemyships[i].currentFrame == 15)
				{

					enemyships[i].isActive = false;

				}

			}


		}


		for (int i = 0; i < eBullets.size(); ++i)
		{
			if (eBullets[i].isActive)
				eBullets[i].draw();
		}

		//playership explosion
		if (player.isActive)
		{
			playership.draw();
			if (playership.textureName == "Explosion")
			{
				if (playership.currentFrame == 15)
				{

					playership.isActive = false;
				
						menuSelection = 5;

				}

			}
		}
		
		
	}
	
	
};