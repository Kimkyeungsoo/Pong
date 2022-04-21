#include <SFML/Graphics.hpp>
#include "Bat.h"
#include "Ball.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Pong!", Style::Fullscreen);

    Bat bat(1920.f * 0.5, 1080.f - 100);
    Ball ball(1920.f * 0.5, 0.f);

    Clock clock;

    bool prevcolSide = false;
    bool prevColTop = false;
    bool prevColBat = false;

    while (window.isOpen())
    {
        Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        // Input
        Sides dir = Sides::NONE;
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            dir = Sides::LEFT;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            dir = Sides::RIGHT;
        }
        bat.SetMoveDir(dir);        

        // Update
        bat.Update(deltaTime);
        ball.Update(deltaTime);

        // 충돌 체크
        FloatRect ballBound = ball.GetGlobalBounds();
        Vector2u windowSize = window.getSize();

        bool colSide = ballBound.left < 0 || ballBound.left + ballBound.width > windowSize.x;
        bool colTop = ballBound.top < 0.f;
        bool colBat = ballBound.intersects(bat.GetGlobalBounds());
        
        if (colSide && !prevcolSide) // 좌우 벽 충돌
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
            break;
            ball.ReboundBottom();
        }

        prevcolSide = colSide;
        prevColTop = colTop;
        prevColBat = colBat;

        // Draw
        window.clear();
        window.draw(bat.GetShape());
        window.draw(ball.GetShape());
        window.display();
    }

    return 0;
}