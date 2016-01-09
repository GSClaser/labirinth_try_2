#ifndef LOOP_H
#define LOOP_H

#include "SDL.h"
#include "display.h"

#include "game.h"

class loop_ok
{
private:
	video_ok vok;
	int quit;
	SDL_Event messages;
	int x,y;
public:
	void run();
};

#endif
