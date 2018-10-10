#include "Menu.hpp"
#include <iostream>
#include <cstdlib>

Menu::Menu(sf::RenderWindow& window)
    : mWindow(window), mGui(mWindow), isStartPressed{false} {
  try {
    loadWidgets();
  } catch (const tgui::Exception& e) {
    std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Menu::loadWidgets() {
  auto startButton = tgui::Button::create("START");
  startButton->setSize({"40%", "10%"});
  startButton->setPosition({"10%", "10%"});
  mGui.add(startButton);

  auto exitButton = tgui::Button::create("EXIT");
  exitButton->setSize({"40%", "10%"});
  exitButton->setPosition({"10%", "25%"});
  mGui.add(exitButton);

  startButton->connect("pressed", [&]() { isStartPressed = true; });
  exitButton->connect("pressed", [&]() { mWindow.close(); });
}

AppStatus Menu::processEvents(const sf::Event& event) {
  mGui.handleEvent(event);
  if (isStartPressed == true) {
    isStartPressed = false;
    return AppStatus::GAME;
  } else {
    return AppStatus::MENU;
  }
}

void Menu::draw() {
  mGui.draw();
}
