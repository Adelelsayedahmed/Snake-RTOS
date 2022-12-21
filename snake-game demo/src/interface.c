#include "std_types.h"
#include "interface.h"

void SetHeighestScore(game_struct* game , const snake_struct* snake) {

    if (snake->snake_length > game->highest_score)
        {
            game->highest_score = snake->snake_length ;
        }
}
