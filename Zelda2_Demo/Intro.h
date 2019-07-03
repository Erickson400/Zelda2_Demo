#pragma once
#include <iostream>
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#ifndef  AUDIO_HPP
#include <SFML\Audio.hpp>
#endif

class Intro {
public:
	Intro();
	~Intro();
	void Update(float &delta);
	void Render(sf::RenderWindow *app);
	void Disable() { active = false; };
private:
	bool active = true;
	float cnt = 0;

	sf::Texture *Sheet = new sf::Texture();
	sf::Sprite *BG = new sf::Sprite();
	sf::Sprite *Front = new sf::Sprite();
	sf::Sprite *Logo = new sf::Sprite();
	sf::Music Theme;
};

