#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable, private sf::NonCopyable {
 public:
  enum class Type { Left, Right };

  explicit Player(Player::Type type);
  void goLeft();
  void goRight();
  void jump();
  void update(const sf::Time& timPereFrame);

 private:
  void move(const sf::Vector2f& movement);
  void fixBorderCrossing();
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;

  Type mType;
  float mVelocityX;
  float mVelocityY;
  float gravity;
  bool mOnGround;
  sf::CircleShape mHead;
  sf::RectangleShape mBody;
  sf::CircleShape mLegs;
};

#endif  // PLAYER_HPP
