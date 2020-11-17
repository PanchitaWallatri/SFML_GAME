#include "animations.h"
#include<iostream>



animations::animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.f;
	currentImage.x = 0;


	//��˹���ͺ���Ѻ sprite �������ҧ,�����٧
	uvrect.width = texture->getSize().x / 3;  // ��Ҵ�ٻ ��ô��� �ӹǹ�Ҿ��ٻ᡹ x
	uvrect.height = texture->getSize().y / 4;  // ��Ҵ�ٻ ��ô��� �ӹǹ�Ҿ��ٻ᡹ y
}


void animations::Updateinteract(int collum, float deltaTime)
{
	currentImage.x = collum;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.y++;
		if (currentImage.y >= imageCount.y)
		{
			currentImage.y = 0;
		}
	}

	uvrect.left = currentImage.x * uvrect.width;
	uvrect.top = currentImage.y * uvrect.height;

}

void animations::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvrect.left = currentImage.x * uvrect.width;
	uvrect.top = currentImage.y * uvrect.height;
}
/*	if (faceright)
	{
		uvrect.left = currentImage.x * uvrect.width;
		uvrect.width = abs(uvrect.width);
	}
	else
		uvrect.left = (currentImage.x + 1) * uvrect.width;
	uvrect.width = -abs(uvrect.width); */




