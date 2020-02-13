/*
** EPITECH PROJECT, 2019
** runner
** File description:
** destroy menu
*/

#include "my.h"

void destroy_menu(strtmenu_t *start, pausemenu_t *pause)
{
    sfTexture_destroy(start->background_text);
    sfTexture_destroy(start->play_text);
    sfTexture_destroy(start->quit_text);
    sfSprite_destroy(start->background);
    sfSprite_destroy(start->play);
    sfSprite_destroy(start->quit);
    sfSprite_destroy(pause->background);
    sfSprite_destroy(pause->play);
    sfSprite_destroy(pause->quit);
    sfTexture_destroy(pause->background_text);
    sfTexture_destroy(pause->play_text);
    sfTexture_destroy(pause->quit_text);
}