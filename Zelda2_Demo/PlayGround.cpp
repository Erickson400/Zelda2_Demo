#include "PlayGround.h"
#include <iostream>
PlayGround::PlayGround() {
	Sheet->loadFromFile("Media/PlayerSheet.png");
	groundTexture->loadFromFile("Media/PlayerSheet.png", sf::IntRect(97, 49, 16, 16));

	groundTexture->setRepeated(true);
	floor->setTexture(*groundTexture, true);
	floor->setTextureRect(sf::IntRect(0, 0, 300, 64));
	floor->setPosition(sf::Vector2f(1, 200));

	Player->setTexture(*Sheet); // 43, 38
	Player->setPosition(90, 180);
	Player->setOrigin(43 / 2, 38 / 2);
	Player->setTextureRect(sf::IntRect(86 + 3, 1, 43, 38));
	//Player->scale(1, 1);
	// Run Frame1 45, 1, 43, 38
	// Run Frame2 89, 1, 43, 38
	// Run Frame3 133, 1, 43, 38

	Sword->setTexture(*Sheet); // 43, 38
	Sword->setPosition(90, -83);
	Sword->setOrigin(43 / 2, 38 / 2);
	Sword->setTextureRect(sf::IntRect(131, 49, 16, 16));
}

PlayGround::~PlayGround() {
	delete Sheet, groundTexture, floor, Player, Sword;
}

void PlayGround::Update(float &delta, char &Hkey, char &Vkey, bool &Space) {
	if (active) {
		cnt++;
		//Mirror
		if (Player->getScale().x > 0) {
			if (Hkey == 1) {
				Player->setScale(Player->getScale().x, Player->getScale().y);
			}
			else if (Hkey == -1) {
				Player->setScale(-Player->getScale().x, Player->getScale().y);
			}
		}
		else {
			if (Hkey == 1) {
				Player->setScale(-Player->getScale().x, Player->getScale().y);
			}
			else if (Hkey == -1) {
				Player->setScale(Player->getScale().x, Player->getScale().y);
			}
		}

		if (attackFrame == 0) {
			if (Vkey == 0 || Vkey == 1) {
				Player->move(Hkey*60*delta, 0);
				if (cnt % 10 == 1 && Hkey != 0) CheckWalkFrame();
			}
			else if (Vkey == -1) {
				Player->setTextureRect(sf::IntRect(1, 1, 43, 38));
			}
			if (Hkey == 0 && Vkey == 0) {
				Player->setTextureRect(sf::IntRect(86 + 3, 1, 43, 38));
			}
		}

		Sword->move((Sword->getScale().x > 0 ? SwordSpeed : -SwordSpeed)*delta, 0);
		Sword->setColor(sf::Color(std::rand() * 255, std::rand() * 255, std::rand() * 255));
		CheckSpacePress(Space);
		Space = false;
	}
	std::cout << Player->getPosition().x << std::endl;
	//Player->setPosition(0, 0);
}

void PlayGround::Render(sf::RenderWindow &window) {
	if (active) {
		window.draw(*floor);
		window.draw(*Player);
		window.draw(*Sword);
	}
}

void PlayGround::CheckWalkFrame() {
	switch (playerFrame) {
	case 0: Player->setTextureRect(sf::IntRect(133, 1, 43, 38)); break;
	case 1: Player->setTextureRect(sf::IntRect(45, 1, 43, 38)); break;
	case 2: Player->setTextureRect(sf::IntRect(89, 1, 43, 38)); break;
	}
	playerFrame++;
	if (playerFrame > 2) playerFrame = 0;
}

void PlayGround::CheckSpacePress(bool &Space) {
	if (Space&&attackFrame == 0) {
		attackFrame = 1;
		if (Player->getScale().x > 0) {
			Sword->setScale(abs(Sword->getScale().x), Sword->getScale().y);
			Sword->setPosition(Player->getPosition().x + 41, Player->getPosition().y + 6);
		}
		else {
			Sword->setScale(-abs(Sword->getScale().x), Sword->getScale().y);
			Sword->setPosition(Player->getPosition().x - 41, Player->getPosition().y + 6);
		}

	}
	switch (attackFrame) {
	case 1: Player->setTextureRect(sf::IntRect(177, 1, 43, 38)); break;
	case 2: Player->setTextureRect(sf::IntRect(1, 40, 43, 38));  Player->setOrigin((43 / 2) - 2 - 10, 38 / 2); break;
	case 3: Player->setTextureRect(sf::IntRect(45, 40, 43, 38)); Player->setOrigin((43 / 2) - 4 - 10, 38 / 2); break;
	case 4: Player->setTextureRect(sf::IntRect(1, 40, 43, 38));  Player->setOrigin((43 / 2) - 2, 38 / 2); break;
	case 5: Player->setTextureRect(sf::IntRect(177, 1, 43, 38)); Player->setOrigin(43 / 2, 38 / 2); break;
	}
	if (attackFrame > 0 && cnt % 5 == 1) attackFrame++;
	if (attackFrame > 5) {
		attackFrame = 0;
		Player->setOrigin(43 / 2, 38 / 2);
	}
}


