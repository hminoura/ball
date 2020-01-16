#include "BallApp.h"
#include "Timer.h"

BallApp::BallApp(){
  setKeyboardListener(this);
  setMouseListener(this);
}

BallApp::~BallApp(){
}

void BallApp::init()
{
  balls.resize(1);

  for (auto& b : balls)
    b.init();
}

void BallApp::update()
{
  for (auto& b : balls)
    b.update();
}

void BallApp::draw()
{
  window.clear(sf::Color::White);

  for (auto& b : balls)
    b.draw();

  window.display();
}

void BallApp::clean()
{
  for (auto& b : balls)
    b.clean();
}  

void BallApp::onKeyDown(sf::Keyboard::Key key){
  if (key==sf::Keyboard::Escape){
    window.close();
  }
}

void BallApp::onMouseMoved(sf::Event::MouseMoveEvent mouse){
}

void BallApp::onClick(sf::Event::MouseButtonEvent mouse){
}

void BallApp::offClick(sf::Event::MouseButtonEvent mouse){
}




