#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
 public:
  enum class Type { Left, Right };

  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;

  explicit Player(Player::Type type);
  void goLeft(float steps);
  void goRight(float steps);
  void jump();

 private:
  void move(const sf::Vector2f& movement);
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;

  Type mType;
  sf::CircleShape mHead;
  sf::RectangleShape mBody;
  sf::CircleShape mLegs;
};

#endif  // PLAYER_HPP
