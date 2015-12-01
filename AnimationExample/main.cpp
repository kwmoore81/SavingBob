#include "sfwdraw.h"
#include "AssetLibrary.h"
#include "Player.h"
#include <vector>
#include "GameState.h"
#include "Menu.h"
#include "Credits.h"
#include "gameover.h"
#include "Background.h"



void main()
{
	sfw::initContext(800, 600, "Saving Bob");
	sfw::setBackgroundColor(BLACK);

	loadTexture("Space", "../res/space800x600.jpg", 1, 1);
	loadTexture("Asteroid Belt", "../res/asteroidbelt.png", 1, 1);
	loadTexture("Nebula", "../res/nebula.png", 1, 1);
	loadTexture("Nebula2", "../res/nebula2.png", 1, 1);
	loadTexture("Player", "../res/playership.png", 8, 1);
	loadTexture("Bullet", "../res/bullet.png", 1, 1);
	loadTexture("eBullet", "../res/enemyBullet.png", 1, 1);
	loadTexture("Enemy", "../res/enemyship.png", 9, 1);
	loadTexture("Explosion", "../res/explosion.png", 4, 4);
	loadTexture("Play", "../res/PlayBlue.png", 1, 1);
	loadTexture("Exit", "../res/ExitBlue.png", 1, 1);
	loadTexture("Credits", "../res/CreditsBlue.png", 1, 1);
	loadTexture("GameOver", "../res/GameOver.jpg", 1, 1);
	loadTexture("Options", "../res/OptionsBlue.png", 1, 1);
	loadTexture("Crosshair", "../res/crosshair.png", 1, 1);
	loadTexture("SavingTitle", "../res/savingTitle.png", 1, 1);
	loadTexture("BobTitle", "../res/bobTitle.png", 1, 1);
	loadTexture("PlanetBob", "../res/planetBob.png", 5, 4);
	loadTexture("Back", "../res/backButton.png", 1, 1);
	loadTexture("CreditsPage", "../res/Credits.jpg", 1, 1);
	addAnimation("Player", "Thrusters", { 0,1,2,3,4,5,6,7 });
	addAnimation("Enemy", "eThrusters", { 0,1,2,3,4,5,6,7,8 });
	addAnimation("Explosion", "Boom", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 });
	addAnimation("PlanetBob", "Rotation", { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 });

	//The Different Game States
	GameState game;
	MenuState menu;
	CreditsPage creditsPage;
	GameOverPG gameOverPage;
	menu.menuLayout();
	game.start();
	creditsPage.creditsPG();
	gameOverPage.gameOverPG();
	


	while (sfw::stepContext())
	{
		
		//Game State Selection
		switch (menuSelection)
		{
		case 1:
			menu.update();
			menu.draw();
			break;
		case 2:
			game.update();
			game.draw();
			break;
		case 3:
			creditsPage.update();
			creditsPage.draw();
			break;
		case 4:
			sfw::termContext();
			break;
		case 5:
			gameOverPage.update();
			gameOverPage.draw();
		}

		
	}
	sfw::termContext();
}

	

