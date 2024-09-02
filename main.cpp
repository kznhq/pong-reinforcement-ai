#include <SFML/Graphics.hpp>

int main()
{
    const float windowLength = 640.f;
    const float windowHeight = 480.f;
    const float paddleWidth = windowLength / 75;
    const float paddleHeight = windowHeight / 7;
    const float ballRadius = paddleWidth / 2;

    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "The Final Pong");
    window.setFramerateLimit(60);

    sf::RectangleShape player1(sf::Vector2f(paddleWidth, paddleHeight));
    sf::RectangleShape player2(sf::Vector2f(paddleWidth, paddleHeight));
    player1.setPosition(paddleWidth * 2, (windowHeight / 2) - (paddleHeight / 2));
    player2.setPosition(windowLength - (paddleWidth * 3), (windowHeight / 2) - (paddleHeight / 2));
    player1.setFillColor(sf::Color(200, 0, 0));
    player2.setFillColor(sf::Color(0, 200, 0));

    sf::CircleShape ball(ballRadius);
    ball.setPosition(windowLength / 2 - 2 * ballRadius, windowHeight / 2 - 2 * ballRadius);
    ball.setFillColor(sf::Color(255, 255, 255));

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(20, 20, 170));
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();
    }

    return 0;
}
