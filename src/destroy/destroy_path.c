/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** destroy path
*/

#include "my.h"


void destroy_path(path_t *path)
{
    path_t *tmp;

    while (path) {
        tmp = path;
        free(tmp);
        path = path->next;
    }
}