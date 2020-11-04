#pragma once
#include <stdbool.h>
#include <SDL.h>
#include <SDL_events.h>

typedef struct
{
	int walkDirection;
	int turnDirection;
	bool exitGame;
} input_t;

void GetInput(input_t* input);