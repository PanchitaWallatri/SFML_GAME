//#include <iostream>
#include "enermy.h"

/*Enermy::Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) :
	Animationsenermy(texture, imageCount, switchTime)
{
	this->enermy1Texture = *texture;
	collum = 0;

	this->enermySprite();

	// random positon ในแต่ละครั้งที่ run ได้ (เอาไว้ใช้กับ object ได้ดั)
	//this->enermy1.setPosition(rand() % 500 + 3, rand() % 500 + 5); 


}

const sf::FloatRect Enermy::getGlobalBounds() const
{
	return this->enermy1.getGlobalBounds();
}



void Enermy::UpdateEnermy(float deltaTime)
{
	Animationsenermy.Updateinteract(collum, deltaTime);
	enermy1.setTextureRect(Animationsenermy.uvrect);
	enermy1.move(0.f, 4.f);

}

void Enermy::enermySprite()
{
	this->enermy1.setTexture(this->enermy1Texture);


}



void Enermy::spawnEnermy(float pos_x, float pos_y)
{
	this->enermy1.setPosition(pos_x, pos_y);
}

void Enermy::Drawenermy(sf::RenderTarget& target)
{

	target.draw(this->enermy1);
}*/

void Enemy::iniVariation()
{
	this->pointConut = rand() % 5 + 3; //min = 3 max = 7
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointConut);
	this->damage = this->pointConut;
	this->recover = this->pointConut;
	this->point = this->pointConut;
}

void Enemy::iniTexture(sf::Sprite enemies)
{
	/*this->shape.setRadius(rand() % 20 + 20);
	this->shape.setPointCount(rand() % 20 + 3);
	this->shape.setFillColor(sf::Color(rand()%255+1, rand() % 255 + 1, rand() % 255 + 1, 255));*/

	enemies = this->enemies;

	if (!this->texture1.loadFromFile("D:/gamess/car001.png"))
	{
		printf("NOT ENEMY 1-5");
	}
	if (!this->texture2.loadFromFile("D:/gamess/car001.png"))
	{
		printf("NOT ENEMY 1-5");

	}
	if (!this->texture3.loadFromFile("D:/gamess/car001.png"))
	{
		printf("NOT ENEMY 1-5");
	}
	if (!this->texture4.loadFromFile("D:/gamess/car001.png"))
	{
		printf("NOT ENEMY 1-5");
	}

	this->typeEnemy = rand() % 4;
	//Green
	if (this->typeEnemy == 3)
	{
		this->enemy[3].setTexture(this->texture4);
		//this->enemy[4].setTextureRect(sf::IntRect(0, 0, 115, 100));
		
		this->enemies = this->enemy[3];
		this->speed = static_cast<float>(this->pointConut / 2);
		this->enemies.setScale(1.f, 1.f);
	}
	//Red
	if (this->typeEnemy == 2)
	{
		this->enemy[2].setTexture(this->texture3);
		//this->enemy[3].setTextureRect(sf::IntRect(0, 110, 115, 130));
		
		this->enemies = this->enemy[2];
		this->speed = static_cast<float>(this->pointConut / 2);
		this->enemies.setScale(1.f, 1.f);
	}
	////big stone
	//if (this->typeEnemy == 2)
	//{
	//	this->enemy[2].setTexture(this->texture_e);
	//	this->enemy[2].setTextureRect(sf::IntRect(120,0, 110, 100));

	//	this->enemies = this->enemy[2];
	//	this->speed = static_cast<float>(this->pointConut / 2+2 );
	//}
	//small stone
	if (this->typeEnemy == 1)
	{
		this->enemy[1].setTexture(this->texture1);
		//this->enemy[1].setTextureRect(sf::IntRect(120, 110, 110, 100));

		this->enemies = this->enemy[1];
		this->speed = static_cast<float>(this->pointConut / 2 + 3);
		this->enemies.setScale(1.f, 1.f);
	}
	//
	if (this->typeEnemy == 0)
	{

	}
}

//void Enemy::iniTexture()
//{
//	this->shape.setRadius(this->pointConut);
//	this->shape.setPointCount(this->pointConut);
//	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255)); 
//
//}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item();
	//this->iniTexture();
	//this->shape.setPosition(pos_x, pos_y);
	this->enemies.setPosition(pos_x, pos_y);
	this->item.setPosition(pos_x, pos_y);
}

void Enemy::Item()
{
	this->typeItem = rand() % 100;

	if (this->typeItem == 99)
	{
		this->item.setTexture(this->texture1);
		//this->item.setTextureRect(sf::IntRect(230, 0, 100, 70));
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
	}
}

Enemy::~Enemy()
{
}


const sf::FloatRect Enemy::getBound() const
{
	return this->enemies.getGlobalBounds();
}

const sf::FloatRect Enemy::getBoundItem() const
{
	return this->item.getGlobalBounds();
}

const sf::Vector2f& Enemy::getpos() const
{
	return this->enemies.getPosition();
}

const sf::Vector2f& Enemy::getposItem() const
{
	return this->item.getPosition();
}

const int& Enemy::getPoint() const
{
	return this->point;
}

const int& Enemy::getDamage() const
{
	return this->damage;
}

const int& Enemy::getRecover() const
{
	return this->recover;
}

void Enemy::update()
{
	this->enemies.move(0.f, this->speed);
}

void Enemy::updateItem()
{
	this->item.move(0.f, this->speed);
}

void Enemy::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->enemies);
}

void Enemy::renderitem(sf::RenderTarget* target)
{
	target->draw(this->item);
}