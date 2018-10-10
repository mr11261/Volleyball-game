#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <SFML/Graphics.hpp>

class Configuration : private sf::NonCopyable {
 public:
  Configuration() = delete;

  static constexpr unsigned WINDOW_WIDTH{1220};
  static constexpr unsigned WINDOW_HEIGHT{700};
  static constexpr float PLAYER_WIDTH{80.f};
  static constexpr float PLAYER_HEIGHT{230.f};
  static constexpr float NET_WIDTH{20.f};
  static constexpr float NET_HEIGHT{400.f};
  static constexpr float BALL_RADIUS{40.f};
};

#endif  // CONFIGURATION_HPP
