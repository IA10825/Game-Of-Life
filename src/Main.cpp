#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"
#include "BinaryArray.h"


int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({ 720u, 480u }), "CMake SFML Project");
	window.setFramerateLimit(60);

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
