#include <random>
#include "Rand.h"

double Rand::range(double a, double b)
{
  static std::random_device rnd;
  static std::mt19937_64 mt(rnd());

  std::uniform_real_distribution<> sr(a, b);

  return sr(mt);
}
