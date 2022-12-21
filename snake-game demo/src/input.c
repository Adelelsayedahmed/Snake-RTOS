 #include "snake.h"
 #include "input.h"

position_state f = 0 ;

 void RanD(snake_struct* snake){

    f=f+1 ;

 Task_TakeInput(f%5, snake);

}
 void    Task_TakeInput(position_state head_new_state , snake_struct* snake){
  position_state head_current_state =  getSnakeHeadState(snake);
  boolean Trans_validity =  isValidTransition(head_new_state , head_current_state);

    if (Trans_validity == TRUE )    // check if the user entered an appropriate transition
        {
            setSnakeHeadState(snake , head_new_state ) ;
        }

    else
        {
            return; // do nothing
        }

}
