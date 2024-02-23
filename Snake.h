#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

class Snake {
public:
    Snake();
    void update();
    void render(sf::RenderWindow& window);
    void handleInput(sf::Event& event);
    bool isCollision();
    int points;
    std::vector<sf::RectangleShape> body;
    void eatFood();
    sf::Vector2f direction;

private:

    // Points

    // Private member function to generate food
    void generateFood();
    sf::RectangleShape food;
};