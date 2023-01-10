#pragma once
#include <vector>
#include "App.h"
#include "Ball.h"

class BallApp : public App, public KeyboardListener, public MouseListener {
private:
  int nballs;
  std::vector<Ball> balls;

public:
  BallApp();
  ~BallApp();
  void init();
  void update();
  void draw();
  void clean();
  void onKeyDown(sf::Keyboard::Key key);
  void onMouseMoved(sf::Event::MouseMoveEvent mouse);
  void onClick(sf::Event::MouseButtonEvent mouse);
  void offClick(sf::Event::MouseButtonEvent mouse);
  void setNBalls(int n);
};
