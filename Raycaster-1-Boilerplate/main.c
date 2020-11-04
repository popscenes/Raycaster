#include <stdio.h>
#include <SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include "defs.h";
#include "graphics.h";


bool isGameRunning = false;
int ticksLastFrame;

void setup()
{
}


void update()
{
	// Compute how long we have until the reach the target frame time in milliseconds
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticksLastFrame);

	// Only delay execution if we are running too fast
	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH) {
		SDL_Delay(timeToWait);
	}

	float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	// Store the milliseconds of the current frame to be used in the future
	ticksLastFrame = SDL_GetTicks();
}

void render()
{
	clearColourBuffer(0xFF666666);
	renderColourBuffer();
}

void releaseResources()
{
	destroyWindow();
}

int main(int argc, char* args[])
{
	isGameRunning = initialiseWindow();

	setup();

	while (isGameRunning) {
		update();
		render();
	}
	releaseResources();
	return 0;
}