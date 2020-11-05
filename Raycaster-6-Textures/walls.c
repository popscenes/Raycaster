#include "walls.h"



void drawWalls()
{
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
			DrawPixel(x, y, 0xFF888888);
		}

		uint32_t textureOffsetX = 0;
		if (rays[x].wasHitVertical)
		{
			textureOffsetX = (int)rays[x].wallHitY % TILE_SIZE;
		}
		else
		{
			textureOffsetX = (int)rays[x].wallHitX % TILE_SIZE;
		}
		
		for (int y = wallTop; y < wallBottom; y++)
		{
			
			int textureId = rays[x].wallHitContent - 1;
			int textureWidth = wallTextures[textureId].width;
			int textureHeight = wallTextures[textureId].height;

			int distanceFromTop = y + (wallHeight / 2) - (BUFFER_HEIGHT / 2);
			int textureOffsetY = (distanceFromTop) * ((float)textureHeight / wallHeight);
			uint32_t texelColour = wallTextures[textureId].texture_buffer[(textureOffsetY * textureWidth) + textureOffsetX];

			if (rays[x].wasHitVertical)
			{
				//texelColour = (0xFF << 24) & (((texelColour & 0x00FF0000) >> 16) - 10 << 16) & ((texelColour & 0x00FF00) - 10 << 8) & ((texelColour & 0x000000FF) - 10);
				DrawPixel(x, y, texelColour);
			}
			else
			{
				DrawPixel(x, y, texelColour);
			}
		}

		for (int y = wallBottom; y < BUFFER_HEIGHT; y++)
		{
			DrawPixel(x, y, 0xFF555555);
		}
	}
}