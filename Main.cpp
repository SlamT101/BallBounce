#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

int BallRadius = 150;

int posX = 0;
int posY = 0;

int MaxX = 2560 - 2 * BallRadius;
int MaxY = 1440 - 2 * BallRadius;

bool BounceX = false;
bool BounceY = false;

int BounceCount = 0;

int main()
{
    std::system("color 0b");
    std::system("echo Sanity Check");

    sf::RenderWindow window(sf::VideoMode(2560, 1440), "BouncyBall Testing");
    sf::CircleShape Bigboi(BallRadius);
    Bigboi.setFillColor(sf::Color::Blue);
    sf::Color colorArray[6] = {sf::Color::Cyan, sf::Color::Blue, sf::Color::Green, sf::Color::Red, sf::Color::Yellow, sf::Color::White};


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!BounceX)
        {
            posX++;
            if (posX >= MaxX)
            {
                BounceX = true;
                Bigboi.setFillColor(colorArray[rand() % 6]);
                std::cout << BounceCount << "\n";
                BounceCount++;
            }
        }
        else
        {
            posX--;
            if (posX <= 0)
            {
                BounceX = false;
                Bigboi.setFillColor(colorArray[rand() % 6]);
                std::cout << BounceCount << "\n";
                BounceCount++;
            }
        }

        if (!BounceY)
        {
            posY++;
            if (posY >= MaxY)
            {
                BounceY = true;
                Bigboi.setFillColor(colorArray[rand() % 6]);
                std::cout << BounceCount << "\n";
                BounceCount++;
            }
        }
        else
        {
            posY--;
            if (posY <= 0)
            {
                BounceY = false;
                Bigboi.setFillColor(colorArray[rand() % 6]);
                std::cout << BounceCount << "\n";
                BounceCount++;
            }
        }

        window.clear();
        Bigboi.setPosition(posX, posY);
        window.draw(Bigboi);
        window.display();
    }

    return 0;
}