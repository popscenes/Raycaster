#include "input.h"

void GetInput(input_t *input)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT: {
		input->exitGame = true;
		break;
	}
	case SDL_KEYDOWN: {
		if (event.key.keysym.sym == SDLK_ESCAPE)
		{
			input->exitGame = true;
		}
		if (event.key.keysym.sym == SDLK_UP)
		{
			input->walkDirection = 1;
		}
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			input->walkDirection = -1;
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			input->turnDirection = -1;
		}
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			input->turnDirection = 1;
		}
		break;
	}
	case SDL_KEYUP: {
		if (event.key.keysym.sym == SDLK_UP)
		{
			input->walkDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_DOWN)
		{
			input->walkDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_LEFT)
		{
			input->turnDirection = 0;
		}
		if (event.key.keysym.sym == SDLK_RIGHT)
		{
			input->turnDirection = 0;
		}
		break;
	}
	default:
		break;
	}

	return input;
}