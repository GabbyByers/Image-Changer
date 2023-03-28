#include <iostream>
#include "SFML/Graphics.hpp"
#define _CRTDBG_MAP_ALLOC

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello SFML", sf::Style::Close);
	sf::Event event;

	sf::Image test_man;
	test_man.loadFromFile("test_man.png");

	int width = test_man.getSize().x;
	int height = test_man.getSize().y;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			sf::Color color = test_man.getPixel(i, j);
			if (color == sf::Color(0, 0, 0))
			{
				test_man.setPixel(i, j, sf::Color(255, 0, 0));
			}
		}
	}

	test_man.saveToFile("post_processed.png");

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color(0, 0, 0));
		window.display();
	}

	return 0;
}