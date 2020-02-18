/*
** EPITECH PROJECT, 2020
** game map
** File description:
** game map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

void check_charac(char a, utils_t *utils, map_t *map, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(map->grass, pos);
        sfRenderWindow_drawSprite(utils->window, map->grass, NULL);
    }
    if (a == 'X') {
        sfSprite_setPosition(map->soil, pos);
        sfRenderWindow_drawSprite(utils->window, map->soil, NULL);
    }
    if (a == '1') {
        //utils->case_pos[utils->tab][0] = utils->x;
        //utils->case_pos[utils->tab][1] = utils->y;
        sfSprite_setPosition(map->tower_pos, pos);
        sfRenderWindow_drawSprite(utils->window, map->tower_pos, NULL);
        //utils->tab++;
    }
    if (a == 'R') {
        sfSprite_setPosition(map->rock, pos);
        sfRenderWindow_drawSprite(utils->window, map->rock, NULL);
    }
    if (a == 'I') {
        sfSprite_setPosition(map->inventory, pos);
        sfSprite_setPosition(map->rock, pos);
        sfRenderWindow_drawSprite(utils->window, map->rock, NULL);
        sfRenderWindow_drawSprite(utils->window, map->inventory, NULL);
    }
}

void printing_map(char **tab, utils_t *utils)
{
    int col = 0;
    int line = 0;
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};
    
    utils->x = 0;
    utils->y = 0;
    while (tab[line] != NULL) {
        col = 0;
        pos.x = 0;
        utils->x = 0;
        while (tab[line][col] != '\0') {
            check_charac(tab[line][col], utils, utils->map_pars, pos);
            pos.x += 128;
            utils->x += 128;
            col++;
        }
        utils->y += 135;
        pos.y += 135;
        line++;
    }
}