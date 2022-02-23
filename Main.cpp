#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

int BallScale = 10;

int sizeX = sf::VideoMode::getDesktopMode().width;
int sizeY = sf::VideoMode::getDesktopMode().height;

int BallRadius;

int MaxX;
int MaxY;

int posX;
int posY;

bool BounceX = false;
bool BounceY = false;

int BounceCount = 0;

void WinConfig(int X, int Y)
{
    sizeX = X; 
    sizeY = Y;

    BallRadius = sizeX * sizeY * 0.000001 * BallScale;

    MaxX = sizeX - 2 * BallRadius;
    MaxY = sizeY - 2 * BallRadius;

    srand(time(0));
    posX = rand() % sizeX;
    srand(time(0));
    posY = rand() % sizeY;
}

int main()
{
    std::system("color 0b");
    std::system("echo Sanity Check");

    WinConfig(sizeX, sizeY);

    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "Ball Bouncing");
    sf:: Clock Regulator;
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

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
                 WinConfig(visibleArea.width, visibleArea.height);
            }
        }

        if (!BounceX)
        {
            posX++;
            if (posX >= MaxX)
            {
                BounceX = true;
                Bigboi.setFillColor(colorArray[rand() % 6]);
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