#include "walls.h"


void drawWalls()
{
	uint32_t* buffer = GetColourBuffer();
	for (int x = 0; x < NUM_RAYS; x++)
	{
		//float distToWall = rays[x].distance;
		float distToWall = rays[x].distance * cos(rays[x].rayAngle - player.rotationAngle);
		
		float wallHeight = (TILE_SIZE / distToWall) * DIST_PROJ_PLANE;

		int midPoint = BUFFER_HEIGHT / 2;
		int wallTop = midPoint - ((int)wallHeight / 2);
		wallTop = wallTop < 0 ? 0 : wallTop;

		int wallBottom = midPoint + (wallHeight / 2);
		wallBottom = wallBottom > BUFFER_HEIGHT ? BUFFER_HEIGHT : wallBottom;

		for (int y = 0; y < wallTop; y++)
		{
			buffer[(y * BUFFER_WIDTH) + x] = 0xFF888888;
		}
		
		for (int y = wallTop; y < wallBottom; y++)
		{
			if (rays[x].wasHitVertical)
			{
				buffer[(y * BUFFER_WIDTH) + x] = 0xFFFFFFFF;
			}
			else
			{
				buffer[(y * BUFFER_WIDTH) + x] = 0xFFDDDDDD;
			}
		}

		for (int y = (wallBottom); y < BUFFER_HEIGHT; y++)
		{
			buffer[(y * BUFFER_WIDTH) + x] = 0xFF555555;
		}
	}
}