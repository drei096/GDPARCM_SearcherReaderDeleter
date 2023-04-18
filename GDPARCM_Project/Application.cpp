#include "Application.h"

#include "GameObjectManager.h"
#include "SceneManager.h"
#include "NonThreadedScene.h"
#include "ThreadedScene_1.h"
#include "TextureManager.h"

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);
const float FRAME_RATE = 60.0f;

Application::Application() :
mWindow(sf::VideoMode(Application::WINDOW_WIDTH, Application::WINDOW_HEIGHT), "SFML Application")
{
    this->mWindow.setFramerateLimit(int(FRAME_RATE));

    font = new sf::Font();
    font->loadFromFile("Media/Sansation.ttf");

    fpsText = new sf::Text();
    fpsText->setFont(*font);
    fpsText->setCharacterSize(48);

    fpsCount = new sf::Text();
    fpsCount->setFont(*font);
    fpsCount->setCharacterSize(48);

    SceneManager::getInstance()->registerScene(new ThreadedScene_1());

    SceneManager::getInstance()->loadScene(SceneManager::THREADED_SCENE_1_NAME);

    
}

void Application::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen()) 
    {
        processEvents();
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        //timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {
            timeSinceLastUpdate -= TIME_PER_FRAME;
            processEvents();
            update(elapsedTime);
        }
        render();
        SceneManager::getInstance()->checkLoadScene();
    }
}

void Application::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) 
    {
        switch (event.type)
    	{
        case sf::Event::Closed:
            mWindow.close();
            break;
        default:
            break;
        }
    }
}

void Application::update(sf::Time deltaTime)
{
    GameObjectManager::getInstance()->update(deltaTime);
    SceneManager::getInstance()->checkLoadScene();

    float fps = floor(1.0f / deltaTime.asSeconds());
    char str[40];
    sprintf_s(str, "%.1f", fps);
    std::string strfps = str;
    fpsCount->setString(strfps);
}

void Application::render()
{
    mWindow.clear();

    GameObjectManager::getInstance()->draw(&mWindow);
    fpsText->setString("FPS:");
    fpsText->setPosition(WINDOW_WIDTH - 300, WINDOW_HEIGHT - 100);
    mWindow.draw(*fpsText);

    fpsCount->setPosition(WINDOW_WIDTH - 200, WINDOW_HEIGHT - 100);
    mWindow.draw(*fpsCount);

    mWindow.display();
}
