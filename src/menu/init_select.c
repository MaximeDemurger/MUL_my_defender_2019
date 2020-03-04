/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init map selection
*/

#include "my.h"

void set_select(selection_t *select)
{

    sfVector2f pos_map1 = {850, 200};
    sfVector2f pos_map2 = {850, 400};
    sfVector2f pos_map3 = {850, 600};
    sfVector2f pos_map4 = {850, 800};

    sfSprite_setTexture(select->back, select->back_text, sfTrue);
    sfSprite_setTexture(select->map1, select->map1_text, sfTrue);
    sfSprite_setTexture(select->map2, select->map2_text, sfTrue);
    sfSprite_setTexture(select->map3, select->map3_text, sfTrue);
    sfSprite_setTexture(select->map4, select->map4_text, sfTrue);
    sfSprite_setPosition(select->map1, pos_map1);
    sfSprite_setPosition(select->map2, pos_map2);
    sfSprite_setPosition(select->map3, pos_map3);
    sfSprite_setPosition(select->map4, pos_map4);
}

int init_select(selection_t *select)
{
    select->font = sfFont_createFromFile("image/police.otf");
    select->back_text = sfTexture_createFromFile("image/war.jpg", NULL);
    select->back = sfSprite_create();
    select->map1_text = sfTexture_createFromFile("image/map1.png", NULL);
    select->map2_text = sfTexture_createFromFile("image/map2.png", NULL);
    select->map3_text = sfTexture_createFromFile("image/map3.png", NULL);
    select->map4_text = sfTexture_createFromFile("image/map4.png", NULL);
    select->map1 = sfSprite_create();
    select->map2 = sfSprite_create();
    select->map3 = sfSprite_create();
    select->map4 = sfSprite_create();
    if (!select->font || !select->back_text || !select->back ||
        !select->map1 || !select->map2 || !select->map3 ||
        !select->map4 || !select->map1_text || !select->map2_text
        || !select->map3_text || !select->map4_text)
        return 1;
    set_select(select);
    return 0;
}