#include "Grid.h"

Grid::Grid(sf::Vector2u size) : size(size), cells(size.x* size.y), vertices(sf::PrimitiveType::Points, size.x* size.y) {
	for (unsigned i = 0; i < size.x * size.y; i++) {
		vertices[i].position = { i % size.x * 1.f, i / size.x * 1.f };
		vertices[i].color = sf::Color::Green;
		cells.set(i, rand() % 2);
	};
}
sf::Vector2u Grid::getSize() const {
	return size;
};
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	target.draw(vertices);
}
void Grid::step() {
	BinaryArray bCells = cells;
	for (unsigned y = 0; y < size.y; y++) {
		for (unsigned x = 0; x < size.x; x++) {
			unsigned neighbors = 0;
			neighbors += at(x - 1, y - 1);
			neighbors += at(x, y - 1);
			neighbors += at(x + 1, y - 1);
			neighbors += at(x + 1, y);
			neighbors += at(x + 1, y + 1);
			neighbors += at(x, y + 1);
			neighbors += at(x - 1, y + 1);
			neighbors += at(x - 1, y);
			if (neighbors < 2 || neighbors > 3) bCells.set(size.x * y + x, false);
			if (neighbors == 3) bCells.set(size.x * y + x, true);
		}
	}
	cells = bCells;
}
void Grid::update() {
	for (unsigned i = 0; i < size.x * size.y; i++) {
		vertices[i].color = cells.get(i) ? sf::Color::White : sf::Color::Black;
	};
}

bool Grid::at(int x, int y) const {
	return cells.get(size.x * y + x);
}
