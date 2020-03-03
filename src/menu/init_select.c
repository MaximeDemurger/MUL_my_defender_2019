/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init map selection
*/

#include "my.h"

void set_select(selection_t *select)
{
    sfText_setFont(select->map1, select->font);
    sfText_setFont(select->map2, select->font);
    sfText_setFont(select->map3, select->font);
    sfText_setFont(select->map4, select->font);
    sfText_setCharacterSize(select->map1, 50);
    sfText_setCharacterSize(select->map2, 50);
    sfText_setCharacterSize(select->map3, 50);
    sfText_setCharacterSize(select->map4, 50);
    sfSprite_setTexture(select->back, select->back_text, sfTrue);
}

int init_select(selection_t *select)
{
    select->font = sfFont_createFromFile("image/police.otf");
    select->back_text = sfTexture_createFromFile("image/war.jpg", NULL);
    select->back = sfSprite_create();
    select->map1 = sfText_create();
    select->map2 = sfText_create();
    select->map3 = sfText_create();
    select->map4 = sfText_create();
    if (!select->font || !select->back_text || !select->back ||
        !select->map1 || !select->map2 || !select->map3 ||
        !select->map4)
        return 1;
    set_select(select);
    return 0;
}