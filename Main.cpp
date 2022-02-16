#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

int BallScale = 10;

int sizeX = sf::VideoMode::getDesktopMode().width;
int sizeY = sf::VideoMode::getDesktopMode().height;


int BallRadius = sizeX*sizeY*0.000001*BallScale;

int MaxX = sizeX - 2 * BallRadius;
int MaxY = sizeY - 2 * BallRadius;

int posX = rand()%sizeX;
int posY = rand()%sizeY;

bool BounceX = false;
bool BounceY = false;

int BounceCount = 0;


int main()
{
    std::system("color 0b");
    std::system("echo Sanity Check");

    //WinConfig();

    sf::RenderWindow window(sf::VideoMode(sizeX, sizeY), "Ball Bouncing");
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