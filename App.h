#include <SFML/Graphics.hpp>

class MouseListener {
public:
  virtual void onClick(sf::Event::MouseButtonEvent mouse)=0;
  virtual void offClick(sf::Event::MouseButtonEvent mouse)=0;
  virtual void onMouseMoved(sf::Event::MouseMoveEvent mouse)=0;
};

class KeyboardListener {
public:
  virtual void onKeyDown(sf::Keyboard::Key key)=0;
};

class App {
protected:
  KeyboardListener* keyListener;
  MouseListener* mouseListener;
  sf::Clock clock;
  sf::Clock rap;
public:
  static unsigned w_width;
  static unsigned w_height;
  static sf::RenderWindow window;

  static const sf::Time sync;

  App();
  virtual ~App();
  void setKeyboardListener(KeyboardListener *keyListener);
  void setMouseListener(MouseListener *mouseListener);
  virtual void init();
  virtual bool isActive();
  virtual void draw();
  virtual void update() = 0;
  virtual void event();
  virtual void waitSync();
  virtual void clean();
};

