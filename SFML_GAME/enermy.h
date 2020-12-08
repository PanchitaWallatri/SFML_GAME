/*#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Enermy
{
private:
	sf::Texture  enermy1Texture;
	sf::Sprite  enermy1;
	sf::Vector2u imageCount;


	animations Animationsenermy;



	unsigned int collum;
	float speed;







public:
	Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	const sf::FloatRect getGlobalBounds() const;

	void UpdateEnermy(float deltaTime);
	void Drawenermy(sf::RenderTarget& target);
	void enermySprite();

	void spawnEnermy(float pos_x, float pos_y);

};*/

#ifndef ENEMY_H
#define ENEMY_H
#include"SFML/Graphics.hpp"

class Enemy
{
private:
	unsigned pointConut;

	sf::Sprite enemy[3];
	sf::Sprite enemies;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;

	sf::Sprite item;
	sf::Sprite item2;

	int type;
	int typeEnemy;
	int typeItem;
	int typeItem2;

	float speed;

	int hp;
	int hpmax;
	int recover;

	int damage;
	int point;

	int addpoint;

	void iniVariation();
	void iniTexture(sf::Sprite sprite);
	//void iniTexture();

public:

	Enemy(float pos_x, float pos_y, int i);
	virtual ~Enemy();

	void Item(int i);
	void Item2(int i);


	const sf::FloatRect getBound() const;
	const sf::FloatRect getBoundItem() const;
	const sf::FloatRect getBoundItem2() const;

	const  sf::Vector2f& getpos() const;
	const  sf::Vector2f& getposItem() const;
	const  sf::Vector2f& getposItem2() const;

	const  int& getPoint() const;
	const  int& getDamage() const;
	const int& getRecover() const;
	const int& Addpoint() const;

	void update();
	void updateItem();
	void updateItem2();

	void render(sf::RenderTarget* target);
	void renderitem(sf::RenderTarget* target);
	void renderitem2(sf::RenderTarget* target);

};

#endif // !ENEMY_H