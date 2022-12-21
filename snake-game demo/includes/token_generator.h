#include "std_types.h"
#include "interface.h"
typedef struct
{
    sint_8 symbol;
    uint_32 widths[FRAME_WIDTH * FRAME_HEIGHT];
    uint_32  heights[FRAME_WIDTH * FRAME_HEIGHT];
    uint_32  current_index;
}token;

extern token powerUps;
extern token specialPowerUps;
extern token enemies;

uint_32 xorshift32(uint_32 max, uint_32 seed);

void randomizeWidths(uint_32 seed, uint_32 randomWidths[]);

void randomizeHeights(uint_32 seed, uint_32 randomHeights[]);

void powerUpsInit(sint_8 symbol, uint_32 widthSeed, uint_32 heightSeed);

void specialPowerUpsInit(sint_8 symbol, uint_32 widthSeed, uint_32 heightSeed);

void enemiesInit(sint_8 symbol, uint_32 widthSeed, uint_32 heightSeed);
