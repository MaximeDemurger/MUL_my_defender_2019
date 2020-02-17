/*
** EPITECH PROJECT, 2020
** start game
** File description:
** start game play function
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

char **gettingMap_fromFile(char **av)
{
    char **line = malloc(sizeof(char *) * 6);
    char *str = NULL;
    int i = 0;
    int fd = 0;

    if (av[1] == NULL)
        return NULL;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return NULL;
    while ((str = get_next_line(fd))) {
        line[i] = my_strdup(str);
        i++;
        free(str);
    }
    line[i] = NULL;
    return line;
}

void check_charac(char a, utils_t *utils, map_t *map, sfVector2f pos)
{
    if (a == 'O') {
        sfSprite_setPosition(map->grass, pos);
        sfRenderWindow_drawSprite(utils->window, map->grass, NULL);
    } else if (a == 'X') {
        sfSprite_setPosition(map->soil, pos);
        sfRenderWindow_drawSprite(utils->window, map->soil, NULL);
    }
}

void printing_map(char **tab, utils_t *utils)
{
    int col = 0;
    int line = 0;
    int x = 0;
    int y = 0;
    sfVector2f pos = {x, y};
    int column = 0;
    map_t *map = malloc(sizeof(map_t));

    init_map(map);
    sfRenderWindow_drawSprite(utils->window, map->soil, NULL);
    while (tab[line] != NULL) {
        column = 0;
        while (tab[line][col] != '\0') {
            check_charac(tab[line][col], utils, map, pos);
            pos.x += 192;
            col++;
        }
        pos.y = 216;
        line++;
    }
}

int map_parsing(utils_t *utils, char **av)
{
    char **tab = NULL;

    if ((tab = gettingMap_fromFile(av)) == NULL)
        return 84;
    printing_map(tab, utils);
    return 0;
}