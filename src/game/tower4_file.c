/*
** EPITECH PROJECT, 2020
** tiwer4$$
** File description:
** tower3
*/

#include "my.h"

int result_case_good4(utils_t *utils, int line, int col, char **tab)
{

    find_line_col(utils, &line, &col);
    utils->tower4.x = my_atoi(utils->case_pos[utils->line]);
    utils->tower4.y = my_atoi(utils->case_pos[utils->line + 1]);
    get_pos_case(utils, tab);
    utils->money -= 70;
    utils->click_on_tower4 = 2;
    return 1;
}