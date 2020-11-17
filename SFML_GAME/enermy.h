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

	sf::Sprite enemy[4];
	sf::Sprite enemies;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;

	sf::Sprite item;

	int type;
	int typeEnemy;
	int typeItem;

	float speed;

	int hp;
	int hpmax;
	int recover;

	int damage;
	int point;

	void iniVariation();
	void iniTexture(sf::Sprite sprite);
	//void iniTexture();

public:

	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	void Item();

	const sf::FloatRect getBound() const;
	const sf::FloatRect getBoundItem() const;

	const  sf::Vector2f& getpos() const;
	const  sf::Vector2f& getposItem() const;

	const  int& getPoint() const;
	const  int& getDamage() const;
	const int& getRecover() const;

	void update();
	void updateItem();

	void render(sf::RenderTarget* target);
	void renderitem(sf::RenderTarget* target);
};

#endif // !ENEMY_H