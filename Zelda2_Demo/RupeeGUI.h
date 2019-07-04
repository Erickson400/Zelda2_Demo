#pragma once
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#ifndef  AUDIO_HPP
#include <SFML\Audio.hpp>
#endif
#include <string>

class RupeeGUI {
public:
	RupeeGUI();
	~RupeeGUI();

	void setBalance(bool self, short value);
	void Update(float delta);
	void Render(sf::RenderWindow &window);
	void Enable() { active = true; };
private:
	bool Check(); //if balance is changing
	bool active = false;
	float tempCnt = 0;
	short balance = 0; // Before
	short inc = 0;   // Max new balance
	sf::Vector2f offset = sf::Vector2f(4, 220);

	std::string printBalance;
	sf::Texture *sheet = new sf::Texture();
	sf::Sprite *Logo = new sf::Sprite();
	sf::Sprite *Drawer = new sf::Sprite();

	sf::SoundBuffer *buffer = new sf::SoundBuffer();
	sf::Sound *beep = new sf::Sound();

};

