/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** destroy selection
*/

#include "my.h"

void destroy_select(selection_t *select)
{
    sfTexture_destroy(select->back_text);
    sfSprite_destroy(select->back);
    sfText_destroy(select->map1);
    sfText_destroy(select->map2);
    sfText_destroy(select->map3);
    sfText_destroy(select->map4);
}