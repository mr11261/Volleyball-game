#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Net.hpp"
#include "Player.hpp"
#include "AppStatus.hpp"

class Game : private sf::NonCopyable {
 public:
  explicit Game(sf::RenderWindow& window);
  AppStatus processEvents(const sf::Event& event);
  void update(const sf::Time& timePerFrame);
  void draw();

 private:
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

  sf::RenderWindow& mWindow;
  Net mNet;
  Player mLeftPlayer;
  Player mRightPlayer;

  bool mIsLeftPlayerMovingLeft;
  bool mIsLeftPlayerMovingRight;
  bool mIsRightPlayerMovingLeft;
  bool mIsRightPlayerMovingRight;
};

#endif  // GAME_HPP
