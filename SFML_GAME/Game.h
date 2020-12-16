#pragma once


#include "player.h"
#include "enermy.h"
#include<map>
#include<sstream>
#include"EndGame.h"
#include <SFML/Audio.hpp>




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

	int c =0;

	//World
	sf::Texture wordBackgound_t;
	sf::Sprite wordBackgound_1;
	sf::Sprite wordBackgound_2;

	sf::SoundBuffer sound1;
	sf::SoundBuffer sound2;

	sf::Sound soundeffect;
	sf::Sound soundeffect2;
	

	float speed = 100.0f;  // ความเร็วของการเลื่อน 100
	float deltaTime = 0.0f;
	sf::Clock clock;  //ใช้ Clock นับเวลาที่เปลี่ยนไป deltaTime

	void iniWorld();
	void iniSound();
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

	void updateBackground();

	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateHightscore();

	
	void updateEnemy();
	void updateitem();
	void updateitem2();
	void updateCombat();
	

	void update();

	void renderGUI();
	void render();
	void renderWorld();
	void renderHightscore();
};
