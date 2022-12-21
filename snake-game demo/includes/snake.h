#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH     70*50
#include "std_types.h"

typedef enum {
    LEFT = 1,
    RIGHT   ,
    UP      ,
    DOWN

}position_state;

typedef enum {
    DEAD ,
    ALIVE
}life_state ;

typedef struct {
    uint_8 x_coordinate  ;
    uint_8 y_coordinate ;
}position_coordinate;


typedef struct
 {
    position_coordinate snake_positions [MAX_SNAKE_LENGTH] ;
    uint_16 snake_length ;
    uint_8  snake_speed  ;
    life_state snake_state  ;
    position_coordinate head_next_posit ;
    position_state head_current_state ;

}snake_struct;

position_state  getSnakeHeadState(const snake_struct* snake);
void    setSnakeHeadState( snake_struct* snake , position_state head_state);
void    SetSnakeLifeState(snake_struct* snake ,life_state state );
void    IncrementSnakeLength(snake_struct* snake , uint_8 value);
void    UpdateSnake_Pos(snake_struct* snake );
boolean IsSnakeAlive(const snake_struct* snake);



#endif
