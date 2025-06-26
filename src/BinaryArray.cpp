#include "BinaryArray.h"

BinaryArray::BinaryArray(unsigned size) : size(size) {
	if (size % 8 != 0) throw std::out_of_range("BinaryArray::BinaryArray Parameter size must be divisible by 8");
	if (size < 8) throw std::out_of_range("BinaryArray::BinaryArray Parameter size must be 8 or greater");
	p = new uint8_t[size / 8];
}

BinaryArray::BinaryArray(const BinaryArray& source) : size(source.size) {
	p = new uint8_t[size / 8];
	std::memcpy(p, source.p, source.size/8);
}

BinaryArray& BinaryArray::operator=(const BinaryArray& source) {
	if (this != &source) {  // Защита от самоприсваивания
		delete[] p;         // Освобождаем старые данные

		size = source.size; // Копируем размер
		p = new uint8_t[size / 8];
		std::memcpy(p, source.p, source.size / 8);
	}
	return *this;           // Возвращаем текущий объект
}

BinaryArray::~BinaryArray() {
	delete[] p;
}

bool BinaryArray::get(int i) const {
	if (i < 0 || i >= size) return false;
	return p[i / 8] & (0b10000000 >> (i%8));
}

void BinaryArray::set(int i, bool value) {
	if (i < 0 || i >= size) return;
	if (value) {
		p[i / 8] |= (0b10000000 >> (i % 8));
	}
	else {
		p[i / 8] &= ~(0b10000000 >> (i % 8));
	}
}