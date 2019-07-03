#pragma once
#include <iostream>
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#include "Intro.h"

class Game {
public:
	Game(sf::RenderWindow *app); ~Game();
	sf::RenderWindow *App; sf::Event event; sf::View view1;
	float delta;
	char Hkey = 0, Vkey = 0;
	bool Up, Down, Right, Left;

	Intro *intro = new Intro();

	void Update();
	void EventHandling();
	void KeyCheck();
	void Rendering();
};
