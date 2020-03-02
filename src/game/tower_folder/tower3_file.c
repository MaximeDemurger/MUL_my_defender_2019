/*
** EPITECH PROJECT, 2020
** tower2 file
** File description:
** tower 2
*/

#include "my.h"

int result_case_good3(game_t *game, int line, int col, char **tab)
{
    find_line_col(game->utils, &line, &col);
    game->play->tower3_pos.x =
            my_atoi(game->utils->case_pos[game->utils->line]);
    game->play->tower3_pos.y =
            my_atoi(game->utils->case_pos[game->utils->line + 1]);
    get_pos_case(game->utils, tab);
    game->utils->money -= 50;
    game->utils->click_on_tower3 = 2;
    return 1;
}