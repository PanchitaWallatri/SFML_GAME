#include "WinDow.h"

void WinDow::iniWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(840, 650), "Escape Car", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(80);
	this->window->setVerticalSyncEnabled(false);
	this->dt = 0.f;
}

void WinDow::iniState()
{
	this->state.push(new MainMenuState(this->window, &this->supportedKey, &this->state));
}

void WinDow::iniKey()
{
	this->supportedKey.emplace("Escape", sf::Keyboard::Key::Escape);
}

WinDow::WinDow()
{
	this->iniWindow();
	this->iniKey();
	this->iniState();
}

WinDow::~WinDow()
{
	delete this->window;

	while (!this->state.empty())
	{
		delete this->state.top();
		this->state.pop();
	}

}

void WinDow::updateDT()
{
	//update and render one frame
	this->dt = this->dtClock.restart().asSeconds();
}


void WinDow::updatePollEvent()
{
	//ãªé»ØèÁ»Ô´ Ë¹éÒµèÒ§ window 
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
		{
			this->window->close();
		}

	}
}

void WinDow::update()
{
	this->updatePollEvent();

	if (!this->state.empty())
	{
		this->state.top()->update(this->dt);

		if (this->state.top()->getQuit())
		{
			this->state.top()->endState();
			delete this->state.top();
			this->state.pop();
		}
	}
	//quit game
	else
	{
		this->window->close();
	}
}

void WinDow::render()
{
	this->window->clear();

	if (!this->state.empty())
	{
		this->state.top()->render();
	}

	this->window->display();
}

void WinDow::run()
{
	while (this->window->isOpen())
	{
		//this->updateDT();

		this->update();
		this->render();
	}
}