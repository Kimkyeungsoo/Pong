#include "Ball.h"
#include <cmath>

Ball::Ball(float x, float y)
	: originalPosition(x, y), position(x, y)
{
	// ���� ����
	dir.x = 1.f;
	dir.y = 1.f;

	float length = sqrt(dir.x * dir.x + dir.y * dir.y); // ������ ����
	dir.x /= length;
	dir.y /= length;

	// shape �ʱ�ȭ
	shape.setSize(Vector2f(10, 10));
	shape.setPosition(position);
	shape.setFillColor(Color::White);
}

FloatRect Ball::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}

const RectangleShape& Ball::GetShape()
{
	return shape;
}

void Ball::ReboundSides()
{
	dir.x *= -1.f;
}

void Ball::ReboundBatOrTop()
{
	dir.y *= -1.f;
}

void Ball::ReboundBottom()
{
	//dir.y *= -1.f;
	position.y = originalPosition.y;
}

void Ball::Update(float dt)
{
	position += dir * dt * speed;
	shape.setPosition(position);
}
