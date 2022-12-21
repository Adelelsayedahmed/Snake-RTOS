#include <stdio.h>
#include "std_types.h"
#include "frame.h"
#include "snake.h"
#include "token_generator.h"
#include "interface.h"

snake_struct snake ;
position_state  getSnakeHeadState(const snake_struct* snake){
        return snake->head_current_state;
}
void    setSnakeHeadState( snake_struct* snake , position_state head_state){
        snake->head_current_state = head_state ;
}

void    SetSnakeLifeState(snake_struct* snake ,life_state state ){
    snake->snake_state = state ;
}
boolean IsSnakeAlive(const snake_struct* snake){
    return snake->snake_state ;
}

void    IncrementSnakeLength(snake_struct* snake , uint_8 value){
    snake->snake_length = snake->snake_length + value ;
}

void    UpdateSnake_Pos(snake_struct* snake){


    for (uint_16 i = snake->snake_length-1 ; i > 0 ; i--)
    {
        snake->snake_positions[i]  = snake->snake_positions[i-1];
    }
        snake->snake_positions[0] = snake->head_next_posit ;
}

void    SnakeAutoMove(snake_struct* snake ){

    switch (snake->head_current_state)
            {
                case RIGHT : snake->head_next_posit.x_coordinate++;
                             break ;

                case LEFT : snake->head_next_posit.x_coordinate--;
                             break ;

                case UP : snake->head_next_posit.y_coordinate--;
                             break ;

                case DOWN :  snake->head_next_posit.y_coordinate++;
                             break ;
            }
}

void    SnakeInit(snake_struct* snake , life_state life , uint_16 length , const position_coordinate* coordinates , position_state head_state){

    snake->snake_state = life ;
    snake->snake_length = length ;
    snake->head_next_posit.x_coordinate = coordinates->x_coordinate;
    snake->head_next_posit.y_coordinate = coordinates->y_coordinate;
    snake->head_current_state = RIGHT ;

}

void Task_InitGame(){
    /* Initializing random algorithm functions */
    position_coordinate snake_start_coordinate = {20,25};
    powerUpsInit('o',4,9);
    specialPowerUpsInit('O',8,7);
    enemiesInit('X',18,23);
    SnakeInit(&snake , ALIVE , 1 ,&snake_start_coordinate,RIGHT );
    /*Initializing snake*/

}



int rond(){
    int m = 32 ;
    int a = 5 ;
    int c = 0 ;
    static int x_0 = 1 ;
    x_0 = ((a*x_0)+c)%m ;
    return x_0 ;
}
int main(){

    Task_InitGame();

    for  (;  ;){
        SnakeAutoMove(&snake);
        UpdateSnake_Pos(&snake);
        Task_Draw(&snake);
        RanD(&snake);
    }




}
