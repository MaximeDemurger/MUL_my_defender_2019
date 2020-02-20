/*
** EPITECH PROJECT, 2020
** init
** File description:
** init game
*/

#include "my.h"

int init_play(play_t *play)
{
    play->tower1_text = sfTexture_createFromFile("image/tower1.png", NULL);
    play->tower1 = sfSprite_create();
    play->select_tow_text = sfTexture_createFromFile("image/tower1_select.png", NULL);
    play->select_tow = sfSprite_create();
    play->range_text = sfTexture_createFromFile("image/range.png", NULL);
    play->range = sfSprite_create();
    play->missile_text = sfTexture_createFromFile("image/missile.png", NULL);
    play->missile = sfSprite_create();
    if (!play->tower1 || !play->tower1 || !play->select_tow_text || !play->select_tow
        || !play->range_text || !play->range || !play->missile_text ||
        !play->missile)
        return 1;
    sfSprite_setTexture(play->tower1, play->tower1_text, sfTrue);
    sfSprite_setTexture(play->select_tow, play->select_tow_text, sfTrue);
    sfSprite_setTexture(play->range, play->range_text, sfTrue);
    sfSprite_setTexture(play->missile, play->missile_text, sfTrue);
    return 0;
}