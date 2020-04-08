#pragma once
#include <list>
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow window;
	bool* keysPressed;
	std::list<sf::Drawable*> toDraw;
	//todo: std::queue< toDrawIterator > toDelete;
public: 
	Game();
	~Game();
	int Run();

protected:
	Returns handleEvents();
	Returns drawFrame();
};

enum struct Returns
{
	closeWin,
	allGood
};