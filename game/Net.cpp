#include "Net.hpp"
#include "Configuration.hpp"

Net::Net() {
  mNet.setPosition(
      ((float)Configuration::WINDOW_WIDTH - Configuration::NET_WIDTH) / 2.f,
      (float)Configuration::WINDOW_HEIGHT - Configuration::NET_HEIGHT);
  mNet.setSize(
      sf::Vector2f{Configuration::NET_WIDTH, Configuration::NET_HEIGHT});
  mNet.setFillColor(sf::Color::Yellow);
}

sf::FloatRect Net::getRectBounds() const {
  return mNet.getLocalBounds();
}

void Net::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(mNet, states);
}
