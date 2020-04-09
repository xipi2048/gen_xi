#pragma once
#include <list>
#include "structs.hpp"

class Game
{
	sf::RenderWindow window;
	bool* keysPressed;	
	std::list<ToDraw> toDraw;
	int currentLevel = -1;
public: 
	Game();
	~Game();
	int Run();

protected:
	Returns handleEvents();
	Returns drawFrame();
	Returns runLogic();
};

