/*
** EPITECH PROJECT, 2020
** pos
** File description:
** pos
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int nbr_case(char **map)
{
    int line = 0;
    int col = 0;
    int i = 0;

    while (map[line]) {
        col = 0;
        while (map[line][col]) {
            if (map[line][col] == '1') {
                i++;
            }
            col++;
        }
        line++;
    }
    return i;
}

int put_in(utils_t *utils, int in_tab, int x, int y)
{
    utils->case_pos[in_tab] = convert_to_string(x);
    in_tab++;
    utils->case_pos[in_tab] = convert_to_string(y);
    in_tab++;
    return in_tab;
}

void get_pos_case(utils_t *utils, char **map)
{
    int line = 0;
    int col = 0;
    int in_tab = 0;
    int x = 0;
    int y = 0;
    
    utils->case_pos = malloc(sizeof(char *) * (nbr_case(map) * 2) + 1);
    while (map[line]) {
        col = 0;
        x = 0;
        while (map[line][col]) {
            if (map[line][col] == '1')
                in_tab = put_in(utils, in_tab, x, y);
            col++;
            x += 128;
        }
        y += 135;
        line++;
    }
    utils->case_pos[in_tab] = NULL;
}