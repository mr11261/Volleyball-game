#include "Player.hpp"
#include "Configuration.hpp"

Player::Player(Player::Type type) : mType{type} {
  auto left{type == Player::Type::Left ? 100.f : 1040.f};
  auto top{Configuration::WINDOW_HEIGHT - Configuration::PLAYER_HEIGHT};
  auto width{Configuration::PLAYER_WIDTH};
  auto height{Configuration::PLAYER_HEIGHT};

  mHead.setRadius(width / 2);
  mBody.setSize(sf::Vector2f{width, height - width});
  mLegs.setRadius(width / 2);

  mHead.setPosition(left, top);
  mBody.setPosition(left, top + width / 2);
  mLegs.setPosition(left, top + height - width);

  auto color{type == Player::Type::Left ? sf::Color::Blue : sf::Color::Red};
  mHead.setFillColor(color);
  mBody.setFillColor(color);
  mLegs.setFillColor(color);
}

void Player::goLeft(float steps) {
  move(sf::Vector2f{-steps, 0.f});
}

void Player::goRight(float steps) {
  move(sf::Vector2f{steps, 0.f});
}

void Player::jump() {
  // to do..
}

void Player::move(const sf::Vector2f& movement) {
  mHead.move(movement);
  mBody.move(movement);
  mLegs.move(movement);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(mHead, states);
  target.draw(mBody, states);
  target.draw(mLegs, states);
}
