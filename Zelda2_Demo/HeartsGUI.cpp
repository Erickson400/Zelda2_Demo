#include "HeartsGUI.h"

HeartsGUI::HeartsGUI() {
	buffer->loadFromFile("Media/RupeeBeep.wav"); beep->setBuffer(*buffer);
	Tex.loadFromFile("Media/Hearts.png");
	Sprite.setTexture(Tex);
	Sprite.setScale(Size.x, Size.y);
	char GridWidth = sizeof(Grid) / sizeof(Grid[0]);
	char GridHeight = sizeof(Grid[0]);
	for (char y = 0; y < GridHeight; y++) {
		for (char x = 0; x < GridWidth; x++) {
			Grid[x][y] = -1;
		}
	}
}
HeartsGUI::~HeartsGUI() {
	delete beep, buffer;
}

void HeartsGUI::Update() {
	if (active) {
#pragma region BG
		if (MaxHearts <= 10) {
			for (char x = 0; x < MaxHearts; x++) {
				Grid[x][0] = 0;
			}
		}
		else {
			for (char x = 0; x < 10; x++) {
				Grid[x][0] = 0;
			}
			for (char x = 0; x < MaxHearts - 10; x++) {
				Grid[x][1] = 0;
			}
		}
#pragma endregion

#pragma region Health
		if (MaxHearts > 20) MaxHearts = 20; //Heart Less
		if (HealthPerHeart*MaxHearts < Health) Health = HealthPerHeart * MaxHearts; //Greater
		if (Health < 0) Health = 0; //Less

		if (Health <= 40) { // Above Heart Row
			for (char x = 0; x < MaxHearts; x++) { // Per heart
				char tempHealth = Health - 1; // to fill all previous hearts except the current one
				for (char x = 0; x < (tempHealth / HealthPerHeart); x++) { // Draw full Hearts before the peace one
					if (x != (tempHealth / HealthPerHeart)) Grid[x][0] = 4;
				}
				if (x == (tempHealth / HealthPerHeart)) { //if in current heart
					Grid[x][0] = (tempHealth % 4) + 1; //set to a peace
					if (tempHealth % 4 == 4) Grid[x][0] = 4; //set it full
				}
				else { //if Not in current heart then draw the rest black
					Grid[x][0] = 0;
				}
			}
		}
		else {// Below Heart Row
			for (char x = 0; x < 10; x++) { // Fill top hearts
				Grid[x][0] = 4;
			}
			for (char x = 0; x < MaxHearts - 10; x++) {
				char tempHealth = (Health - 40) - 1;
				for (char x = 0; x < (tempHealth / HealthPerHeart); x++) {
					if (x != (tempHealth / HealthPerHeart)) Grid[x][1] = 4;
				}
				if (x == (tempHealth / HealthPerHeart)) {
					Grid[x][1] = (tempHealth % 4) + 1;
					if (tempHealth % 4 == 4) Grid[x][1] = 4;
				}
				else {
					Grid[x][1] = 0;
				}
			}
		}
#pragma endregion
	}
}

void HeartsGUI::Render(sf::RenderWindow & window) {
	if (active) {
		char GridWidth = sizeof(Grid) / sizeof(Grid[0]);
		char GridHeight = sizeof(Grid[0]);
		for (char y = 0; y < GridHeight; y++) {
			for (char x = 0; x < GridWidth; x++) {
				Sprite.setPosition(((x + 0.5) * 16)*Size.x, ((y + 0.5) * 16)*Size.y);

				switch (Grid[x][y]) {
				case -1: break;
				case 0: Sprite.setTextureRect(sf::IntRect(0, 0, 16, 16)); window.draw(Sprite); break;
				case 1: Sprite.setTextureRect(sf::IntRect(16, 0, 16, 16)); window.draw(Sprite); break;
				case 2: Sprite.setTextureRect(sf::IntRect(32, 0, 16, 16)); window.draw(Sprite); break;
				case 3: Sprite.setTextureRect(sf::IntRect(48, 0, 16, 16)); window.draw(Sprite); break;
				case 4: Sprite.setTextureRect(sf::IntRect(64, 0, 16, 16)); window.draw(Sprite); break;
				}

			}
		}
	}
}

void HeartsGUI::damage(char damage) {
	Health += damage;
}

void HeartsGUI::addHealth() {
	MaxHearts++;
	beep->play();
}
