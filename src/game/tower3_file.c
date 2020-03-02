/*
** EPITECH PROJECT, 2020
** tower2 file
** File description:
** tower 2
*/

#include "my.h"

int result_case_good3(utils_t *utils, int line, int col, char **tab)
{

    find_line_col(utils, &line, &col);
    utils->tower3.x = my_atoi(utils->case_pos[utils->line]);
    utils->tower3.y = my_atoi(utils->case_pos[utils->line + 1]);
    get_pos_case(utils, tab);
    utils->money -= 50;
    utils->click_on_tower3 = 2;
    return 1;
}