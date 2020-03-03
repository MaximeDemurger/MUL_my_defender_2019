/*
** EPITECH PROJECT, 2020
** tower3
** File description:
** tower2
*/

#include "my.h"

int result_case_good2(game_t *game, int line, int col, char **tab)
{
    find_line_col(game->utils, &line, &col);
    game->play->tower2_pos.x =
            my_atoi(game->utils->case_pos[game->utils->line]);
    game->play->tower2_pos.y =
            my_atoi(game->utils->case_pos[game->utils->line + 1]);
    get_pos_case(game->utils, tab);
    game->utils->money -= 40;
    game->utils->click_on_tower2 = 2;
    return 1;
}