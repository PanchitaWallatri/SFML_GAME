#pragma once
/*#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>*/

#include "player.h"
//#include "animations.h"
#include "enermy.h"
//#include "object.h"
#include<map>
#include<sstream>
#include"EndGame.h"

/*class game
{
private:

	//Variable
	float spawnTimer;
	float spawnTimerMax;

	sf::Vector2u imageCount;

	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Font font;
	sf::Text pointtext;

	unsigned points;


	//Private Functions
	void pollEvent();
	void titleWindow();
	void titlePlayer();
	void titleEnermy();
	//void titleObject();
	//void titleFont();
	//void titleText();


	//Game objects

	std::vector<Enermy*> enemies;
	Enermy* enermy;
	Player* player;
	//object* Object;

	sf::RectangleShape* bg1;
	sf::Texture bodyTexture, enermyTexture, bgTexture;
	sf::Sprite* body, enermy1;

public:

	//constructor 
	game();
	void regame();


	//variable
	float deltaTime = 0.f;
	sf::Clock clock;


	//function

	void run();

	void update();
	void render();


	void randomenemies();
	void updateCollision();


};*/

class Game
{
private:
	//window
	sf::RenderWindow* window;
	//player
	Player* player;
	EndGame* highscore;

	//Enemy
	float spawnTimer;
	float spawnTimerMax;


	std::vector<Enemy*> enemies;
	std::vector<Enemy*> items;
	std::vector<Enemy*> items2;


	

	//item_recover
	float spawnTimerItem;
	float spawnTimerItemMax;

	float spawnTimerItem2;
	float spawnTimerItemMax2;

	std::map<std::string, sf::Texture*> texture;
	//std::vector<Bullet*> bullets;

	//GUI
	sf::Font font;
	sf::Text pointText;
	//sf::Text playHP;

	sf::Text GameOver;

	//system
	unsigned Hightscore;
	unsigned point;
	unsigned count = 0;


	//player gui
	sf::RectangleShape playHPBar;
	sf::RectangleShape playHPBarBack;


	//World
	sf::Texture wordBackgound_t;
	sf::Sprite wordBackgound_s;
	sf::Sprite wordBackgound_a;

	void iniWorld();
	void iniWindow(sf::RenderWindow* window);
	void iniTexture();

	void iniGui();

	void inisystem();
	void inisystemHightscore();

	void iniPlayer();
	void iniEnemies();

	void iniItem();
	void iniItem2();

public:
	Game(sf::RenderWindow* window);
	virtual ~Game();

	//Function
	void run();

	void updatePollEvent();
	void updateInput();

	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateHightscore();

	//void updateBullet();
	void updateEnemy();
	void updateitem();
	void updateitem2();
	void updateCombat();
	//void updateCombatitem();

	void update();

	void renderGUI();
	void render();
	void renderWorld();
	void renderHightscore();
};
