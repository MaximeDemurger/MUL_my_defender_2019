/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** get path
*/

#include "my.h"

path_t *my_rev_list(path_t *begin)
{
    path_t *tmp = 0;
    path_t *elem = begin;
    path_t *next;

    while (elem->next) {
        next = elem->next;
        elem->next = tmp;
        tmp = elem;
        elem = next;
    }
    elem->next = tmp;
    return elem;
}

path_t *add_elem(path_t *elem, int x, int y)
{
    path_t *tmp = malloc(sizeof(path_t));

    if (!tmp)
        return NULL;
    tmp->pos.x = (float)x;
    tmp->pos.y = (float)y;
    tmp->next = elem;
    return tmp;
}

path_t *get_path(char **map)
{
    path_t *tmp = NULL;
    int line = 0;
    int col = 0;
    int x = 0;
    int y = 0;

    while (map[line]) {
        col = 0;
        x = 0;
        while (map[line][col]) {
            if (map[line][col] == 'X')
                tmp = add_elem(tmp, x, y);
            col++;
            x += 128;
        }
        y += 135;
        line++;
    }
    return my_rev_list(tmp);
}