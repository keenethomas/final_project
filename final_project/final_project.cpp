// final_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>

using namespace std;
using namespace sf;
using namespace sfp;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const float PLAYER_SPEED = 0.2f;


int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");
    World world(Vector2f(0, 0));

    //player spaceship
    RectangleShape player(Vector2f(100.0f, 100.0f));

    Texture playerTexture;
    if (!playerTexture.loadFromFile("images/player.png")) {
        return 1;
    }

    Sprite playerSprite(playerTexture);
    playerSprite.setScale(0.5f, 0.5f);
    playerSprite.setPosition(WINDOW_WIDTH / 2 - 25.0f, WINDOW_HEIGHT - 100.0f);

    //player bullets

        while (window.isOpen()) {

            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) {
                    window.close();
                }
            }

            window.clear();


            window.draw(playerSprite);

            //game stuff
            if (Keyboard::isKeyPressed(Keyboard::Left) && playerSprite.getPosition().x > 0) {
                playerSprite.move(-PLAYER_SPEED, 0);
            }
            if (Keyboard::isKeyPressed(Keyboard::Right) && playerSprite.getPosition().x < WINDOW_WIDTH - playerSprite.getGlobalBounds().width) {
                playerSprite.move(PLAYER_SPEED, 0);
            }

            window.display();
        }

        return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
