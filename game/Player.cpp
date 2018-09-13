#include "Player.hpp"

Player::Player(Player::Type type) : mType{type} {
  mHead.setRadius(40.f);
  mBody.setSize(sf::Vector2f{80.f, 150.f});
  mLegs.setRadius(40.f);

  if (mType == Player::Type::Left) {
    mHead.setPosition(100.f, 470.f);
    mBody.setPosition(100.f, 510.f);
    mLegs.setPosition(100.f, 620.f);

    mHead.setFillColor(sf::Color::Blue);
    mBody.setFillColor(sf::Color::Blue);
    mLegs.setFillColor(sf::Color::Blue);
  } else {
    mHead.setPosition(1040.f, 470.f);
    mBody.setPosition(1040.f, 510.f);
    mLegs.setPosition(1040.f, 620.f);

    mHead.setFillColor(sf::Color::Red);
    mBody.setFillColor(sf::Color::Red);
    mLegs.setFillColor(sf::Color::Red);
  }
}

void Player::goLeft(float steps) {
  // to do..
}

void Player::goRight(float steps) {
  // to do..
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
