#include "game.h"

int main(int argc, char** argv)
{
	sf::RenderWindow window;
	Globals::init();
	Game game;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			auto retCode = handleEvent(event);
			if (retCode == Returns::closeWin)
			{
				Globals::denit();
				window.close();
				return 0;
			}
		}

		game.DrawFrame();
		Draw(window);
	}
}