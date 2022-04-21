#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f originalPosition;

	Vector2f position;
	RectangleShape shape;

	float speed = 500.f;
	Vector2f dir;
public:
	Ball(float x, float y);

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();
	// 충돌 처리
	void ReboundSides();
	void ReboundBatOrTop();
	void ReboundBottom();

	//void SetPosition(const float& x);

	void Update(float dt);
};

