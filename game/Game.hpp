#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Net.hpp"
#include "Player.hpp"

class Game {
 public:
  Game(const Game&) = delete;
  Game& operator=(const Game&) = delete;

  Game();
  void run(unsigned minimumFramePerSeconds);

 private:
  void processEvents();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
  void update(const sf::Time& timePerFrame);
  void render();

  sf::RenderWindow mWindow;
  sf::CircleShape mBall;
  Net mNet;
  Player mLeftPlayer;
  Player mRightPlayer;

  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};

#endif  // GAME_HPP
