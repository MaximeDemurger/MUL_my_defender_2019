/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** destroy death
*/

#include "my.h"

void destroy_death(deathmenu_t *death)
{
    sfText_destroy(death->text);
    sfFont_destroy(death->font);
    sfTexture_destroy(death->background_text);
    sfSprite_destroy(death->background);
    sfTexture_destroy(death->play_text);
    sfSprite_destroy(death->play);
    sfTexture_destroy(death->quit_text);
    sfSprite_destroy(death->quit);
}