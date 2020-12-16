#include "enermy.h"



void Enemy::iniVariation()
{
	this->pointConut = rand() % 5 +3; 
	this->type = 0;
	this->speed = static_cast<float>(this->pointConut);
	this->hp = this->hpmax;
	this->hpmax = static_cast<float>(this->pointConut);
	this->damage = this->pointConut;
	this->recover = this->pointConut;
	this->point = this->pointConut;
	this->addpoint = this->pointConut;
}

void Enemy::iniTexture(sf::Sprite enemies)
{
	

	enemies = this->enemies;

	if (!this->texture1.loadFromFile("pic/car001.png"))
	{
		printf("NOT ENEMY 1");
	}
	if (!this->texture2.loadFromFile("pic/car002.png"))
	{
		printf("NOT ENEMY 2");

	}
	if (!this->texture3.loadFromFile("pic/car003.png"))
	{
		printf("NOT ENEMY 3");
	}
	if (!this->texture4.loadFromFile("pic/bone.png"))
	{
		printf("NOT ENEMY 4");
	}
	if (!this->texture5.loadFromFile("pic/coin.png"))
	{
		printf("NOT ENEMY 5");
	}
	

	this->typeEnemy = rand() % 3;
	
	if (this->typeEnemy == 2)
	{
		this->enemy[2].setTexture(this->texture3);
		
		
		this->enemies = this->enemy[2];
		this->speed = static_cast<float>(this->pointConut / 2);
		this->enemies.setScale(1.f, 1.f);
		
	}
	
	if (this->typeEnemy == 1)
	{
		this->enemy[1].setTexture(this->texture2);
		
		
		this->enemies = this->enemy[1];
		this->speed = static_cast<float>(this->pointConut / 2);
		this->enemies.setScale(1.f, 1.f);
	}
	
	if (this->typeEnemy == 0)
	{
		this->enemy[0].setTexture(this->texture1);
		

		this->enemies = this->enemy[0];
		this->speed = static_cast<float>(this->pointConut / 2);
		this->enemies.setScale(1.f, 1.f);
	}
	
	
}



Enemy::Enemy(float pos_x, float pos_y, int i)
{
	this->iniVariation();
	this->iniTexture(enemies);
	this->Item(i);
	this->Item2(i);
	
	this->enemies.setPosition(pos_x, pos_y);
	this->item.setPosition(pos_x, pos_y);
	this->item2.setPosition(pos_x, pos_y);
}

void Enemy::Item(int i)
{
	this->typeItem = rand() % i;

	if (this->typeItem == 0)
	{
		this->item.setTexture(this->texture4);
		
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item.setScale(.7f, .7f);
	}
}
void Enemy::Item2(int i)
{
	this->typeItem2 = rand() % i;

	if (this->typeItem2 == 0)
	{
		this->item2.setTexture(this->texture5);
		
		this->speed = static_cast<float>(this->pointConut / 2 + 1);
		this->item2.setScale(.7f, .7f);
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

const sf::FloatRect Enemy::getBoundItem2() const
{
	return this->item2.getGlobalBounds();
}

const sf::Vector2f& Enemy::getpos() const
{
	return this->enemies.getPosition();
}

const sf::Vector2f& Enemy::getposItem() const
{
	return this->item.getPosition();
}

const sf::Vector2f& Enemy::getposItem2() const
{
	return this->item2.getPosition();
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
const int& Enemy::Addpoint() const
{
	return this->addpoint;
}

void Enemy::update()
{
	this->enemies.move(0.f, this->speed);
}

void Enemy::updateItem()
{
	this->item.move(0.f, this->speed);
}

void Enemy::updateItem2()
{
	this->item2.move(0.f, this->speed);
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

void Enemy::renderitem2(sf::RenderTarget* target)
{
	target->draw(this->item2);
}
