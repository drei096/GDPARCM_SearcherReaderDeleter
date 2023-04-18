#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Application
{
public:
    static const int WINDOW_WIDTH = 1280;
    static const int WINDOW_HEIGHT = 720;
    static const sf::Time	TIME_PER_FRAME;

    Application();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

private:
    sf::RenderWindow mWindow;
    sf::Font* font;
    sf::Text* fpsText;
    sf::Text* fpsCount;

};

