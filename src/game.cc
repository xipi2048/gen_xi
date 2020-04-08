#include "game.h"

Game::Game()
	:keysPressed(new bool[sf::Keyboard::KeyCount])
{
}

Game::~Game()
{
	delete keysPressed;
}

void Game::Run()
{
}

void Game::handleEvent(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::Closed: return Returns::closeWin;
	case sf::Event::KeyPressed:
		Globals::keysPressed[event.key.code] = true;
		break;
	case sf::Event::KeyReleased:
		Globals::keysPressed[event.key.code] = false;
		break;
	}

	return Returns::allGood;
}

void Game::drawFrame()
{
	window.clear();

	for (auto d = Globals::toDraw.begin();
		d != Globals::toDraw.end();
		++d)
	{
		if (d->release)
		{
			Globals::toDraw.erase(d);
			--d;
			continue;
		}

		if (d->isVisible)
		{
			window.draw(*d->drawable);
		}
	}

	window.display();

	return Returns::allGood;
}
