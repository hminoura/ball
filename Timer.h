#pragma once
#include <SFML/System/Clock.hpp>

class Timer
{
  sf::Clock timer;
 public:
  Timer();
  virtual ~Timer();

  void reset();
  double get() const;
};
