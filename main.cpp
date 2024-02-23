#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Snake.h"






int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
    window.setFramerateLimit(10);

    Snake snake;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            snake.handleInput(event);
        }

        snake.update();

        if (snake.isCollision()) {
            std::cout << "Game Over! Points: " << snake.points << std::endl;
            window.close();
        }

        window.clear();
        snake.render(window);
        window.display();
    }

    return 0;
}
