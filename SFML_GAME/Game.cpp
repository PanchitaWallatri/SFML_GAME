//#include <iostream>
#include "game.h"
//#include "player.h"
//#include "animations.h"

//Construtor ,Destructor /// �зӧҹ���� ��������¡�� game.
/*void game::titleWindow()
{
    this->window = new  sf::RenderWindow(sf::VideoMode(840, 650), "Game", sf::Style::Close | sf::Style::Default);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

    bg1 = new sf::RectangleShape(sf::Vector2f(840.f, 650.f));
    bgTexture.loadFromFile("D:/gamess/background.png");
    bg1->setTexture(&bgTexture);



}

void game::titlePlayer()
{

    this->bodyTexture.loadFromFile("D:/gamess/dog1.png");
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 100.f);


}

void game::titleEnermy()
{

    this->enermyTexture.loadFromFile("D:/gamess/car1.png");

    enermy = new Enermy(&enermyTexture, sf::Vector2u(2, 6), 0.5f);


    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;

}

/*void game::titleObject()
{
    this->sandbarTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");
    this->Object = new object(&sandbarTexture, sf::Vector2u(4, 1), 0.5f);
    this->Object->setUvrectObject(&sandbarTexture, sf::Vector2u(4, 1));

}

void game::titleFont()
{
    if (!this->font.loadFromFile("fonts/c"))
    {
        std::cout << "Error::Game::titlefont:: could not load FFFFORWA.ttf" << "\n" ;
    }
}

/*void game::titleText()
{
    this->pointtext.setFont(this->font);
    this->pointtext.setColor(sf::Color::White);
    this->pointtext.setCharacterSize(24);
    this->pointtext.setString("test");
}*/

/*void game::pollEvent()
{

    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();

            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Key::Escape)
            {
                this->window->close();
            }
            break;

        }
    }
}


/// ���¡��ѧ��蹵����������� �Ѻ ˹�ҵ�ҧ�������
game::game()
{

    this->titleWindow();
    this->titlePlayer();
    this->pollEvent();
    this->titleEnermy();
    //this->titleObject();
    // this->titleFont();
    // this->titleText();


}

void game::regame()
{
    delete this->window;
    delete this->player;
    delete this->enermy;


}




///Functions    /// ��ͧ���¡���繨ش�� �� game.update

void game::run()
{
    while (this->window->isOpen())
    {

        this->update();
        this->render();

    }

}

void game::randomenemies()
{   //����㹡�� spawn
    this->spawnTimer += 0.4f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        this->enermy->spawnEnermy(rand() % 200, -140);
        this->spawnTimer = 0.f;
    }
    /*  for (auto* enermy : this->enemies)
      {
          enermy->UpdateEnermy(this->deltaTime);
      }
      
}*/

/*void game::updateCollision()
{
    if (this->player->getGlobalBounds().intersects(this->enermy->getGlobalBounds()))
    {
        this->player->setPosition();
    }
}

void game::update()
{
    this->deltaTime = clock.restart().asSeconds();
    this->pollEvent();
    //update movement & animation Player
    this->player->Updateplayer(this->deltaTime);

    this->enermy->UpdateEnermy(this->deltaTime);

    this->updateCollision();
    this->randomenemies();
    this->player->getPoints();

}

void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));


    ///render stuff
    this->window->draw(*this->bg1);
    this->player->Drawplayer(*this->window);

    this->enermy->Drawenermy(*this->window);
    //this->Object->DrawObject(*this->window);

    ///��ͧ��������ҧ�ش
    this->window->display();


}*/
void Game::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(840, 650), "Car Car Car", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::iniTexture()
{
	
}

/*void Game::iniTexture()
{
	this->texture["Bullet"] = new sf::Texture();
	this->texture["Bullet"]->loadFromFile("img/player/Bullet_1.png");
}*/

void Game::iniWorld()
{
	if (!this->wordBackgound_t.loadFromFile("D:/gamess/background.png"))
	{
		printf("NOT LOAD BACKGROUND");
	}
	this->wordBackgound_s.setTexture(this->wordBackgound_t);
	this->wordBackgound_s.setTextureRect(sf::IntRect(0, 0, 840, 650));
}

void Game::iniGui()
{
	//load font
	if (!this->font.loadFromFile("C:/Users/User/Downloads/SnesItalic-1G9Be.ttf"))
		printf("NOT LOAD FONT");

	//inipoint
	this->pointText.setFont(font);
	this->pointText.setCharacterSize(50);
	this->pointText.setPosition(this->window->getSize().x - 200, 0);
	this->pointText.setString("POINT");


	//update player
	this->playHPBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playHPBar.setFillColor(sf::Color::Red);
	this->playHPBar.setPosition(sf::Vector2f(0, 50));

	this->playHPBarBack = this->playHPBar;
	this->playHPBarBack.setFillColor(sf::Color(25, 25, 25, 200));

	this->GameOver.setFont(font);
	this->GameOver.setFillColor(sf::Color::Red);
	this->GameOver.setCharacterSize(60);
	this->GameOver.setPosition(this->window->getSize().x / 2.5f - this->GameOver.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - -this->GameOver.getGlobalBounds().height / 2.f);
	this->GameOver.setString("GAME OVER!");

}

void Game::inisystem()
{
	this->point = 0;
}

void Game::iniPlayer()
{
	this->player = new Player();

}

void Game::iniEnemies()
{
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
}

void Game::iniItem()
{
	this->spawnTimerItemMax = 500.f;
	this->spawnTimerItem = this->spawnTimerItemMax;
}

Game::Game()
{
	this->iniWindow();

	//this->iniTexture();

	this->iniGui();
	this->iniWorld();

	this->inisystem();

	this->iniPlayer();
	this->iniEnemies();
}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//delete texture
	/*for (auto& i : this->texture)
	{
		delete i.second;
	}
	//delete bullet
	for (auto* i : this->bullets)
	{
		delete i;
	}*/
	//delete enemy
	for (auto* i : this->enemies)
	{
		delete i;
	}

	for (auto* i : this->items)
	{
		delete i;
	}
	/*for (auto* i : this->itemspeed)
	{
		delete i;
	}*/

}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();
		if (this->player->getHP() > 0)
			this->update();

		this->render();
	}
}

void Game::updatePollEvent()
{
	//������Դ ˹�ҵ�ҧ window 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}
		//����
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
		{
			this->window->close();
		}

	}
}

void Game::updateInput()
{
	
	//move player
	this->player->move(this->window);
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//{
	//	this->player->move(-2.f, 0.f);
	//	//this->player->setTexture(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//	this->player->move(2.f, 0.f);
	//	//this->player->setTexture(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//	this->player->move(0.f, -2.f);
	//	//this->player->setTexture(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//	this->player->move(0.f, 2.f);
		//this->player->setTexture(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
		this->bullets.push_back(new Bullet(this->texture["Bullet"], this->player->getpos().x + this->player->getBound().width / 2.f - 20,
			this->player->getpos().y,
			0.f, -1.f, 12.f));*/
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Point : " << this->point;
	this->pointText.setString(ss.str());

	//update player
	float hpPercent = static_cast<float>(this->player->getHP()) / this->player->getHPMax() * 100;
	this->playHPBar.setSize(sf::Vector2f(4.f * hpPercent, this->playHPBar.getSize().y));
}

void Game::updateWorld()
{

}

void Game::updateCollision()
{
	//set not move over sceen
	//left
	if (this->player->getBound().left < 115.f)
	{
		this->player->setPosition(115.f, this->player->getBound().top);
	}
	//top
	if (this->player->getBound().top < 0.f)
	{
		this->player->setPosition(this->player->getBound().left, 0.f);
	}
	//right
	if (this->player->getBound().left + this->player->getBound().width >= this->window->getSize().x-115.f)
	{
		this->player->setPosition(this->window->getSize().x-115.f - this->player->getBound().width, this->player->getBound().top);
	}
	//down
	if (this->player->getBound().top + this->player->getBound().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBound().left, this->window->getSize().y - this->player->getBound().height);
	}
}

/*void Game::updateBullet()
{
	unsigned counter = 0;
	for (auto& bullet : this->bullets)
	{
		bullet->update();

		//��� screen
		if (bullet->getBound().top + bullet->getBound().height < 0.f)
		{
			//delete bullet
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
		}
		counter++;
	}
}

void Game::updateCombat()
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_delet = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_delet == false; k++)
		{
			if (this->enemies[i]->getBound().intersects(this->bullets[k]->getBound()))
			{
				this->point += this->enemies[i]->getPoint();

				enemy_delet = true;
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

			}
		}
	}
}

void Game::updateCombatitem()
{
	for (size_t i = 0; i < this->items.size(); i++)
	{
		bool item_delet = false;
		for (size_t k = 0; k < this->bullets.size() && item_delet == false; k++)
		{
			if (this->items[i]->getBoundItem().intersects(this->bullets[k]->getBound()))
			{
				item_delet = true;
				delete this->items[i];
				this->items.erase(this->items.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

			}
		}
	}
}*/

void Game::updateEnemy()
{
	//spawn
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		float randomX = rand() % this->window->getSize().x;
		if(randomX>=150 && randomX<= 600){
			this->enemies.push_back(new Enemy(randomX, -100.f));
			this->spawnTimer = 0.f;
		}
		//this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 100, -100.f));
		//this->spawnTimer = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//��� screen
		if (enemy->getBound().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			this->point += 10;
		}
		//player collision
		else if (enemy->getBound().intersects(this->player->getBound()))
		{
			this->player->loseHP(this->enemies.at(counter)->getDamage());
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			//hp
		}
		counter++;
	}
	/*for (auto* enemy : this->enemies)
	{
		enemy->update();
	}*/
}


void Game::updateitem()
{
	//spawn
	this->spawnTimerItem += .25f;
	if (this->spawnTimerItem >= this->spawnTimerItemMax)
	{
		this->items.push_back(new Enemy(rand() % this->window->getSize().x - 100, -100.f));
		this->spawnTimerItem = 0.f;
	}

	//update
	unsigned counter = 0;
	for (auto* enemy1 : this->items)
	{
		enemy1->updateItem();

		//��� screen
		if (enemy1->getBoundItem().top > this->window->getSize().y)
		{
			//delete enemy
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
		}
		//player collision
		else if (enemy1->getBoundItem().intersects(this->player->getBound()))
		{
			this->player->FillHP(this->items.at(counter)->getRecover());
			delete this->items.at(counter);
			this->items.erase(this->items.begin() + counter);
			//hp
		}
		counter++;
	}
}

void Game::update()
{
	this->updateInput();
	this->player->update();
	this->updateCollision();

	//this->updateBullet();
	this->updateEnemy();
	//this->updateitem();
	//this->updateCombatitem();
	//this->updateCombat();

	this->updateGUI();
	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playHPBarBack);
	this->window->draw(this->playHPBar);

}

void Game::render()
{
	this->window->clear();

	//draw world
	this->renderWorld();

	//Draw stuff
	this->player->render(*this->window);

	/*for (auto& bullet : this->bullets)
	{
		bullet->render(this->window);
	}*/

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	for (auto* enemy1 : this->items)
	{
		enemy1->renderitem(this->window);
	}
	this->renderGUI();

	//Game over
	if (this->player->getHP() <= 0)
		this->window->draw(this->GameOver);

	this->window->display();

}

void Game::renderWorld()
{
	this->window->draw(this->wordBackgound_s);
}