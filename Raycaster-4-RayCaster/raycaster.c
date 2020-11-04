#include "raycaster.h"
#include "player.h"
#include "map.h"

ray_t rays[NUM_RAYS];

void castAllRays()
{
	float angleStep = FOV_ANGLE / NUM_RAYS;
	float currentAngle = player.rotationAngle - (FOV_ANGLE / 2);

	//castRay(0, player.rotationAngle);

	for (int i = 0; i < NUM_RAYS; i++)
	{
		castRay(i, currentAngle);
		currentAngle += angleStep;
	}
}

void drawRays()
{
	for (int i = 0; i < NUM_RAYS; i++)
	{
		drawLine(player.x, player.y, rays[i].wallHitX, rays[i].wallHitY, 0xFFFF0000);
	}
}

void castRay(int column, float angle)
{
	angle = normaliseAngle(angle);
	bool isRayFacingDown = angle > 0 && angle < PI;
	bool isRayFacingRight = angle < PI * 0.5 || angle > 1.5 * PI;

	
	wallHit_t vertWallHit = { 0 };
	getWallHitVertical(&vertWallHit, angle, isRayFacingDown, isRayFacingRight);
	wallHit_t horzWallHit = { 0 };
	getWallHitHorizontal(&horzWallHit, angle, isRayFacingDown, isRayFacingRight);

	
	wallHit_t* wallHit = &vertWallHit;
	if (horzWallHit.distance < vertWallHit.distance)
	{
		wallHit = &horzWallHit;
	}

	rays[column].wallHitX = wallHit->wallHitx;
	rays[column].wallHitY = wallHit->wallHitY;
	rays[column].distance = wallHit->distance;
	rays[column].wasHitVertical = true;
	rays[column].wallHitContent = wallHit->tileContent;
	rays[column].rayAngle = angle;
	
}

float normaliseAngle(float angle) {
	angle = remainder(angle, TWO_PI);
	if (angle < 0) {
		angle = TWO_PI + angle;
	}
	return angle;
}
void getWallHitHorizontal(wallHit_t* wallHit, float angle, bool isRayFacingDown, bool isRayFacingRight)
{
	float xintercept, yintercept;
	float xstep, ystep;

	wallHit->foundWallHit = false;
	wallHit->distance = FLT_MAX;

	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += isRayFacingDown ? TILE_SIZE : 0;

	xintercept = player.x + (yintercept - player.y) / tan(angle);

	ystep = TILE_SIZE;
	ystep *= isRayFacingDown ? 1 : -1;

	xstep = TILE_SIZE / tan(angle);
	xstep *= (!isRayFacingRight && xstep > 0) ? -1 : 1;
	xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;

	float xGridHit = xintercept;
	float yGridHit = yintercept;

	while (isInMap(xGridHit, yGridHit))
	{
		float wallTestX = xGridHit;
		float wallTestY = yGridHit;

		wallTestY += isRayFacingDown ? 0 : -1;
		if (isInWall(wallTestX, wallTestY))
		{
			wallHit->foundWallHit = true;
			wallHit->wallHitx = xGridHit;
			wallHit->wallHitY = yGridHit;
			wallHit->tileContent = GetTileContent(wallTestX, wallTestY);
			wallHit->distance = distBetweenPoints(player.x, player.y, xGridHit, yGridHit);
			break;
		}

		xGridHit += xstep;
		yGridHit += ystep;
	}
}

void getWallHitVertical(wallHit_t* wallHit, float angle, bool isRayFacingDown, bool isRayFacingRight)
{
	float xintercept, yintercept;
	float xstep, ystep;

	wallHit->foundWallHit = false;
	wallHit->distance = FLT_MAX;


	xintercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	xintercept += isRayFacingRight ? TILE_SIZE : 0;

	yintercept = player.y + (xintercept - player.x) * tan(angle);

	xstep = TILE_SIZE;
	xstep *= isRayFacingRight ? 1 : -1;

	ystep = tan(angle) * TILE_SIZE;
	ystep *= (!isRayFacingDown && ystep > 0) ? -1 : 1;
	ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

	float xGridHit = xintercept;
	float yGridHit = yintercept;

	while (isInMap(xGridHit, yGridHit))
	{
		float wallTestX = xGridHit;
		float wallTestY = yGridHit;

		wallTestX += isRayFacingRight ? 0 : -1;
		if (isInWall(wallTestX, wallTestY))
		{
			wallHit->foundWallHit = true;
			wallHit->wallHitx = xGridHit;
			wallHit->wallHitY = yGridHit;
			wallHit->tileContent = GetTileContent((int)wallTestX, (int)wallTestY);
			wallHit->distance = distBetweenPoints(player.x, player.y, xGridHit, yGridHit);
			break;
		}

		xGridHit += xstep;
		yGridHit += ystep;
	}
}

float distBetweenPoints(float startx, float starty, float endx, float endy)
{
	float lengthX = endx - startx;
	float lengthY = endy - starty;

	float distance = sqrt((lengthX * lengthX) + (lengthY * lengthY));

	return distance;
}

