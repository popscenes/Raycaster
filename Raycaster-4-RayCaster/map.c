#include "map.h"

void drawMap()
{
	for (int rows = 0; rows  < MAP_ROWS; rows++)
	{
		for (int cols = 0; cols  < MAP_COLS; cols++)
		{
			int tileValue = map[rows][cols];
			int32_t colour = 0x00000000;
			if (tileValue == 1)
			{
				colour = 0xFFFFFFFF;
			}
			int rectX = cols * TILE_SIZE;
			int rectY = rows * TILE_SIZE;
			drawRectangle(rectX, rectY, TILE_SIZE, TILE_SIZE, colour);
		}
	}
}

bool isInWall(float x, float y)
{
	int tileX = (int)floor(x / TILE_SIZE);
	int tileY = (int)floor(y / TILE_SIZE);

	int tileContent = map[tileY][tileX];
	if (tileContent != 0)
	{
		return true;
	}

	return false;
}
int GetTileContent(float x, float y)
{
	int tileX = (int)floor(x / TILE_SIZE);
	int tileY = (int)floor(y / TILE_SIZE);
	return map[tileY][tileX];
}

bool isInMap(float x, float y)
{
	if ((x > 0 && x < (TILE_SIZE * MAP_COLS)) && (y > 0 && y < (TILE_SIZE * MAP_ROWS)))
	{
		return true;
	}

	return false;
}