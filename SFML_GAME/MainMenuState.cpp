#include "MainMenuState.h"

void MainMenuState::iniVariable()
{
}

void MainMenuState::iniBackground()
{
	this->background.setSize(sf::Vector2f(static_cast<float>(this->window->getSize().x), static_cast<float>(this->window->getSize().y)));


	if (!this->bgTexture.loadFromFile("bg/main.png"))
	{
		throw "Main_Menu_Background_not_load";
	}

	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::iniFont()
{
	if (!this->font.loadFromFile("font/SnesItalic-1G9Be.ttf"))
	{
		printf("Error font");
	}
}

void MainMenuState::iniKeybind()
{
	//	this->keybinds["Escape"]  = this->supportedKey->at("Escape");

	this->keybinds["CLOSE"] = this->supportedKey->at("Escape");

	//this->keybinds["MOVE_LEFT"] = this->supportedKey->at("A");
	//this->keybinds["MOVE_RIGHT"] = this->supportedKey->at("D");
	//this->keybinds["MOVE_TOP"] = this->supportedKey->at("W");
	//this->keybinds["MOVE_DOWN"] = this->supportedKey->at("S");

	//this->keybinds.emplace("MOVE_LEFT", this->supportedKey->at("A"));

}

void MainMenuState::iniButton()
{

	this->button["Game_State"] = new Button(350, 300, 150, 80,
		&this->font, "Start", 80,
		sf::Color::Black, sf::Color(70, 70, 70, 200), sf::Color(20, 20, 20, 50),
		sf::Color(150, 150, 150, 0), sf::Color(70, 70, 70, 0), sf::Color(20, 20, 20, 0));

	this->button["Exit_State"] = new Button(350, 400, 150, 80,
		&this->font, "Quit", 80,
		sf::Color::Black, sf::Color(70, 70, 70, 200), sf::Color(20, 20, 20, 50),
		sf::Color(150, 150, 150, 0), sf::Color(70, 70, 70, 0), sf::Color(20, 20, 20, 0));
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKey, std::stack<State*>* state)
	: State(window, supportedKey, state)
{
	this->iniVariable();
	this->iniBackground();
	this->iniFont();
	this->iniKeybind();
	this->iniButton();
}

MainMenuState::~MainMenuState()
{
	auto it = this->button.begin();
	for (it = this->button.begin(); it != this->button.end(); ++it)
	{
		delete it->second;
	}
}

//void MainMenuState::endState()
//{
//	printf("End MenuState\n");
//}

void MainMenuState::updateInput(const float& dt)
{
	//Keyboard
	//this->checkForQuit();
}

void MainMenuState::updateButton()
{
	//update all button
	for (auto& it : this->button)
	{
		it.second->update(this->mousePosView);
	}

	//New
	if (this->button["Game_State"]->isPressed())
	{
		this->state->push(new GameState(this->window, this->supportedKey, this->state));
	}

	//quit
	if (this->button["Exit_State"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosition();

	this->updateInput(dt);

	this->updateButton();


}

void MainMenuState::renderButton(sf::RenderTarget& target)
{
	for (auto& it : this->button)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{

	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButton(*target);

	//x,y mouse
	sf::Text mouseText;
	//���˹� ��� x,y 
	/*mouseText.setPosition(this->mousePosView.x, this->mousePosView.y-50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(18);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);*/


}