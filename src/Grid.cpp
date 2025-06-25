#include "Grid.h"

Grid::Grid(sf::Vector2u size, unsigned k) : size(size), cells(size.x* size.y), rectangles(size.x* size.y) {
	for (unsigned i = 0; i < size.x * size.y; i++) {
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
void Grid::step() {
	std::vector<bool> bCells = cells;
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
			if (neighbors < 2 || neighbors > 3) bCells[y * size.x + x] = false;
			if (neighbors == 3) bCells[y * size.x + x] = true;
		}
	}
	cells = bCells;
}
void Grid::update() {
	for (unsigned i = 0; i < size.x * size.y; i++) {
		rectangles[i].setFillColor(cells[i] ? sf::Color::White : sf::Color::Black);
	};
}

bool Grid::at(int x, int y) const {
	if (x >= size.x || x<0 || y >= size.y || y<0) {
		return false;
	}
	return cells[size.x * y + x];
}
