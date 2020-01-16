#include "Ball.h"
#include "Rand.h"
#include "BallApp.h"

Ball::Ball()
{
  x = y = 0;
  vx = vy = 0;
  ax = ay = 0;
}

Ball::~Ball()
{
}

void Ball::init()
{
  x = BallApp::window.getSize().x / 2;
  y = BallApp::window.getSize().y / 2;
  vx = Rand::range(-300, 300);
  vy = Rand::range(-300, 300);
  ax = 0;
  ay = 0;

  texture = new sf::Texture;
  texture->loadFromFile("bomb.png");

  sprite.setTexture(*texture);
  auto size = texture->getSize()/2u;
  sprite.setOrigin(size.x, size.y);

  rap.reset();
}

void Ball::update()
{
  double dt = rap.get();
  rap.reset();
  
  vx += ax * dt;
  vy += ay * dt;
  x += vx * dt;
  y += vy * dt;

  if (x < 0 || x > BallApp::window.getSize().x - 1)
    vx = -vx;
  if (y < 0 || y > BallApp::window.getSize().y - 1)
    vy = -vy;
}

void Ball::draw()
{
  sprite.setPosition(x, y);
  BallApp::window.draw(sprite);
}

void Ball::clean()
{
  delete texture;
}
