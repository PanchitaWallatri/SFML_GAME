#include "EndGame.h"

void EndGame::iniText(sf::RenderWindow* window, sf::Text pointt)
{

	//load font
	if (!font.loadFromFile("font/SnesItalic-1G9Be.ttf"))
		printf("NOT LOAD FONT");

	//ini hightscoreText
	this->hightscoreText.setFont(this->font);
	this->hightscoreText.setCharacterSize(70);
	this->hightscoreText.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f-50, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 40);
	this->hightscoreText.setString("HightScore");
	this->hightscoreText.setFillColor(sf::Color::Black);

	//score
	pointt.setCharacterSize(70);
	pointt.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f + 80, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 80);
	this->pointtText = pointt;

	//score1
	this->pointtText1.setFont(this->font);
	this->pointtText1.setCharacterSize(70);
	this->pointtText1.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 120);
	this->pointtText1.setString("pointtText1");
	this->pointtText1.setFillColor(sf::Color::Black);


}

void EndGame::iniTextBackground(sf::RenderWindow* window)
{
	if (!this->bg.loadFromFile("bg/end.png"))
	{
		printf("NOT LOAD BG High");
	}

	this->bgg.setTexture(this->bg);
	
}

EndGame::EndGame(unsigned score, unsigned hightscore, sf::RenderWindow* window, sf::Text pointt)
{
	iniText(window, pointt);
	iniTextBackground(window);
}

EndGame::~EndGame()
{

}

void EndGame::update(unsigned Hightscore, unsigned point, unsigned c)
{

	//Hight score
	std::ifstream readHightscore;
	readHightscore.open("score/hightScore.text");
	if (readHightscore.is_open())
	{
		while (!readHightscore.eof())
		{
			readHightscore >> Hightscore;
		}
	}
	readHightscore.close();

	std::ofstream writeHightscore("score/hightScore.text");
	if (writeHightscore.is_open())
	{
		if (point > Hightscore)
		{
			Hightscore = point;
		}
		writeHightscore << Hightscore;
	}
	writeHightscore.close();

	//score

	std::ifstream readscore;
	readscore.open("score/score.text");
	if (readscore.is_open())
	{
		while (!readHightscore.eof())
		{
			readHightscore >> this->score;
		}
	}
	readHightscore.close();

	std::ofstream writescore("score/score.text");
	if (writescore.is_open())
	{
		if (c == 1)
		{
			this->score = point;
		}
		writescore << this->score;
	}
	writeHightscore.close();
	std::stringstream dd;
	dd << "Hight score  " << Hightscore;
	this->hightscoreText.setString(dd.str());
	this->hightscoreText.setFillColor(sf::Color::Black);

	std::stringstream ss;
	ss << "score  " << point;
	this->pointtText.setString(ss.str());
	this->pointtText.setFillColor(sf::Color::Black);
}

void EndGame::render(sf::RenderTarget* target)
{
	target->draw(this->bgg);
	target->draw(this->hightscoreText);
	target->draw(this->pointtText);


}