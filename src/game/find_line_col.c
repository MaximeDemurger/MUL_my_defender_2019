/*
** EPITECH PROJECT, 2020
** find_line_col
** File description:
** find
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