#include <iostream>
#include "Timer.h"
#include "BallApp.h"

int main()
{
  App* app;
  
  app = new BallApp();

  Timer t;
  t.reset();
  app->init();
  std::cout << t.get() << 's' << std::endl;

  while (app->isActive()){
    app->event();
    app->update();
    app->draw();
    app->waitSync();
  }

  app->clean();

  delete app;
}

