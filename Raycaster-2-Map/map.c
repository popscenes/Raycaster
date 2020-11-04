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