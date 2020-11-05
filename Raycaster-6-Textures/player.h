#pragma once
#include "defs.h";
#include "graphics.h"
#include "input.h"
#include "map.h"

typedef struct {
	float x;
	float y;

	int width;
	int height;

	float rotationAngle;
	int walkSpeed;
	float rotationSpeed;

} player_t;

extern player_t player;

void drawPlayer();
void movePlayer(input_t *input, float deltaTime);

