#ifndef SETTINGS_H
#define SETTINGS_H

#include "SDL.h"

class settings
{
public:
  int get_x();
  int get_y();
  int get_min();
private:
  int x,y;
  SDL_DisplayMode dm;
};

#endif