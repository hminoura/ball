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
  theta = Rand::range(0, 360);
  vtheta = Rand::range(-360, 360);

  image.loadFromFile("ball.png");
  texture.loadFromImage(image);

  auto center = texture.getSize()/2u;
  sprite.setTexture(texture, true);
  sprite.setOrigin(center.x, center.y);

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

  theta += vtheta * dt;
}

void Ball::draw()
{
  sprite.setPosition(x, y);
  sprite.setRotation(theta);
  BallApp::window.draw(sprite);
}

void Ball::clean()
{
}
