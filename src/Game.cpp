#include "Game.hpp"
#include <iostream>

Game::Game()
  : mWindow(sf::VideoMode(1010, 600), "Volleyball"),
    mPlayer(),
    mIsMovingUp(false),
    mIsMovingDown(false),
    mIsMovingLeft(false),
    mIsMovingRight(false)
{
  mWindow.setVerticalSyncEnabled(true);
  
  mPlayer.setRadius(40.f);
  mPlayer.setPosition(100.f, 100.f);
  mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run(unsigned minimumFramePerSeconds)
{
  // game loop:
  sf::Clock clock;
  sf::Time timeSinceLastUpdate;
  const sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

  while (mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate = clock.restart();
    
    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      update(timePerFrame);
    }
    
    update(timeSinceLastUpdate);
    render();
  }
}

void Game::processEvents()
{
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    switch(event.type) {
    case sf::Event::KeyPressed:
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      mWindow.close();
      break;
    default:
      break;
    }
  }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
  if(key == sf::Keyboard::W)
    mIsMovingUp = isPressed;
  else if(key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
  else if(key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;
  else if(key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}

void Game::update(const sf::Time & timePerFrame)
{
  sf::Vector2f movement(0.f, 0.f);
  if(mIsMovingUp)
    movement.y -= 1.f;
  if(mIsMovingDown)
    movement.y += 1.f;
  if(mIsMovingLeft)
    movement.x -= 1.f;
  if(mIsMovingRight)
    movement.x += 1.f;

  mPlayer.move(movement * (timePerFrame.asSeconds() * 100.f));
}

void Game::render()
{
  mWindow.clear();
  mWindow.draw(mBackgroundSprite);
  mWindow.draw(mPlayer);
  mWindow.display();
}
