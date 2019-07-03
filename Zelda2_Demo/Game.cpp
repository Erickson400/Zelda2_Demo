#include "Game.h"

Game::Game(sf::RenderWindow *app) : App(app) {
	view1.setCenter(sf::Vector2f(256 / 2, 232 / 2));
	view1.setSize(sf::Vector2f(256, 232));
}

void Game::Update() {
	intro->Update(delta);
}

void Game::Rendering() {
	App->clear();
	App->setView(view1);

	intro->Render(App);

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
		case sf::Keyboard::Space: intro->Disable(); break;
		}break;
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::W: Up = false; break;
		case sf::Keyboard::A: Left = false; break;
		case sf::Keyboard::S: Down = false; break;
		case sf::Keyboard::D: Right = false; break;
		}break;
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
	delete  intro, App;
}
