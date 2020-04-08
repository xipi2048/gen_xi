#pragma once
#include <list>
#include "structs.hpp"

class Game
{
	sf::RenderWindow window;
	bool* keysPressed;
	std::list<ToDraw> toDraw;
	//todo: std::queue< toDrawIterator > toDelete;
public: 
	Game();
	~Game();
	int Run();

protected:
	Returns handleEvents();
	Returns drawFrame();
};

