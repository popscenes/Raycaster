#pragma once
#include <stdbool.h>
#include "defs.h"
#include <float.h>

typedef struct 
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool wasHitVertical;
	int wallHitContent;
} ray_t;

typedef struct
{
	float wallHitx;
	float wallHitY;
	bool  foundWallHit;
	int tileContent;
	float distance;
} wallHit_t;

extern ray_t rays[BUFFER_WIDTH];

void castAllRays();
void drawRays();
void castRay(int column, float angle);
void getWallHitVertical(wallHit_t* wallHit, float angle, bool isRayFacingDown, bool isRayFacingRight);
void getWallHitHorizontal(wallHit_t* wallHit, float angle, bool isRayFacingDown, bool isRayFacingRight);
float normaliseAngle(float angle);
float distBetweenPoints(float startx, float starty, float endx, float endy);