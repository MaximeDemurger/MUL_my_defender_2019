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
    play->bookclose_text = sfTexture_createFromFile("image/bookclose.png", NULL);
    play->bookclose = sfSprite_create();
    play->bookopen_text = sfTexture_createFromFile("image/bookopen.png", NULL);
    play->bookopen = sfSprite_create();
    play->menubook_text = sfTexture_createFromFile("image/menu_book.png", NULL);
    play->menubook = sfSprite_create();
    if (!play->tower1 || !play->tower1 || !play->select_tow_text || !play->select_tow
        || !play->range_text || !play->range || !play->missile_text ||
        !play->missile || !play->bookclose_text || !play->bookclose
        || !play->bookopen_text || !play->bookopen ||
        !play->menubook || !play->menubook_text)
        return 1;
    sfSprite_setTexture(play->tower1, play->tower1_text, sfTrue);
    sfSprite_setTexture(play->select_tow, play->select_tow_text, sfTrue);
    sfSprite_setTexture(play->range, play->range_text, sfTrue);
    sfSprite_setTexture(play->missile, play->missile_text, sfTrue);
    sfSprite_setTexture(play->bookclose, play->bookclose_text, sfTrue);
    sfSprite_setTexture(play->bookopen, play->bookopen_text, sfTrue);
    sfSprite_setTexture(play->menubook, play->menubook_text, sfTrue);
    return 0;
}