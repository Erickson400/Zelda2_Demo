#pragma once
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#ifndef  AUDIO_HPP
#include <SFML\Audio.hpp>
#endif

class HeartsGUI {
public:
	HeartsGUI();
	~HeartsGUI();

	void Update();
	void Render(sf::RenderWindow &window);

	void damage(char damage);
	void addHealth();
	void Enable() { active = true; };

	bool active = false;
private:
	char Health = 7;	 // Max is 80
	char MaxHearts = 3; // Max is 20
	char const HealthPerHeart = 4;
	char Grid[10][2];   // Must always be 10, 2


	sf::Texture Tex;
	sf::Sprite Sprite;
	sf::Vector2f Size = sf::Vector2f(0.5, 0.5);

	sf::SoundBuffer *buffer = new sf::SoundBuffer();
	sf::Sound *beep = new sf::Sound();
};

