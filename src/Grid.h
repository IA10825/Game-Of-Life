#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Grid : public sf::Drawable, public sf::Transformable {
public:
	Grid(sf::Vector2u size, unsigned k = 2);
	sf::Vector2u getSize() const;
	void update();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	const sf::Vector2u size;
	std::vector<bool> cells;
	std::vector<sf::RectangleShape> rectangles;
};