#include "game.h"


Game::Game()
	: window(sf::VideoMode(800, 600), "Generation XI")
{
	keysPressed = new bool[sf::Keyboard::KeyCount];
}

Game::~Game()
{
	delete keysPressed;
	for (auto d : toDraw)
		delete d.drawable;
}

int Game::Run()
{
	while (window.isOpen())
	{
		switch (handleEvents())
		{
		case Returns::closeWin:
			window.close();
			return 0;
		}

		runLogic();
		drawFrame();
	}
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
		if (d->plsDelete)
		{
			delete d--->drawable;
		}

		if (d->isVisible)
			window.draw(*d->drawable);
	}

	window.display();

	return Returns::allGood;
}

Returns Game::runLogic()
{
	return Returns::allGood;
}
