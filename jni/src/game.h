#ifndef GAME_H
#define GAME_H

#include "keyboard.h"
#include "mouse.h"
#include "display.h"
#include "settings.h"

class game
{
public:
  game(video_ok&,keyboard_out&,mouse_out&);
  void run();
private:
  video_ok vin;
  keyboard_in kin;
  mouse_in min;
  settings set;

  float i,j,x,y;
  int wall[32*32];
};

#endif
