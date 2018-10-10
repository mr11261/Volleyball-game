#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "AppStatus.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Pause.hpp"

class Application : private sf::NonCopyable {
 public:
  Application();
  void run(unsigned minimumFramePerSeconds);

 private:
  void processEvents();
  void update(const sf::Time& timePerFrame);
  void render();

  sf::RenderWindow mWindow;
  AppStatus mAppStatus;
  Menu mMenu;
  Game mGame;
  Pause mPause;
};

#endif  // APPLICATION_HPP
