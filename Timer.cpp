#include "Timer.h"

Timer::Timer()
{
  timer.restart();
}

Timer::~Timer()
{
}

void Timer::reset()
{
  timer.restart();
}

double Timer::get() const
{
  return timer.getElapsedTime().asSeconds();
}
