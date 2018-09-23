#include "Net.hpp"

Net::Net() {
  mNet.setPosition(600.f, 300.f);
  mNet.setSize(sf::Vector2f{20.f, 400.f});
  mNet.setFillColor(sf::Color::Yellow);
}

sf::FloatRect Net::getRectBounds() const {
  return mNet.getLocalBounds();
}

void Net::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(mNet, states);
}
