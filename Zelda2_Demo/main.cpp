#define NOMINMAX
#include <iostream>
#include <Windows.h>
#ifndef  GRAPHICS_HPP
#include <SFML\Graphics.hpp>
#endif
#include "Game.h"

int main(int argc, char** argv) {
	FreeConsole();
	sf::RenderWindow *App = new sf::RenderWindow(sf::VideoMode(256*3,232*3), "Zelda2_Demo", sf::Style::Titlebar | sf::Style::Close);
	App->setFramerateLimit(60);
	App->setKeyRepeatEnabled(false);

	Game *game = new Game(App);
	while (App->isOpen()) {
		sf::Clock timer;
		sf::Time elapsed1 = timer.getElapsedTime();
		while (App->pollEvent(game->event)) { game->EventHandling(); }
		game->Update();
		game->KeyCheck();
		game->Rendering();
		sf::Time elapsed2 = elapsed1 - timer.getElapsedTime();
		game->delta = -elapsed2.asSeconds();
		game->deltaMilli = -elapsed2.asMilliseconds();
	}
	delete game, App;
	return 0;
}
