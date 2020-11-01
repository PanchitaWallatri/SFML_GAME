#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

#include "Player.h"
#include "animations.h"
//#include "Enermy.h"
//#include "object.h"

class game
{
private:

	//Variable
	/*float spawnTimer;
	float spawnTimerMax;*/

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
	//void titleEnermy();
	//void titleObject();
	//void titleFont();
	//void titleText();


	//Game objects

	//std::vector<Enermy*> enemies;
	//Enermy* enermy;
	Player* player;
	//object* Object;

	sf::RectangleShape* bg1;
	sf::Texture bodyTexture, enermyTexture, sandbarTexture, bgTexture;
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


};
