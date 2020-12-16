#pragma once
#include <SFML\Graphics.hpp>
#include<SFML/System.hpp>
#include<stdio.h>

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

