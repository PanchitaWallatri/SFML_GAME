#pragma once
#include <SFML/Graphics.hpp>


class animations
{

private:

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;




	float totalTime;
	float switchTime;


public:

	animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(int row, float deltaTime);

	void Updateinteract(int collum, float deltatTime);


	sf::IntRect uvrect;


};