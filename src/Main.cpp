#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"


int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({ 720u, 480u }), "Game of Life");
	window.setFramerateLimit(60);

	sf::Image icon;
	if (!icon.loadFromFile("images/icon.png")) return 1;
	window.setIcon(icon);

	Grid grid({ 512,512 });

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			if (event->is<sf::Event::Resized>()) {
				window.setView({ {window.getSize().x / 2.f,window.getSize().y / 2.f}, {window.getSize().x * 1.f,window.getSize().y * 1.f } });
			}
		}

		grid.step();
		grid.update();

		window.clear();
		window.draw(grid);
		window.display();
	}
}
