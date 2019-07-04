#pragma once
#include <iostream>
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#include "Intro.h"
#include "PlayGround.h"

class Game {
public:
	Game(sf::RenderWindow *app); ~Game();
	sf::RenderWindow *App; sf::Event event; sf::View view1;
	float delta;
	char Hkey = 0, Vkey = 0;
	bool Up, Down, Right, Left, Space;

	Intro *intro = new Intro();
	PlayGround *playGround = new PlayGround();

	void Update();
	void EventHandling();
	void KeyCheck();
	void Rendering();
};
