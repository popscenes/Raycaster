#pragma once
#define PI 3.14159265
#define TWO_PI 6.28318530

#define BUFFER_WIDTH 320
#define BUFFER_HEIGHT 240

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS BUFFER_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000/FPS)

#define MINI_MAP_SCALE 0.1

#define DIST_PROJ_PLANE ((BUFFER_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define NUMTEXTURES 8