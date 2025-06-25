#include "Grid.h"

Grid::Grid(sf::Vector2u size, unsigned k) : size(size), cells(size.x* size.y), rectangles(size.x* size.y) {
	for (int i = 0; i < size.x * size.y; i++) {
		rectangles[i].setPosition({ i % size.x * k * 1.f, i / size.x * k * 1.f });
		rectangles[i].setSize({ k * 1.f, k * 1.f });
		rectangles[i].setFillColor(sf::Color::Green);

		cells[i] = rand() % 2;
	};
}
sf::Vector2u Grid::getSize() const {
	return size;
};
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	for (sf::RectangleShape rect : rectangles) target.draw(rect);
}
void Grid::update() {
	for (int i = 0; i < size.x * size.y; i++) {
		rectangles[i].setFillColor(cells[i] ? sf::Color::White : sf::Color::Black);
	};
}
