#include "player.h"


 player_t player = {
	.x = 200,
	.y = 200,
	.width = 10,
	.height = 10,
	.walkSpeed = 200,
	.rotationAngle = 0,
	.rotationSpeed = 45 * (PI / 180)
};

void drawPlayer()
{
	drawRectangle(player.x* MINI_MAP_SCALE, player.y* MINI_MAP_SCALE, player.width* MINI_MAP_SCALE, player.height* MINI_MAP_SCALE, 0xFFFF00FF);
	
	float lineStartX = player.x + 5;
	float lineStartY = player.y + 5;
	drawLine(lineStartX* MINI_MAP_SCALE, lineStartY* MINI_MAP_SCALE, (lineStartX + cos(player.rotationAngle) * 40)* MINI_MAP_SCALE, (lineStartY + sin(player.rotationAngle) * 40)* MINI_MAP_SCALE, 0xFFFFFFFF);
}

void movePlayer(input_t input, float deltaTime)
{
	float stepDistance = input.walkDirection * player.walkSpeed * deltaTime;
	float rotationAmount = input.turnDirection * player.rotationSpeed * deltaTime;

	player.rotationAngle += rotationAmount;

	float newX = player.x + cos(player.rotationAngle) * stepDistance;
	float newY = player.y + sin(player.rotationAngle) * stepDistance;
	
	if (isInWall(newX, newY))
	{
		return;
	}

	player.x = newX;
	player.y = newY;
}