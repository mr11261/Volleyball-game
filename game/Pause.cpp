#include "Pause.hpp"
#include <iostream>
#include <cstdlib>

Pause::Pause(sf::RenderWindow& window)
  : mWindow(window),
    mGui(mWindow),
    isResumePressed{false},
    isMenuPressed{false} {
  try {
    loadWidgets();
  } catch (const tgui::Exception& e) {
    std::cerr << "Pause::Failed to load TGUI widgets: "
	      << e.what()
	      << std::endl;
    exit(EXIT_FAILURE);
  }
}

void Pause::loadWidgets() {
  
  auto resumeButton = tgui::Button::create("RESUME");
  resumeButton->setSize({"40%", "10%"});
  resumeButton->setPosition({"30%", "30%"});
  mGui.add(resumeButton);

  auto menuButton = tgui::Button::create("MENU");
  menuButton->setSize({"40%", "10%"});
  menuButton->setPosition({"30%", "45%"});
  mGui.add(menuButton);

  resumeButton->connect("pressed", [&]() {isResumePressed = true;});
  menuButton->connect("pressed", [&]() { isMenuPressed = true; });
}

AppStatus Pause::processEvents(const sf::Event& event) {
  mGui.handleEvent(event);
  if (isResumePressed == true) {
    isResumePressed = false;
    isMenuPressed = false;
    return AppStatus::GAME;
  }
  else if(isMenuPressed == true) {
    isResumePressed = false;
    isMenuPressed = false;
    return AppStatus::MENU;
  }
  else {
    return AppStatus::PAUSE;
  }
}

void Pause::draw() {
  mGui.draw();
}
