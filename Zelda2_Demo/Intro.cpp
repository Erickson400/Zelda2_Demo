#include "Intro.h"
using namespace std;

Intro::Intro() {
	Sheet->loadFromFile("Media/IntroBG.png");
	Theme.openFromFile("Media/Theme.wav");
	BG->setTexture(*Sheet);
	Front->setTexture(*Sheet);
	Logo->setTexture(*Sheet);
	Logo->setPosition((256/2)-(215/2)+10,233);
	Logo->setTextureRect(sf::IntRect(512,1680,215,340));
	Theme.play();
}

Intro::~Intro() {
	delete Sheet, BG, Front, Logo;
}

void Intro::Update(float &delta) {
	if (active) {
		cnt += 6 * delta;
		if (Logo->getPosition().y > 36) {
			Logo->move(0, -11 * delta);
		}
		if (cnt > 160) Logo->move(0, -8.7 * delta);
		if (cnt > 420) {
			cnt = 0;
			Logo->setPosition((256 / 2) - (215 / 2) + 10, 140);
		}
		BG->setTextureRect(sf::IntRect(256 * ((int)cnt % 2), 232 * ((int)cnt % 3), 256, 232));
		Front->setTextureRect(sf::IntRect(256 * ((int)cnt % 2), 1160 + (232 * ((int)cnt % 3)), 256, 232));
	}
	else {
		Theme.stop();
	}
}

void Intro::Render(sf::RenderWindow *app) {
	if (active) {
		app->draw(*BG);
		app->draw(*Logo);
		app->draw(*Front);
	}
}


