/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** destroy all maps
*/

#include "my.h"

void destroy_allmaps(all_map_t *maps)
{
    all_map_t *tmp;

    while (maps) {
        tmp = maps;
        free(maps->filename);
        sfTexture_destroy(maps->texture);
        sfSprite_destroy(maps->sprite);
        free(tmp);
        maps = maps->next;
    }
}