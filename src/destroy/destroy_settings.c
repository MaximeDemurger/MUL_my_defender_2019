/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** destroy settings
*/

#include "my.h"

void destroy_settings(settings_t *set)
{
    sfTexture_destroy(set->bg_text);
    sfTexture_destroy(set->plus_text);
    sfTexture_destroy(set->minus_text);
    sfTexture_destroy(set->quit_text);
    sfSprite_destroy(set->bg);
    sfSprite_destroy(set->minus);
    sfSprite_destroy(set->plus);
    sfSprite_destroy(set->quit);
}