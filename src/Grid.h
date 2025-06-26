#pragma once
#include <SFML/Graphics.hpp>
#include "BinaryArray.h"

class Grid : public sf::Drawable, public sf::Transformable {
public:
	Grid(sf::Vector2u size);
	sf::Vector2u getSize() const;
	void update();
	void step();
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool at(int x, int y) const;
	const sf::Vector2u size;
	BinaryArray cells;
	sf::VertexArray vertices;
};