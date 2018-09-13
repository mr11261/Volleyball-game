#ifndef NET_HPP
#define NET_HPP

#include <SFML/Graphics.hpp>

class Net : public sf::Drawable {
 public:
  Net(const Net&) = delete;
  Net& operator=(const Net&) = delete;

  Net();
  sf::FloatRect getRectBounds() const;

 private:
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;

  sf::RectangleShape mNet;
};

#endif  // NET_HPP
