#pragma once
#define PI 3.14159265
#define TWO_PI 6.28318530

#define BUFFER_WIDTH 640
#define BUFFER_HEIGHT 480

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS BUFFER_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000/FPS)

#define MINI_MAP_SCALE 0.05

#define DIST_PROJ_PLANE ((BUFFER_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define NUMTEXTURES 8