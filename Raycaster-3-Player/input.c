#include "input.h"

input_t GetInput()
{
	SDL_Event event;
	input_t result = {0};
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		result.exitGame = true;
		break;
	}
	case SDL_KEYDOWN: {
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			result.exitGame = true;
		}
		if (event.key.keysym.sym == SDLK_UP)
		{
			result.walkDirection = 1;
		}
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			result.walkDirection = -1;
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			result.turnDirection = -1;
		}
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			result.turnDirection = 1;
		}
		break;
	}
	case SDL_KEYUP: {
		if (event.key.keysym.sym == SDLK_UP)
		{
			result.walkDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			result.walkDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			result.turnDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			result.turnDirection = 0;
		}
		break;
	}
	default:
		break;
	}

	return result;
}