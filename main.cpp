#include <exception>
#include <iostream>
#include "Timer.h"
#include "BallApp.h"

using namespace std;

int main(int argc, char* argv[])
{
  App* app;

  try { 
    if (argc != 2)
      throw invalid_argument("");
  }
  catch (invalid_argument &e) {
    cout << argv[0] << " <num>" << endl;
    exit(-1);
  }

  app = new BallApp();
  dynamic_cast<BallApp*>(app)->setNBalls(atoi(argv[1]));

  // 初期化時間を計測
  Timer t;
  t.reset();
  app->init();
  cout << t.get() << 's' << endl;

  while (app->isActive()){
    app->event();
    app->update();
    app->draw();
    app->waitSync();
  }

  app->clean();

  delete app;
}

