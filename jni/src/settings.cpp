#include "settings.h"

int settings::get_x()
{
  SDL_GetDesktopDisplayMode(0,&dm);
  return get_min();
}

int settings::get_y()
{
  SDL_GetDesktopDisplayMode(0,&dm);
  return get_min();
}

int settings::get_min()
{
  SDL_GetDesktopDisplayMode(0,&dm);
  if (dm.h < dm.w) return dm.h;
    return dm.w;
}