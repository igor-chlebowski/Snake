#include "Snake.h"

Snake::Snake() {
    sf::RectangleShape head(sf::Vector2f(20, 20));
    head.setFillColor(sf::Color::Green);
    head.setPosition(300, 300);
    body.push_back(head);

    direction = sf::Vector2f(20, 0);
    points = 0;

    // Generate initial food
    generateFood();
}

void Snake::eatFood() {
    sf::RectangleShape tail(sf::Vector2f(20, 20));
    tail.setFillColor(sf::Color::Green);

    

    tail.setPosition(-100, -100);
    



    this -> body.push_back(tail);

    

    //this -> body[body.size()-1].setFillColor(sf::Color::Green);
    
}

void Snake::update() {
    for (int i = body.size() - 1; i > 0; --i) {
        body[i].setPosition(body[i - 1].getPosition());
    }

    body[0].move(direction);

    // Check if snake eats food
    if (body[0].getGlobalBounds().intersects(food.getGlobalBounds())) {
        points += 10;
        eatFood();
        generateFood();
        
    }
}

void Snake::render(sf::RenderWindow& window) {
    for (const auto& segment : body) {
        window.draw(segment);
    }

    window.draw(food);


    //uncomment this piece of code to get live points counter, you need a font file in project location while building executable 

    
    /*
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Change the path to your font file
    sf::Text text;
    text.setFont(font);
    text.setString("Points: " + std::to_string(points));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    window.draw(text);
    */
}

void Snake::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up && direction.y == 0) {
            direction = sf::Vector2f(0, -20);
        } else if (event.key.code == sf::Keyboard::Down && direction.y == 0) {
            direction = sf::Vector2f(0, 20);
        } else if (event.key.code == sf::Keyboard::Left && direction.x == 0) {
            direction = sf::Vector2f(-20, 0);
        } else if (event.key.code == sf::Keyboard::Right && direction.x == 0) {
            direction = sf::Vector2f(20, 0);
        }
    }
}

bool Snake::isCollision() {
    sf::FloatRect headBounds = body[0].getGlobalBounds();

    // Check collision with window boundaries
    if (headBounds.left < 0 || headBounds.top < 0 || headBounds.left + headBounds.width > 800 || headBounds.top + headBounds.height > 600) {
        return true;
    }

    // Check collision with itself
    for (size_t i = 1; i < body.size(); ++i) {
        if (headBounds.intersects(body[i].getGlobalBounds())) {
            return true;
        }
    }

    return false;
}

void Snake::generateFood() {
    // Random number generator for food position
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disX(0, 39);
    std::uniform_int_distribution<> disY(0, 29);

    int x = disX(gen) * 20; // 20 is the width of each grid
    int y = disY(gen) * 20; // 20 is the height of each grid

    food.setSize(sf::Vector2f(20, 20));
    food.setFillColor(sf::Color::Red);
    food.setPosition(x, y);
}