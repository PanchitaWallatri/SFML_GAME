#include "EndGame.h"

void EndGame::iniText(sf::RenderWindow* window, sf::Text pointt)
{

	//load font
	if (!font.loadFromFile("font/SnesItalic-1G9Be.ttf"))
		printf("NOT LOAD FONT");

	//ini hightscoreText
	this->hightscoreText.setFont(this->font);
	this->hightscoreText.setCharacterSize(70);
	this->hightscoreText.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f-90, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 160);
	this->hightscoreText.setString("HightScore");
	this->hightscoreText.setFillColor(sf::Color::Black);
	//score
	pointt.setCharacterSize(70);
	pointt.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f + 80, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 210);
	this->pointtText = pointt;
	this->pointtText.setFillColor(sf::Color::Black);

	//score1
	this->pointtText1.setFont(this->font);
	this->pointtText1.setCharacterSize(70);
	this->pointtText1.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 70);
	this->pointtText1.setString("pointtText1");
	this->pointtText1.setFillColor(sf::Color::Black);

	//score2
	this->pointtText2.setFont(this->font);
	this->pointtText2.setCharacterSize(70);
	this->pointtText2.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f - 0);
	this->pointtText2.setString("pointtText2");
	this->pointtText2.setFillColor(sf::Color::Black);

	//score3
	this->pointtText3.setFont(this->font);
	this->pointtText3.setCharacterSize(70);
	this->pointtText3.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f + 70);
	this->pointtText3.setString("pointtText3");
	this->pointtText3.setFillColor(sf::Color::Black);

	//score4
	this->pointtText4.setFont(this->font);
	this->pointtText4.setCharacterSize(70);
	this->pointtText4.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f +140);
	this->pointtText4.setString("pointtText4");
	this->pointtText4.setFillColor(sf::Color::Black);

	//score5
	this->pointtText5.setFont(this->font);
	this->pointtText5.setCharacterSize(70);
	this->pointtText5.setPosition(window->getSize().x / 2.5f - this->hightscoreText.getGlobalBounds().width / 2.f, window->getSize().y / 2.f - this->hightscoreText.getGlobalBounds().height / 2.f + 210);
	this->pointtText5.setString("pointtText5");
	this->pointtText5.setFillColor(sf::Color::Black);
}

void EndGame::iniTextBackground(sf::RenderWindow* window)
{
	if (!this->bg.loadFromFile("bg/end.png"))
	{
		printf("NOT LOAD BG High");
	}

	this->bgg.setTexture(this->bg);
	//this->bgg.setScale(0.5, 0.4);
	//this->bgg.setTextureRect(sf::IntRect(280, 1320, 800, 600));
}

EndGame::EndGame(int score, unsigned hightscore, sf::RenderWindow* window, sf::Text pointt,int c)
{
	iniText(window, pointt);
	iniTextBackground(window);
}

EndGame::~EndGame()
{

}

void EndGame::update(int Hightscore, int point, unsigned c)
{
	////////////////////////////////////////////////read/////////////////////////////////////////////

	//count
	std::ifstream readcount;
	readcount.open("score/scorecount.text");
	if (readcount.is_open())
	{
		while (!readcount.eof())
		{
			readcount >> c;
		}
	}
	readcount.close();

	//Hight score

	std::ifstream readHightscore;
	readHightscore.open("score/HightScore.text");
	if (readHightscore.is_open())
	{
		while (!readHightscore.eof())
		{
			readHightscore >> Hightscore;
		}
	}
	readHightscore.close();

	//score
	std::ifstream readscore;
	readscore.open("score/score_0.text");
	if (readscore.is_open())
	{
		while (!readscore.eof())
		{
			readscore >> this->score;
		}
	}
	readscore.close();

	//score1
	std::ifstream readscore1;
	readscore1.open("score/score_1.text");
	if (readscore1.is_open())
	{
		while (!readscore1.eof())
		{
			readscore1 >> this->score_[0];
		}
	}
	readscore1.close();

	//score2
	std::ifstream readscore2;
	readscore2.open("score/score_2.text");
	if (readscore2.is_open())
	{
		while (!readscore2.eof())
		{
			readscore2 >> this->score_[1];
		}
	}
	readscore2.close();

	//score3
	std::ifstream readscore3;
	readscore3.open("score/score_3.text");
	if (readscore3.is_open())
	{
		while (!readscore3.eof())
		{
			readscore3 >> this->score_[2];
		}
	}
	readscore3.close();

	//score4
	std::ifstream readscore4;
	readscore4.open("score/score_4.text");
	if (readscore4.is_open())
	{
		while (!readscore4.eof())
		{
			readscore4 >> this->score_[3];
		}
	}
	readscore4.close();

	//score5
	std::ifstream readscore5;
	readscore5.open("score/score_5.text");
	if (readscore5.is_open())
	{
		while (!readscore5.eof())
		{
			readscore5 >> this->score_[4];
		}
	}
	readscore5.close();
	/////////////////////////////cosident/////////////////////////////////////////

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (score_[j + 1] > score_[j])
			{
				temp = score_[j];
				score_[j] = score_[j + 1];
				score_[j + 1] = temp;
			}
		}

	}
	/////////////////////////////////////////////////////write/////////////////////////////////////////////////////

	//highscore
	std::ofstream writeHightscore("score/HightScore.text");
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

	std::ofstream writescore("score/score_0.text");
	if (writescore.is_open())
	{
		this->score = point;

		writescore << this->score;
	}

	//1
	if (c % 5 == 0)
	{
		this->score_[0] = this->score;
		std::ofstream writescore1("score/score_1.text");

		if (writescore1.is_open())
		{
			this->score_[0];

			writescore1 << this->score_[0];
		}
	}
	//2
	if (c % 5 == 1)
	{
		this->score_[1] = this->score;
		std::ofstream writescore2("score/score_2.text");

		if (writescore2.is_open())
		{
			this->score_[1];

			writescore2 << this->score_[1];
		}
	}

	//3
	if (c % 5 == 2)
	{
		this->score_[2] = this->score;
		std::ofstream writescore3("score/score_3.text");

		if (writescore3.is_open())
		{
			this->score_[2];

			writescore3 << this->score_[2];
		}
	}

	//4
	if (c % 5 == 3)
	{
		this->score_[3] = this->score;
		std::ofstream writescore4("score/score_4.text");

		if (writescore4.is_open())
		{
			this->score_[3];

			writescore4 << this->score_[3];
		}
	}

	//5
	if (c % 5 == 4)
	{
		this->score_[4] = this->score;
		std::ofstream writescore5("score/score_5.text");

		if (writescore5.is_open())
		{
			this->score_[4];

			writescore5 << this->score_[4];
		}
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

	/////////////////scorecount/////////////////////////

	std::stringstream ss1;
	ss1 << "score1  " << this->score_[0];
	this->pointtText1.setString(ss1.str());
	this->pointtText1.setFillColor(sf::Color::Black);

	std::stringstream ss2;
	ss2 << "score2  " << this->score_[1];
	this->pointtText2.setString(ss2.str());
	this->pointtText2.setFillColor(sf::Color::Black);

	std::stringstream ss3;
	ss3 << "score3  " << this->score_[2];
	this->pointtText3.setString(ss3.str());
	this->pointtText3.setFillColor(sf::Color::Black);

	std::stringstream ss4;
	ss4 << "score4  " << this->score_[3];
	this->pointtText4.setString(ss4.str());
	this->pointtText4.setFillColor(sf::Color::Black);

	std::stringstream ss5;
	ss5 << "score5  " << this->score_[4];
	this->pointtText5.setString(ss5.str());
	this->pointtText5.setFillColor(sf::Color::Black);


	////////////////////////////////////////////cosident//////////////////////////////////////////


}

void EndGame::render(sf::RenderTarget* target)
{
	target->draw(this->bgg);
	target->draw(this->hightscoreText);
	target->draw(this->pointtText);

	target->draw(this->pointtText1);
	target->draw(this->pointtText2);
	target->draw(this->pointtText3);
	target->draw(this->pointtText4);
	target->draw(this->pointtText5);
}