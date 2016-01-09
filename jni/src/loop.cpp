#include "loop.h"

void loop_ok::run()
{
	quit = 0;
	if (!vok.init())
		exit(1);
	mouse_out mot;
	keyboard_out kot;
	game gam(vok,kot,mot);
	while(!quit)
	{
		SDL_GetMouseState(&x,&y);
		while(SDL_PollEvent(&messages))
		{
			switch(messages.type)
			{
				case SDL_KEYDOWN:
				  switch(messages.key.keysym.sym)
				  {
				    case SDLK_ESCAPE:
				      kot.set_key_esc();
				      break;
				    case SDLK_w:
				      kot.set_key_w();
				      break;
				    case SDLK_s:
				      kot.set_key_s();
				      break;
				     case SDLK_a:
				      kot.set_key_a();
				      break;
				    case SDLK_d:
				      kot.set_key_d();
				      break;
				    case SDLK_f:
				      kot.set_key_f();
				      break;
				    case SDLK_v:
				      kot.set_key_v();
				      break;
				     case SDLK_h:
				      kot.set_key_h();
				      break;
				    case SDLK_k:
				      kot.set_key_k();
				      break;
				  }
					break;
				case SDL_KEYUP:
				  switch(messages.key.keysym.sym)
				  {
				    case SDLK_ESCAPE:
				      kot.unset_key_esc();
				      break;
				    case SDLK_w:
				      kot.unset_key_w();
				      break;
				    case SDLK_s:
				      kot.unset_key_s();
				      break;
				     case SDLK_a:
				      kot.unset_key_a();
				      break;
				    case SDLK_d:
				      kot.unset_key_d();
				      break;
				    case SDLK_f:
				      kot.unset_key_f();
				      break;
				    case SDLK_v:
				      kot.unset_key_v();
				      break;
				     case SDLK_h:
				      kot.unset_key_h();
				      break;
				    case SDLK_k:
				      kot.unset_key_k();
				      break;
				  }
					break;
				case SDL_QUIT:
					quit = 1;
					break;
				case SDL_MOUSEBUTTONDOWN:
					mot.click();
					break;
				case SDL_MOUSEBUTTONUP:
					mot.motion();
					break;
				case SDL_MOUSEMOTION:
					mot.set_x(x);
					mot.set_y(y);
					mot.move();
					break;
				default:
					break;
			}
		}
		
//		vok.set_x(203);
//		vok.set_y(204);
//		vok.draw_pixel(203,204,144,144,144);
		
		gam.run();
	}
}