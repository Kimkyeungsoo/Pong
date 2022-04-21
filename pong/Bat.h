#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
// 그리기 : RectangleShape
// 이동 : 
	// main함수에서 키입력을 받아서 왼쪽으로 이동함수, 오른쪽으로 이동함수
	// 속도, 시간 을 기준으로 움직인다.

enum class Sides
{
	LEFT,
	RIGHT,
	NONE,
};

class Bat
{
private:
	Vector2f position;

	RectangleShape shape; // 그리기용 함수

	float speed = 1000.f;
	Sides moveDir = Sides::NONE;
public:
	Bat();
	Bat(float x, float y);

	FloatRect GetGlobalBounds();	// 충돌 체크
	const RectangleShape& GetShape();

	//float GetPositionX() const;
	//void ReboundSides();

	void SetMoveDir(Sides side);

	void Update(float dt);
};

