/*
** EPITECH PROJECT, 2020
** start game
** File description:
** start game play function
*/

#include <stddef.h>
#include <fcntl.h>
#include "my.h"

char **gettingMap_fromFile(char **av)
{
    char **line = malloc(sizeof(char *) * 9);
    char *str = NULL;
    int i = 0;
    int fd = 0;

    if (av[1] == NULL)
        return NULL;
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return NULL;
    while ((str = get_next_line(fd))) {
        if (checking_map(str) == 1)
            return NULL;
        line[i] = my_strdup(str);
        i++;
        free(str);
    }
    line[i] = NULL;
    return line;
}

int start_game(utils_t *utils, char **av)
{
    char **tab = NULL;

    if ((tab = gettingMap_fromFile(av)) == NULL)
        return NULL;
    printing_map(tab, utils);
    return 0;
}