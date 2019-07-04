#pragma once
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif

class PlayGround {
public:
	PlayGround();
	~PlayGround();

	void CheckWalkFrame();
	void CheckSpacePress(bool &Space);
	void Update(float &delta, char &Hkey, char &Vkey, bool &Space);
	void Render(sf::RenderWindow &window);
	void Enable() { active = true; }
private:
	int cnt = 0;
	bool active=false;
	char playerFrame = 0, attackFrame = 0;
	float SwordSpeed = 80;

	sf::Texture *Sheet = new sf::Texture();
	sf::Texture *groundTexture = new sf::Texture();
	sf::Sprite *floor = new sf::Sprite();
	sf::Sprite *Player = new sf::Sprite(); 
	sf::Sprite *Sword = new sf::Sprite();
};

