/*
** EPITECH PROJECT, 2020
** tower3
** File description:
** tower2
*/

#include "my.h"

int result_case_good2(utils_t *utils, int line, int col, char **tab)
{

    find_line_col(utils, &line, &col);
    utils->tower2.x = my_atoi(utils->case_pos[utils->line]);
    utils->tower2.y = my_atoi(utils->case_pos[utils->line + 1]);
    get_pos_case(utils, tab);
    utils->money -= 40;
    utils->click_on_tower2 = 2;
    return 1;
}