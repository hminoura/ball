#include "App.h"

//App::App():w_width(640),w_height(480),window(sf::VideoMode(w_width,w_height), "sample")
App::App()
{
  this->keyListener = NULL;
  this->mouseListener = NULL;
}
App::~App(){
}
void App::setKeyboardListener(KeyboardListener *keyListener){
  this->keyListener = keyListener;
}
void App::setMouseListener(MouseListener *mouseListener){
  this->mouseListener = mouseListener;
}
void App::init(){
}
bool App::isActive(){
  return window.isOpen();
}

void App::draw(){
  window.clear();
}

void App::event(){
  sf::Event event;
  while(window.pollEvent(event)){
    if (event.type == sf::Event::Closed) // 
      window.close();
    // キーボード
    if (event.type == sf::Event::EventType::KeyPressed)
      if(this->keyListener!=NULL)
	this->keyListener->onKeyDown(event.key.code);
    // マウス動き
    if (event.type == sf::Event::MouseMoved)
      if(this->mouseListener!=NULL)
	this->mouseListener->onMouseMoved(event.mouseMove);
    // マウスボタン押し
    if (event.type == sf::Event::MouseButtonPressed)
      if(this->mouseListener!=NULL)
	this->mouseListener->onClick(event.mouseButton);
    // マウスボタン離し
    if (event.type == sf::Event::MouseButtonReleased)
      if(this->mouseListener!=NULL)
	this->mouseListener->offClick(event.mouseButton);
  }
}

void App::waitSync(){
  sf::Time dt = rap.getElapsedTime();
  
  if (sync > dt)
    sf::sleep(sync - dt);

  rap.restart();
}

void App::clean() {
}

unsigned App::w_width = 800;
unsigned App::w_height = 600;
sf::RenderWindow App::window(sf::VideoMode(w_width, w_height), "sample");
const sf::Time App::sync = sf::seconds(1.0/60); // 60FPS
