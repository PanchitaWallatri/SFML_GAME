#pragma once
#include "State.h"
#include"game.h"

class GameState :
	public State

{

private:

	//Function
	void iniKeybind();
	void iniTexture();
	void iniPlayer();

	Game* game;


	//window
	sf::RenderWindow* window;
	//player
	Player* player;
	EndGame* highscore;

	//Boss
	

	//Enemy
	float spawnTimer;
	float spawnTimerMax;

	float spawnTimerBuf;
	float spawnTimerMaxBuf;

	std::vector<Enemy*> enemies;
	std::vector<Enemy*> items;
	std::vector<Enemy*> items2;

	//item_recover
	float spawnTimerItem;
	float spawnTimerItemMax;

	float spawnTimerItem2;
	float spawnTimerItemMax2;


	//std::map<std::string, sf::Texture*> texture;
	//std::vector<Bullet*> bullets;

	//std::map<std::string, sf::Texture*> texture1;
	//std::vector<Bullet*> bulletsBuf;
	//std::vector<Bullet*> bulletsBuf2;

	//bullet boss
	//std::map<std::string, sf::Texture*> textureboss;
	//std::vector<Bullet*> bulletsboss;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text GameOver;

	//system
	unsigned Hightscore;
	unsigned point;
	unsigned count = 0;

	//player gui
	sf::RectangleShape playHPBar;
	sf::RectangleShape playHPBarBack;

	//Boss gui
	sf::RectangleShape bossHPBar;
	sf::RectangleShape bossHPBarBack;

	//World
	sf::Texture wordBackgound_t;
	sf::Sprite wordBackgound_s;

public:

	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state);
	virtual ~GameState();

	//Function


	//void endState();

	void updateInput(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);


};
