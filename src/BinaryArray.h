#pragma once
#include <cstdint>
#include <iostream>


class BinaryArray {
public:
	BinaryArray(unsigned size);
	BinaryArray(const BinaryArray&);
	BinaryArray& operator=(const BinaryArray& source);
	~BinaryArray();
	bool get(int i) const;
	void set(int i, bool value);
private:
	unsigned size;
	std::uint8_t* p;
};