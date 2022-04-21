#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class Block
{
private:
	Vector2f position;
	RectangleShape shape;
public:
	Block();

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();

	void SetPosition(float x, float y);
};

