#pragma once

#include <stdint.h>
#include "defs.h"
#include "upng.h"

typedef struct {
    upng_t* upngTexture;
    int width;
    int height;
    uint32_t* texture_buffer;
} texture_t;

extern texture_t wallTextures[NUMTEXTURES];

void loadWallTextures();
void freeWallTextures();
