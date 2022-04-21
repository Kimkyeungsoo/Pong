#include "Bat.h"

Bat::Bat(float x, float y)
	: position(x, y)
{
	shape.setSize(Vector2f(100, 5));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect Bat::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}
const RectangleShape& Bat::GetShape()
{
	return shape; // 렌더링 할 때 사용
}

void Bat::SetMoveDir(Sides side)
{
	moveDir = side;
}

void Bat::Update(float dt)
{
	Vector2f dir;
	switch (moveDir)
	{
	case Sides::LEFT:
		dir.x = -1.f; // 왼쪽으로의 단위벡터
		break;
	case Sides::RIGHT:
		dir.x = 1.f; // 오른쪽으로의 단위벡터
		break;
	}
	position += dir * dt * speed;
	shape.setPosition(position);
}
