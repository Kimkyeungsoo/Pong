#pragma once

#include "Block.h"
#include "SFML/Graphics.hpp"

using namespace sf;

class BlockArray
{
private:
	Block* blockArray;
	int xCount;
	int yCount;

	//Vector2f position;
	//RectangleShape shape;
public:
	BlockArray(const int& x, const int& y);
	~BlockArray();

	FloatRect GetGlobalBounds(int i);
	const RectangleShape& GetShape(int i);
};

