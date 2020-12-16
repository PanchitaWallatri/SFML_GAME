
#include "player.h"




void Player::iniVariable()
{
	this->MoveSpeed = 80.f;
	this->attackCooldownMax = 8.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
	this->P_x = 0;
}

void Player::iniTexture()
{
	//load file
	if (!texture.loadFromFile("pic/dog1.png"))
	{
		printf("NOT LOAD PLAYER");
	}
}

void Player::iniSprite()
{
	this->A_x = texture.getSize().x / 3;
	this->A_y = texture.getSize().y / 4;

	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, A_x, A_y));
	//this->sprite.setTexture(texture);
	//this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y , this->A_x, this->A_y));

	//size
	//this->sprite.setScale(1.f, 1.f);
	this->sprite.setPosition(410, 600);
}

void Player::setupHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int velue)
{
	this->hp -= velue;
}

Player::Player()
{
	this->iniVariable();
	this->MoveSpeed = 4.f;
	this->iniTexture();
	this->iniSprite();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getpos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBound() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHP() const
{
	return this->hp;
}

const int& Player::getHPMax() const
{
	return this->hpMax;
}

void Player::setHP(const int hp)
{
	this->hp = hp;
	if (this->hp < 0)
	{
		this->hp = 0;
	}
}

void Player::loseHP(const int Velue)
{
	this->hp -= Velue;
}

void Player::FillHP(const int Velue)
{
	if (this->hp <= 100)
	{
		this->hp += Velue;
	}
}

void Player::Speedup(const int Velue)
{
	int time = 0;
	int timemax = 2;

	do
	{
		this->MoveSpeed = 100;
		time++;

	} while (time<=timemax);

	time = 0;
	this->MoveSpeed = 4;
	
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::move(sf::RenderWindow* window)
{
	this->speedMove = 60;
	this->A_x = texture.getSize().x / 3;
	this->A_y = texture.getSize().y / 4;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//left RIGHT
		this->sprite.move(5.f, 0.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 2, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//left RIGHT
		this->sprite.move(-5.f, 0.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 1, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//left RIGHT
		this->sprite.move(0.f, -5.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 3, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		//left RIGHT
		this->sprite.move(0.f, 5.f);
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->P_x * this->A_x, this->A_y * 0, this->A_x, this->A_y));

		this->P_x = P_x + 1;

		if (this->P_x * this->A_x >= this->A_x * 3)
		{
			this->P_x = 0;
		}
	}


	else
	{
		window->setFramerateLimit(this->speedMove);

		this->sprite.setTextureRect(sf::IntRect(this->A_x * 1, this->A_y * 0, this->A_x, this->A_y));
	}
}

const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAttack()
{
	if (this->attackCooldown < this->attackCooldownMax)
	{
		this->attackCooldown += 0.60f;
	}
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}