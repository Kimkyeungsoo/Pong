#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"
#include "Block.h"
#include "BlockArray.h"
#include <Windows.h>

using namespace sf;

#define xSize 14
#define ySize 5

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);
	/****************************************************************************
	* 커서 숨기기 추가
	*****************************************************************************/
	window.setMouseCursorVisible(false);
	/****************************************************************************/
	Font fontDS_DIGI;
	fontDS_DIGI.loadFromFile("fonts/DS-DIGI.TTF.ttf");

	Text textMessage;
	textMessage.setFont(fontDS_DIGI);
	textMessage.setString("- Press SpaceBar to start -");
	textMessage.setCharacterSize(100);
	textMessage.setFillColor(Color::White);

	FloatRect textRect = textMessage.getLocalBounds();
	textMessage.setOrigin(
		textRect.left + textRect.width * 0.5f,
		textRect.top + textRect.height * 0.5f
	);

	textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

	Bat bat(1920.f * 0.5 - 50, 1080.f - 100);
	Ball ball(1920.f * 0.5 - 5, 1080.f - 110);
	BlockArray blockArray(xSize, ySize);

	Clock clock;

	bool prevColSide = false;
	bool prevColTop = false;
	bool prevColBat = false;
	/****************************************************************************
	* 조건 추가
	*****************************************************************************/
	bool prevColStart = false;
	bool prevColBlock = false;
	/****************************************************************************/

	while (window.isOpen())
	{
		Time dt = clock.restart();
		float deltaTime = dt.asSeconds();

		// 키입력
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		// Input
		bool prevBarLeftRock = false;
		bool prevBarRightRock = false;
		Sides dir = Sides::NONE;
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			dir = Sides::LEFT;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dir = Sides::RIGHT;
		}
		/****************************************************************************
		* 키입력 추가
		*****************************************************************************/
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			prevColStart = true;
		}
		/****************************************************************************/
		bat.SetMoveDir(dir);

		// Update
		bat.Update(deltaTime);
		if (prevColStart)
		{
			ball.Update(deltaTime);
		}
		else
		{
			//ball.SetPosition(bat.GetPositionX());
		}

		// Ball 충돌 체크
		FloatRect ballBound = ball.GetGlobalBounds();
		Vector2u windowSize = window.getSize();

		bool colSide = ballBound.left < 0 || ballBound.left + ballBound.width > windowSize.x;
		bool colTop = ballBound.top < 0.f;
		bool colBat = ballBound.intersects(bat.GetGlobalBounds());

		if (colSide && !prevColSide) // 좌우 벽 충돌
		{
			ball.ReboundSides();
		}
		if (colTop && !prevColTop) // 위 벽 충돌
		{
			ball.ReboundBatOrTop();
		}

		if (colBat && !prevColBat) // 배트 충돌
		{
			ball.ReboundBatOrTop();
		}
		else if (ballBound.top + ballBound.height > windowSize.y) // 아래 벽 충돌
		{
			ball.ReboundBottom();

			prevColStart = false;
		}
		prevColSide = colSide;
		prevColTop = colTop;
		prevColBat = colBat;

		// Draw
		window.clear();
		if (!prevColStart)
		{
			window.draw(textMessage);
		}
		window.draw(bat.GetShape());
		window.draw(ball.GetShape());
		for (int i = 0; i < xSize * ySize; i++)
		{
			window.draw(blockArray.GetShape(i));
		}

		window.display();
	}

	return 0;
}