#pragma once
#include "structs.hpp"
#include <list>

class Game
{
	bool* keysPressed;
	std::list<ToDraw> toDraw;

public: 
	Game();
	~Game();
	void Run();

protected:
	void handleEvent(sf::Event& event);
	void drawFrame();
};