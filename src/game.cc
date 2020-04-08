#include "game.h"


Game::Game()
	: window()
{
	keysPressed = new bool[sf::Keyboard::KeyCount];
}

Game::~Game()
{
	delete keysPressed;
	for (auto d : toDraw)
		delete d;
}

int Game::Run()
{
	return 0;
}

Returns Game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed: 
			return Returns::closeWin;
		case sf::Event::KeyPressed:
			keysPressed[event.key.code] = true;
			break;
		case sf::Event::KeyReleased:
			keysPressed[event.key.code] = false;
			break;
		}
	}

	return Returns::allGood;
}

Returns Game::drawFrame()
{
	window.clear();

	for (auto d = toDraw.begin();
		d != toDraw.end();
		++d)
	{
		if (d->isVisible)
		{
			window.draw(*d->drawable);
		}
	}

	window.display();

	return Returns::allGood;
}
