#include "BallApp.h"

int main()
{
  App* app;
  
  app = new BallApp();

  app->init();
  
  while (app->isActive()){
    app->event();
    app->update();
    app->draw();
    app->waitSync();
  }

  app->clean();

  delete app;
}

