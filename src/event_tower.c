/*
** EPITECH PROJECT, 2020
** tower_event
** File description:
** event
*/

#include "my.h"

void find_line_col(utils_t *utils, int *line, int *col)
{
    int x = 0;
    int y = 0;

    while (y < my_atoi(utils->case_pos[utils->line + 1])) {
        y += 135;
        *line += 1;
    }
    while (x < my_atoi(utils->case_pos[utils->line])) {
        x += 128;
        *col += 1;
    }
}

int check_selected_tower(utils_t *utils, char **tab, int line, int col)
{
    if (utils->click_on_tower == 1)
        result_case_good1(utils, line, col, tab);
    if (utils->click_on_tower2 == 1)
        result_case_good2(utils, line, col, tab);
    if (utils->click_on_tower3 == 1)
        result_case_good3(utils, line , col, tab);
    if (utils->click_on_tower4 == 1)
        result_case_good4(utils, line , col, tab);
}

int check_pos(utils_t *utils, int mouse_x, int mouse_y, char **tab)
{
    utils->line = 0;
    int line = 0;
    int col = 0;

    while (utils->case_pos[utils->line]) {
        if (mouse_x > my_atoi(utils->case_pos[utils->line]) - 120 &&
            mouse_x < my_atoi(utils->case_pos[utils->line]) + 120 &&
            mouse_y > my_atoi(utils->case_pos[utils->line + 1]) &&
            mouse_y < my_atoi(utils->case_pos[utils->line + 1]) + 120)
            check_selected_tower(utils, tab, line, col);
        check_mouse_case(mouse_x, mouse_y, utils);
        utils->line += 2;
    }
    return 0;
}