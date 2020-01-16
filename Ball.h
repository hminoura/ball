#pragma once
#include <random>
#include "Timer.h"
#include <SFML/Graphics.hpp>

class Ball {
protected:
  double x, y;
  double vx, vy;
  double ax, ay;

  Timer timer;
  Timer rap;

  double life;

  sf::Texture* texture;
  sf::Sprite sprite;

 public:
  Ball();
  ~Ball();

  void init();
  void update();
  void draw();
  void clean();
};
