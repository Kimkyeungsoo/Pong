#include "Block.h"

Block::Block()
{
	shape.setSize(Vector2f(100.0, 50.0));
	shape.setPosition(0.0, 0.0);
	shape.setFillColor(Color::White);
}

FloatRect Block::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Block::GetShape()
{
	return shape;
}

void Block::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	shape.setPosition(position);
}
