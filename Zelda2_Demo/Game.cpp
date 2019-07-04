#include "Game.h"

Game::Game(sf::RenderWindow *app) : App(app) {
	view1.setCenter(sf::Vector2f(256 / 2, 232 / 2));
	view1.setSize(sf::Vector2f(256, 232));
	buf->loadFromFile("Media/Sword.wav");
	sword->setBuffer(*buf);
}

void Game::Update() {
	intro->Update(delta);
	playGround->Update(delta, Hkey, Vkey, Space);
	hearts->Update();
	rupee->Update(deltaMilli);
}

void Game::Rendering() {
	char BG = 70;
	App->clear(sf::Color(BG, BG, BG));
	App->setView(view1);

	intro->Render(App);
	playGround->Render(*App);
	hearts->Render(*App);
	rupee->Render(*App);
	App->display();
}

void Game::EventHandling() {
	switch (event.type) {
	case sf::Event::Closed: App->close(); break;
	case sf::Event::KeyPressed:
		switch (event.key.code) {
		case sf::Keyboard::Escape: App->close(); break;
		case sf::Keyboard::W: Up = true; break;
		case sf::Keyboard::A: Left = true; break;
		case sf::Keyboard::S: Down = true; break;
		case sf::Keyboard::D: Right = true; break;
		case sf::Keyboard::Space: sword->play(); Space = true; intro->Disable(); playGround->Enable(); hearts->Enable(); rupee->Enable(); break;
		case sf::Keyboard::Num1: rupee->setBalance(true, 10); break;
		case sf::Keyboard::Num2: rupee->setBalance(true, -10); break;
		}break;
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::W: Up = false; break;
		case sf::Keyboard::A: Left = false; break;
		case sf::Keyboard::S: Down = false; break;
		case sf::Keyboard::D: Right = false; break;
		}break;
	case sf::Event::MouseButtonPressed:
		if (event.mouseButton.button == sf::Mouse::Left) { 
			if (hearts->active) hearts->addHealth();
		};
		break;
	case sf::Event::MouseWheelMoved: {
		if(hearts->active) hearts->damage(event.mouseWheel.delta); 
	};
	break;
	}
}

void Game::KeyCheck() {
	if (Up&&Down) {
		Vkey = 0;
	}
	else if (!Up && !Down) {
		Vkey = 0;
	}
	else if (!Up&&Down) {
		Vkey = -1;
	}
	else if (Up && !Down) {
		Vkey = 1;
	}

	if (Right&&Left) {
		Hkey = 0;
	}
	else if (!Right && !Left) {
		Hkey = 0;
	}
	else if (!Right&&Left) {
		Hkey = -1;
	}
	else if (Right && !Left) {
		Hkey = 1;
	}
}















Game::~Game() {
	App->close();
	delete  buf, sword, rupee, hearts, intro, playGround, App;
}
