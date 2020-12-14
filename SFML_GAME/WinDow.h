#pragma once
#include"game.h"
#include"State.h"
#include"MainMenuState.h"


class WinDow
{
private:
	//window
	sf::RenderWindow* window;
	std::stack<State*> state;
	std::map<std::string, int> supportedKey;
	float dt;
	sf::Clock dtClock;

	void iniWindow();
	void iniState();
	void iniKey();


public:
	WinDow();
	virtual ~WinDow();

	void updatePollEvent();
	void updateDT();
	void update();
	void render();
	void run();
};