#pragma once
#include <iostream>
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#ifndef  AUDIO_HPP
#include <SFML\Audio.hpp>
#endif
#include "Intro.h"
#include "PlayGround.h"
#include "HeartsGUI.h"
#include "RupeeGUI.h"

class Game {
public:
	Game(sf::RenderWindow *app); ~Game();
	sf::RenderWindow *App; sf::Event event; sf::View view1;
	float delta, deltaMilli;
	char Hkey = 0, Vkey = 0;
	bool Up, Down, Right, Left, Space;
	sf::SoundBuffer *buf = new sf::SoundBuffer();
	sf::Sound *sword = new sf::Sound();

	Intro *intro = new Intro();
	PlayGround *playGround = new PlayGround();
	HeartsGUI *hearts = new HeartsGUI();
	RupeeGUI *rupee = new RupeeGUI();

	void Update();
	void EventHandling();
	void KeyCheck();
	void Rendering();
};
