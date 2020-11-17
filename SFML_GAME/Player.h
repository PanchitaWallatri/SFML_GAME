#pragma once
#include <SFML\Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>
//#include "animations.h"
/*class Player
{
private:
	sf::Texture bodyTexture;
	sf::Sprite body;
	sf::Vector2f velocity;


	//Variable
	unsigned int row;
	float speed;
	int Points;

	//physics
	float velocityMax;
	float accerlerate;


	//Class added
	animations Animationsplayer;


	//function

	void titlePhysics();




public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	const sf::FloatRect getGlobalBounds() const;


	//functions
	void Updateplayer(float deltatime);
	void setPosition();
	void Drawplayer(sf::RenderTarget& target);
	void Sprite();
	void getPoints();
};*/

class Player
{

private:

	sf::Sprite sprite;
	sf::Texture texture;
	

	float MoveSpeed;

	int hp;
	int hpMax;

	float attackCooldown;
	float attackCooldownMax;

	
	

	//Function
	void iniVariable();
	void iniTexture();
	void iniSprite();
	void setupHp(const int hp);
	void loseHp(const int velue);


public:
	Player();
	virtual ~Player();

	//pos player
	const  sf::Vector2f& getpos() const;
	//pos anemy
	const sf::FloatRect getBound() const;
	const int& getHP() const;
	const int& getHPMax() const;
	void setHP(const int hp);
	void loseHP(const int Velue);
	void FillHP(const int Velue);
	void Speedup(const int Velue);

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);

	//animation
	float speedMove;
	float A_x;
	float A_y;
	float P_x = 0;

	//Function
	void move(sf::RenderWindow* window);

	const bool canAttack();
	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);
};

