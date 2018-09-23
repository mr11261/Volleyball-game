#include "Game.hpp"
#include "Player.hpp"
#include "Configuration.hpp"

Game::Game()
    : mWindow{sf::VideoMode{Configuration::WINDOW_WIDTH,
                            Configuration::WINDOW_HEIGHT},
              "Volleyball"},
      mLeftPlayer{Player::Type::Left},
      mRightPlayer{Player::Type::Right},
      mIsLeftPlayerMovingLeft{false},
      mIsLeftPlayerMovingRight{false},
      mIsRightPlayerMovingLeft{false},
      mIsRightPlayerMovingRight{false} {
  mWindow.setVerticalSyncEnabled(true);
  mBall.setRadius(40.f);
  mBall.setPosition(100.f, 100.f);
  mBall.setFillColor(sf::Color::Cyan);
}

void Game::run(unsigned minimumFramePerSeconds) {
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

void Game::processEvents() {
  sf::Event event;

  while (mWindow.pollEvent(event)) {
    switch (event.type) {
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

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::A)
    mIsLeftPlayerMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
    mIsLeftPlayerMovingRight = isPressed;
  else if (key == sf::Keyboard::Left)
    mIsRightPlayerMovingLeft = isPressed;
  else if (key == sf::Keyboard::Right)
    mIsRightPlayerMovingRight = isPressed;
}

void Game::update(const sf::Time& timePerFrame) {
  if (mIsLeftPlayerMovingLeft)
    mLeftPlayer.goLeft(timePerFrame.asSeconds() * 100.f);
  if (mIsLeftPlayerMovingRight)
    mLeftPlayer.goRight(timePerFrame.asSeconds() * 100.f);
  if (mIsRightPlayerMovingLeft)
    mRightPlayer.goLeft(timePerFrame.asSeconds() * 100.f);
  if (mIsRightPlayerMovingRight)
    mRightPlayer.goRight(timePerFrame.asSeconds() * 100.f);
}

void Game::render() {
  mWindow.clear();
  mWindow.draw(mNet);
  mWindow.draw(mBall);
  mWindow.draw(mLeftPlayer);
  mWindow.draw(mRightPlayer);
  mWindow.display();
}
