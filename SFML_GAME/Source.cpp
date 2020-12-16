#include <SFML/Audio.hpp>
#include "game.h"
#include<time.h>
#include"WinDow.h"

using namespace sf;

int main()
{
   
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
    
}