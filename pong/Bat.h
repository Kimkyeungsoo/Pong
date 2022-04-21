#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
// �׸��� : RectangleShape
// �̵� : 
	// main�Լ����� Ű�Է��� �޾Ƽ� �������� �̵��Լ�, ���������� �̵��Լ�
	// �ӵ�, �ð� �� �������� �����δ�.

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

	RectangleShape shape; // �׸���� �Լ�

	float speed = 1000.f;
	Sides moveDir = Sides::NONE;
public:
	Bat();
	Bat(float x, float y);

	FloatRect GetGlobalBounds();	// �浹 üũ
	const RectangleShape& GetShape();

	//float GetPositionX() const;
	//void ReboundSides();

	void SetMoveDir(Sides side);

	void Update(float dt);
};

