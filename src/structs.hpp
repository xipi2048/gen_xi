#pragma once
#include <SFML/Graphics.hpp>

class ToDraw
{
	bool release = false;
	bool isVisible = true;
	sf::Drawable* drawable;
	sf::RenderWindow window;
public:
	ToDraw();
	~ToDraw()
	{
		delete drawable;
	}
};

enum struct Returns
{
	closeWin,
	allGood
};

