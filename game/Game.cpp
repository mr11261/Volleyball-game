#include "Game.hpp"
#include "Player.hpp"

Game::Game(sf::RenderWindow& window)
    : mWindow{window},
      mLeftPlayer{Player::Type::Left},
      mRightPlayer{Player::Type::Right},
      mIsLeftPlayerMovingLeft{false},
      mIsLeftPlayerMovingRight{false},
      mIsRightPlayerMovingLeft{false},
      mIsRightPlayerMovingRight{false} {}

AppStatus Game::processEvents(const sf::Event& event) {
  switch (event.type) {
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::Escape) {
        return AppStatus::PAUSE;
      }
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    default:
      break;
  }
  return AppStatus::GAME;
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
    mLeftPlayer.goLeft();
  if (mIsLeftPlayerMovingRight)
    mLeftPlayer.goRight();
  if (mIsRightPlayerMovingLeft)
    mRightPlayer.goLeft();
  if (mIsRightPlayerMovingRight)
    mRightPlayer.goRight();

  mLeftPlayer.update(timePerFrame);
  mRightPlayer.update(timePerFrame);
}

void Game::draw() {
  mWindow.draw(mNet);
  mWindow.draw(mLeftPlayer);
  mWindow.draw(mRightPlayer);
}
