//#include <SFML/Graphics.hpp>
//#include <iostream>
#include <SFML/Audio.hpp>
//#include "animations.h"
//#include "player.h"
#include "game.h"
//#include "object.h"
#include<time.h>
#include"WinDow.h"

using namespace sf;

int main()
{
    //sf::RenderWindow window(sf::VideoMode(840, 650), "Escape Car", sf::Style::Close | sf::Style::Default);
    //sf::Event ev;
    //srand(time(NULL));
    std::srand(static_cast<unsigned>(time(NULL)));

    sf::SoundBuffer Sound1;
    if(!Sound1.loadFromFile("sound/SEVENTEEN.wav"))
    {
        std::cout << "ERROR" << std::endl;
    }

    sf::Sound Sound;
    Sound.setBuffer(Sound1);
    Sound.setVolume(20);
    Sound.setLoop(true);
    Sound.play();
    

    WinDow game;
    game.run();
    /*sf::CircleShape collision(100.f);
    collision.setPosition({ 200.f, 200.f });
    collision.setFillColor(sf::Color::Magenta);

    sf::Music music;
    if (!music.openFromFile("C:/Users/User/Downloads/The-Pink-Panther-Soundtrack.ogg"))
    {
        std::cout << "ERROR" << std::endl;
    }
    music.play();


    sf::Texture playerTexture;
    sf::Texture backgroundTexture;
    if (!playerTexture.loadFromFile("D:/gamess/dog1.png"))
    {
        std::cout << "Load failed" << std::endl;
    }
    if (!backgroundTexture.loadFromFile("D:/gamess/background.png"))
    {
        std::cout << "Load background failed" << std::endl;
    }



    sf::Sprite shapeSprite;
    sf::Sprite bgSprite;
    shapeSprite.setTexture(playerTexture);
    bgSprite.setTexture(backgroundTexture);
    int spriteSizeX = playerTexture.getSize().x / 3;
    int spriteSizeY = playerTexture.getSize().y / 4;

    shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

    int animationFrame = 0;

    sf::Vector2f spawnPoint = { 0.f, 0.f };
    shapeSprite.setPosition(spawnPoint);

    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
            //std::cout << "Score: " << Text.getPosition();
        }
        

        
        window.draw(bgSprite);
        window.draw(shapeSprite);
        window.draw(collision);
        window.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            shapeSprite.move(.1f, 0.f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            shapeSprite.move(-.1f, 0.f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            shapeSprite.move(0.f, -.1f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            shapeSprite.move(0.f, .1f);
            shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0, spriteSizeX, spriteSizeY));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        animationFrame++;

        if (animationFrame >= 2)
        {
            animationFrame = 0;
        }

        if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds()))
        {
            shapeSprite.setPosition(spawnPoint);
        }

        window.clear();
    }

    
    return 0;*/   
}