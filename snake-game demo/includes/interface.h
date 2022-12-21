#ifndef INTERFACE_H
#define INTERFACE_H

#include "snake.h"
#define FRAME_WIDTH          70
#define FRAME_HEIGHT         50
typedef struct {

    uint_32 time  ;
    uint_8  score ;
    uint_8  level ;
    uint_8  highest_score ;

}game_struct;

void SetHeighestScore(game_struct* game , const snake_struct* snake) ;
#endif
