#include "token_generator.h"

// tokens struct
token powerUps, specialPowerUps, enemies;

// pseudo random number generator
static unsigned int state = -1;
unsigned int xorshift32(uint_32 max, uint_32 seed)
{
    if (state == -1)
        state = seed;
    unsigned int x = state;
    x ^= x << 17;
    x ^= x >> 7;
    x ^= x << 5;
    state = x;
    return (x % max);
}

// randomizing widths
void randomizeWidths(unsigned int seed, unsigned int randomWidths[])
{
    for (int i = 0; i < FRAME_WIDTH * FRAME_HEIGHT; i++)
    {
        randomWidths[i] = xorshift32(FRAME_WIDTH, seed);
    }
    state = -1;
}

// randomizing heights
void randomizeHeights(unsigned int seed, unsigned int randomHeights[])
{
    for (int i = 0; i < FRAME_HEIGHT * FRAME_WIDTH; i++)
    {
        randomHeights[i] = xorshift32(FRAME_HEIGHT, seed);
    }
    state = -1;
}

// initializing powerups
void powerUpsInit(sint_8 symbol, uint_32  widthSeed, uint_32 heightSeed)
{
    powerUps.symbol = symbol;
    randomizeWidths(widthSeed, powerUps.widths);
    randomizeHeights(heightSeed, powerUps.heights);
    powerUps.current_index = 0;
}

// initializing special powerups
void specialPowerUpsInit(sint_8 symbol, uint_32 widthSeed, uint_32 heightSeed)
{
    specialPowerUps.symbol = symbol;
    randomizeWidths(widthSeed, specialPowerUps.widths);
    randomizeHeights(heightSeed, specialPowerUps.heights);
    specialPowerUps.current_index = 0;
}

// initializing enemies
void enemiesInit(sint_8 symbol, uint_32 widthSeed, uint_32 heightSeed)
{
    enemies.symbol = symbol;
    randomizeWidths(widthSeed, enemies.widths);
    randomizeHeights(heightSeed, enemies.heights);
    enemies.current_index = 0;
}
