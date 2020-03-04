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
    sfTexture_destroy(select->map1_text);
    sfSprite_destroy(select->map1);
    sfTexture_destroy(select->map2_text);
    sfSprite_destroy(select->map2);
    sfTexture_destroy(select->map3_text);
    sfSprite_destroy(select->map3);
    sfTexture_destroy(select->map4_text);
    sfSprite_destroy(select->map4);
}