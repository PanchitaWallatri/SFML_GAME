#include <iostream>
#include "Game.h"
#include "Player.h"
#include "animations.h"

//Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
void game::titleWindow()
{
    this->window = new  sf::RenderWindow(sf::VideoMode(840, 650), "HOME;RUN", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);

    bg1 = new sf::RectangleShape(sf::Vector2f(256.f, 256.f));
    bgTexture.loadFromFile("D:/gamess/background.png");
    bg1->setTexture(&bgTexture);



}

void game::titlePlayer()
{

    this->bodyTexture.loadFromFile("D:/gamess/dog1.png");
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 100.f);


}

/*void game::titleEnermy()
{

    this->enermyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");

    enermy = new Enermy(&enermyTexture, sf::Vector2u(2, 6), 0.5f);


    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;

}

void game::titleObject()
{
    this->sandbarTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");
    this->Object = new object(&sandbarTexture, sf::Vector2u(4, 1), 0.5f);
    this->Object->setUvrectObject(&sandbarTexture, sf::Vector2u(4, 1));

}

/*void game::titleFont()
{
    if (!this->font.loadFromFile("fonts/c"))
    {
        std::cout << "Error::Game::titlefont:: could not load FFFFORWA.ttf" << "\n" ;
    }
}*/

/*void game::titleText()
{
    this->pointtext.setFont(this->font);
    this->pointtext.setColor(sf::Color::White);
    this->pointtext.setCharacterSize(24);
    this->pointtext.setString("test");
}*/

void game::pollEvent()
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


/// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
game::game()
{

    this->titleWindow();
    this->titlePlayer();
    this->pollEvent();
    //this->titleEnermy();
    //this->titleObject();
    // this->titleFont();
    // this->titleText();


}

void game::regame()
{
    delete this->window;
    delete this->player;
    //delete this->enermy;


}




///Functions    /// ต้องเรียกใช้เป็นจุดๆไป เช่น game.update

void game::run()
{
    while (this->window->isOpen())
    {

        this->update();
        this->render();

    }

}

/*void game::randomenemies()
{   //เวลาในการ spawn
    this->spawnTimer += 0.4f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        this->enermy->spawnEnermy(rand() % 200, -140);
        this->spawnTimer = 0.f;
    }
      for (auto* enermy : this->enemies)
      {
          enermy->UpdateEnermy(this->deltaTime);
      }
      
}

void game::updateCollision()
{
    if (this->player->getGlobalBounds().intersects(this->enermy->getGlobalBounds()))
    {
        this->player->setPosition();
    }
}*/

void game::update()
{
    this->deltaTime = clock.restart().asSeconds();
    this->pollEvent();
    //update movement & animation Player
    this->player->Updateplayer(this->deltaTime);

    //this->enermy->UpdateEnermy(this->deltaTime);

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

    //this->enermy->Drawenermy(*this->window);
    //this->Object->DrawObject(*this->window);

    ///ต้องเอาไว้ล่างสุด
    this->window->display();


}