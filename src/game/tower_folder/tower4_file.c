/*
** EPITECH PROJECT, 2020
** tiwer4$$
** File description:
** tower3
*/

#include "my.h"

int result_case_good4(game_t *game, int line, int col, char **tab)
{
    find_line_col(game->utils, &line, &col);
    game->play->tower4_pos.x =
            my_atoi(game->utils->case_pos[game->utils->line]);
    game->play->tower4_pos.y =
            my_atoi(game->utils->case_pos[game->utils->line + 1]);
    get_pos_case(game->utils, tab);
    game->utils->money -= 70;
    game->utils->click_on_tower4 = 2;
    return 1;
}