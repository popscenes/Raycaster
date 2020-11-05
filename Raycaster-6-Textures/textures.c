#include "textures.h"
#include <stdio.h>

static const char* textureFileNames[NUMTEXTURES] = {
    "./images/redbrick.png",
    "./images/purplestone.png",
    "./images/mossystone.png",
    "./images/graystone.png",
    "./images/colorstone.png",
    "./images/bluestone.png",
    "./images/eagle.png",
    "./images/wisr.png"
};

texture_t wallTextures[NUMTEXTURES];

void loadWallTextures() {
    for (int i = 0; i < NUMTEXTURES; i++) {
        upng_t* upng;

        upng = upng_new_from_file(textureFileNames[i]);
        if (upng != NULL) {
            upng_decode(upng);
            if (upng_get_error(upng) == UPNG_EOK) {
                wallTextures[i].upngTexture = upng;
                wallTextures[i].width = upng_get_width(upng);
                wallTextures[i].height = upng_get_height(upng);
                wallTextures[i].texture_buffer = (uint32_t*)upng_get_buffer(upng);
            }
        }
    }

}

void freeWallTextures() {
    for (int i = 0; i < NUMTEXTURES; i++) {
        upng_free(wallTextures[i].upngTexture);
    }
}