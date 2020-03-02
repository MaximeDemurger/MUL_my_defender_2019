/*
** EPITECH PROJECT, 2020
** tower 1
** File description:
** file
*/

#include "my.h"

int result_case_good1(game_t *game, int line, int col, char **tab)
{
    find_line_col(game->utils, &line, &col);
    game->play->tow1_pos_x = my_atoi(game->utils->case_pos[game->utils->line]);
    game->play->tow1_pos_y = my_atoi(game->utils->case_pos[game->utils->line + 1]);
    get_pos_case(game->utils, tab);
    game->utils->money -= 20;
    game->utils->click_on_tower = 2;
    return 1;
}