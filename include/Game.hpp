#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class Game
{
public:
  Game(const Game &) = delete;
  Game & operator = (const Game &) = delete;
  Game();
  void run(unsigned);
  
private:
  void processEvents();
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
  void update(const sf::Time &);
  void render();

  sf::RenderWindow mWindow;
  sf::Texture mBackgroundTexture;
  sf::Sprite mBackgroundSprite;
  sf::CircleShape mPlayer;

  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};


#endif // GAME_HPP
