#pragma once

#include <SFML/Graphics.hpp>

enum struct Returns
{
	closeWin,
	allGood
};

struct ToDraw
{
public:
	bool isVisible = true;
	sf::Drawable* drawable;
};