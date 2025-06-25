#include <SFML/Graphics.hpp>
#include "Grid.h"

int main()
{
	auto window = sf::RenderWindow(sf::VideoMode({ 720u, 480u }), "CMake SFML Project");
	window.setFramerateLimit(144);

	Grid grid({ 64,64 }, 4);

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

		grid.update();

		window.clear();
		window.draw(grid);
		window.display();
	}
}
