#include "RupeeGUI.h"

RupeeGUI::RupeeGUI() {
	buffer->loadFromFile("Media/RupeeBeep.wav");
	beep->setBuffer(*buffer);
	sheet->loadFromFile("Media/RupeeFont.png");
	Drawer->setTexture(*sheet);
	Logo->setTexture(*sheet, true);
	Logo->setTextureRect(sf::IntRect(40, 0, 7, 7));
	Logo->setPosition(offset);
}
RupeeGUI::~RupeeGUI() {
	delete buffer, beep, sheet, Logo, Drawer;
}


void RupeeGUI::Update(float delta) {
	if (active) {
		tempCnt += delta;
		if (tempCnt >= 50) {
			if (Check()) {
				beep->play();
			}
			tempCnt = 0;
		}
	}
}

bool RupeeGUI::Check() {
	inc = (inc > 200) ? 200 : inc;
	if (inc >= 0) {
		if (inc > balance) {
			balance++;
			return true;
		};
		if (inc < balance) {
			balance--;
			return true;
		};
		return false;
	}
	else {
		inc = 0;
		return false;
	}
}

void RupeeGUI::Render(sf::RenderWindow & window) {
	if (active) {
		if (balance < 1000) {
			printBalance = std::to_string(balance);
		}
		if (balance < 100) {
			printBalance = "0" + std::to_string(balance);
		}
		if (balance < 10) {
			printBalance = "00" + std::to_string(balance);
		}

		if (balance == 200) {
			Drawer->setColor(sf::Color(0, 255, 0));
		}
		else {
			Drawer->setColor(sf::Color::Black);
		}
		for (char x = 0; x < 3; x++) {
			Drawer->setPosition((offset.x + 9) + (5 * x), offset.y);
			if (x == 0) {
				int num = std::stoi(printBalance.substr(0, 1));
				Drawer->setTextureRect(sf::IntRect(num * 4, 0, 3, 5));
			}
			if (x == 1) {
				int num = std::stoi(printBalance.substr(1, 1));
				Drawer->setTextureRect(sf::IntRect(num * 4, 0, 3, 5));
			}
			if (x == 2) {
				int num = std::stoi(printBalance.substr(2, 1));
				Drawer->setTextureRect(sf::IntRect(num * 4, 0, 3, 5));
			}
			window.draw(*Drawer);
		}
		window.draw(*Logo);
	}
}

void RupeeGUI::setBalance(bool self, short value) {
	if (self) {
		inc += value;
	}
}


