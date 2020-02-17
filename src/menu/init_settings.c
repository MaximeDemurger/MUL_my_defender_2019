/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init settings
*/

#include "my.h"

void set_settings(settings_t *set)
{
    sfVector2f plus_pos = {1150, 400};
    sfVector2f minus_pos = {775, 400};
    sfVector2f quit_pos = {850, 600};
    sfVector2f scale = {2, 2};

    sfSprite_setTexture(set->bg, set->bg_text, sfTrue);
    sfSprite_setTexture(set->plus, set->plus_text, sfTrue);
    sfSprite_setTexture(set->minus, set->minus_text, sfTrue);
    sfSprite_setTexture(set->quit, set->quit_text, sfTrue);
    sfSprite_setPosition(set->plus, plus_pos);
    sfSprite_setPosition(set->quit, quit_pos);
    sfSprite_setPosition(set->minus, minus_pos);
    sfSprite_setScale(set->plus, scale);
    sfSprite_setScale(set->minus, scale);
}

int init_settings(settings_t *set)
{
    set->bg_text = sfTexture_createFromFile("image/war.jpg", NULL);
    set->bg = sfSprite_create();
    set->plus_text = sfTexture_createFromFile("image/plus.png", NULL);
    set->plus = sfSprite_create();
    set->minus_text = sfTexture_createFromFile("image/moins.png", NULL);
    set->minus = sfSprite_create();
    set->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    set->quit = sfSprite_create();
    if (!set->bg_text || !set->bg || !set->plus_text || !set->plus ||
        !set->minus_text || !set->minus || !set->quit_text || !set->quit)
        return 1;
    set_settings(set);
    return 0;
}