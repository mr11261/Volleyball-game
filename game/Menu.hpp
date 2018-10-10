#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "AppStatus.hpp"

class Menu : private sf::NonCopyable {
 public:
  explicit Menu(sf::RenderWindow& window);
  AppStatus processEvents(const sf::Event& event);
  void draw();

 private:
  void loadWidgets();

  sf::RenderWindow& mWindow;
  tgui::Gui mGui;
  bool isStartPressed;
};

#endif  // MANU_H
