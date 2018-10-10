#ifndef PAUSE_HPP
#define PAUSE_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "AppStatus.hpp"

class Pause : private sf::NonCopyable {
 public:
  explicit Pause(sf::RenderWindow& window);
  AppStatus processEvents(const sf::Event& event);
  void draw();

 private:
  void loadWidgets();

  sf::RenderWindow& mWindow;
  tgui::Gui mGui;
  bool isResumePressed;
  bool isMenuPressed;
};

#endif  // MANU_H
