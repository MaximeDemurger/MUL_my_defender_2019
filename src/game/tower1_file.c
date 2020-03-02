/*
** EPITECH PROJECT, 2020
** tower 1
** File description:
** file
*/

#include "my.h"

int check_mouse_case(int mouse_x, int mouse_y, utils_t *utils)
{
    if (mouse_x < my_atoi(utils->case_pos[utils->line]) - 120 &&
        mouse_x > my_atoi(utils->case_pos[utils->line]) + 120 &&
        mouse_y < my_atoi(utils->case_pos[utils->line + 1]) &&
        mouse_y > my_atoi(utils->case_pos[utils->line + 1]) + 120) {
        if (utils->click_on_tower == 1)
            utils->click_on_tower = 0;
            utils->click_on_tower2 = 0;
        if (utils->click_on_tower2 == 1)
        if (utils->click_on_tower3 == 1)
            utils->click_on_tower3 = 0;
        if (utils->click_on_tower4 == 1)
            utils->click_on_tower4 = 0;
    }
}

int result_case_good1(utils_t *utils, int line, int col, char **tab)
{
    find_line_col(utils, &line, &col);
    utils->tow_pos_x = my_atoi(utils->case_pos[utils->line]);
    utils->tow_pos_y = my_atoi(utils->case_pos[utils->line + 1]);
    get_pos_case(utils, tab);
    utils->money -= 20;
    utils->click_on_tower = 2;
    return 1;
}