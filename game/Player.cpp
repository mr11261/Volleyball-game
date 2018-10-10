#include "Player.hpp"
#include "Configuration.hpp"

Player::Player(Player::Type type)
    : mType{type},
      mVelocityX{0.0f},
      mVelocityY{0.0f},
      gravity{0.3f},
      mOnGround{true} {
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

void Player::goLeft() {
  mVelocityX += -3.f;
}

void Player::goRight() {
  mVelocityX += 3.f;
}

void Player::jump() {
  if (mOnGround) {
    mVelocityY = -12.f;
    mOnGround = false;
  }
}

void Player::update(const sf::Time& timePerFrame) {
  mVelocityY += gravity;
  sf::Vector2f movement{mVelocityX, mVelocityY};
  movement *= timePerFrame.asSeconds() * 100.f;
  move(movement);
  mVelocityX = 0.f;
}

void Player::move(const sf::Vector2f& movement) {
  mHead.move(movement);
  mBody.move(movement);
  mLegs.move(movement);

  fixBorderCrossing();
}

void Player::fixBorderCrossing() {
  if (mHead.getPosition().y + Configuration::PLAYER_HEIGHT >
      Configuration::WINDOW_HEIGHT) {
    auto left{mHead.getPosition().x};
    auto top{Configuration::WINDOW_HEIGHT - Configuration::PLAYER_HEIGHT};
    auto width{Configuration::PLAYER_WIDTH};
    auto height{Configuration::PLAYER_HEIGHT};

    mHead.setPosition(left, top);
    mBody.setPosition(left, top + width / 2);
    mLegs.setPosition(left, top + height - width);
    mOnGround = true;
  }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(mHead, states);
  target.draw(mBody, states);
  target.draw(mLegs, states);
}
