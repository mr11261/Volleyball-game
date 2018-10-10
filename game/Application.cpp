#include "Application.hpp"
#include "Configuration.hpp"

Application::Application()
    : mWindow{sf::VideoMode{Configuration::WINDOW_WIDTH,
                            Configuration::WINDOW_HEIGHT},
              "Volleyball game"},
      mAppStatus{AppStatus::MENU},
      mMenu{mWindow},
      mGame{mWindow},
      mPause{mWindow} {
  mWindow.setVerticalSyncEnabled(true);
}

void Application::run(unsigned minimumFramePerSeconds) {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate;
  const sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

  while (mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate = clock.restart();

    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      update(timePerFrame);
    }

    update(timeSinceLastUpdate);
    render();
  }
}

void Application::processEvents() {
  sf::Event event;

  while (mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      mWindow.close();
    switch (mAppStatus) {
      case AppStatus::MENU:
        mAppStatus = mMenu.processEvents(event);
        break;
      case AppStatus::GAME:
        mAppStatus = mGame.processEvents(event);
        break;
      case AppStatus::PAUSE:
        mAppStatus = mPause.processEvents(event);
      default:
        break;
    }
  }
}

void Application::update(const sf::Time& timePerFrame) {
  if (mAppStatus == AppStatus::GAME)
    mGame.update(timePerFrame);
}

void Application::render() {
  mWindow.clear();
  switch (mAppStatus) {
    case AppStatus::MENU:
      mMenu.draw();
      break;
    case AppStatus::GAME:
      mGame.draw();
      break;
    case AppStatus::PAUSE:
      mGame.draw();
      mPause.draw();
    default:
      break;
  }
  mWindow.display();
}
