#include "std_types.h"
#include "frame.h"
#include "interface.h"
#include "snake.h"
#include "token_generator.h"
#include "input.h"
#include <stdio.h>


float x = 0 ;



 boolean isSnakeHitBorder  (const snake_struct* snake){
 boolean result = FALSE ;
    if ( snake->snake_positions[0].x_coordinate == FRAME_WIDTH  ||
         snake->snake_positions[0].y_coordinate == FRAME_HEIGHT ||
         snake->snake_positions[0].x_coordinate == 0            ||
         snake->snake_positions[0].y_coordinate == 0
       )
        {
            result = TRUE ;
        }
    return result ;
}
 boolean isSnakeHitEnemy   (const snake_struct* snake){
    boolean result = FALSE ;
    if ( snake->snake_positions[0].x_coordinate == enemies.widths[enemies.current_index] && snake->snake_positions[0].y_coordinate == enemies.heights[enemies.current_index] )
        {
            result = TRUE ;
        }
    return result ;
}
 boolean isSnakeEatHimSelf (const snake_struct* snake){

    boolean result = FALSE ;

    for (uint_16 i = 1 ; i < snake->snake_length -1 ; i++ )
        {
            if ( snake->snake_positions[0].x_coordinate == snake->snake_positions[i].x_coordinate && snake->snake_positions[0].y_coordinate == snake->snake_positions[i].y_coordinate )
            {
                result = TRUE ;
            }
        }
    return result ;
}


 boolean isSnakeHere ( snake_struct* snake , uint_8 x , uint_8 y){
boolean result = 0 ;

    for (int i = 0 ; i < snake->snake_length ; i++)
    {
        if (snake->snake_positions[i].x_coordinate == x && snake->snake_positions[i].y_coordinate == y)
            {
                result = 1 ;
                break ;
            }
    }
    return result ;
}

void ToScreen(const snake_struct* snake ){
    uint_8 width  = 0 ;
    uint_8 height = 0 ;
     printf(" ");
    for ( width = 0 ; width < FRAME_WIDTH ; width++)
    {
        printf("-");
    }
    printf("\n");

   for (height  = 0 ; height < FRAME_HEIGHT ; height++){

    printf("|");

    for( width = 0 ; width < FRAME_WIDTH;width++)
    {
          if (isSnakeHere(snake,width,height) == TRUE)
          {
              if (snake->snake_positions[0].x_coordinate == width &&snake->snake_positions[0].y_coordinate == height )
                printf("W");
              else
                printf("*");
          }
          else if (enemies.widths[enemies.current_index]== width &&enemies.heights[enemies.current_index] ==height )
          {
            printf("%c",enemies.symbol);
          }
          else if (powerUps.widths[powerUps.current_index] == width && powerUps.heights[powerUps.current_index] == height)
          {
              printf("%c",powerUps.symbol);
          }
          else if (specialPowerUps.widths[specialPowerUps.current_index] == width && specialPowerUps.heights[specialPowerUps.current_index] == height)
          {
              printf("%c",specialPowerUps.symbol);
          }
          else
          {
             printf(" ");
          }

    }
    printf("|");
    printf("\n");
   }
    printf(" ");
    for ( width = 0 ; width < FRAME_WIDTH ; width++)
    {
        printf("-");
    }

}


 void CheckSnakeState(snake_struct* snake){
position_coordinate head = snake->snake_positions[0] ;

    if (    isSnakeHitBorder(snake)  == TRUE ||
            isSnakeEatHimSelf(snake) == TRUE ||
            isSnakeHitEnemy(snake)   == TRUE
        )
        {
            SetSnakeLifeState(snake, DEAD) ;
        }

    if (IsSnakeAlive(snake) == FALSE)
        {
         system("cls");
         printf("Game OVER !!!");
         exit(0);
        }

    if ( head.x_coordinate == powerUps.widths[powerUps.current_index] ||
         head.y_coordinate == powerUps.heights[powerUps.current_index] )
      {
            IncrementSnakeLength(snake , 1);
            powerUps.current_index++;
      }

       if (head.x_coordinate == specialPowerUps.widths[specialPowerUps.current_index] ||
           head.y_coordinate == specialPowerUps.heights[specialPowerUps.current_index] )
      {
            IncrementSnakeLength(snake , 3 ) ;
            specialPowerUps.current_index++;
      }

}




void Task_Draw( snake_struct* snake){

    CheckSnakeState(snake);
    ToScreen(snake);
         system("cls");



}


 boolean isValidTransition (position_state head_new_state , position_state head_current_state ){

    if (head_new_state + head_current_state == LEFT+RIGHT || head_new_state + head_current_state == UP +DOWN)
        {
            return FALSE ;
        }
    else return TRUE ;

}






