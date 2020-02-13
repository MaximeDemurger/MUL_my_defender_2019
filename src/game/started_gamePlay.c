/*
** EPITECH PROJECT, 2020
** start game
** File description:
** start game play function
*/

#include "my.h"

int checking_map(char const *str);

char **gettingMap_fromFile(char **av)
{
    char **tab = malloc(sizeof(char *) * 6);
    char *str = NULL;
    int i = 0;
    int fd = 0;

    if (av[1] == NULL || tab == NULL)
        return NULL;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return NULL;
    while (getline(&line, &size, fd) > 0) {
        if (checking_map(line) == 1)
            return NULL;
        tab[i] = my_strdup(line);
        i++;
        free(line);
    }
    tab[i] = NULL;
    return tab;
}

int map_parsing(char **av)
{
    char **tab = NULL;

    if ((tab = gettingMap_fromFile(av)) == NULL)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    return (map_parsing(av));
}