/*
** EPITECH PROJECT, 2020
** init
** File description:
** init game
*/

#include "my.h"

int texture_tower(play_t *play)
{
    sfSprite_setTexture(play->tower1, play->tower1_text, sfTrue);
    sfSprite_setTexture(play->select_tow, play->select_tow_text, sfTrue);
    sfSprite_setTexture(play->tower2, play->tower2_text, sfTrue);
    sfSprite_setTexture(play->select2_tow, play->select2_tow_text, sfTrue);
    sfSprite_setTexture(play->tower3, play->tower3_text, sfTrue);
    sfSprite_setTexture(play->select3_tow, play->select3_tow_text, sfTrue);
    sfSprite_setTexture(play->tower4, play->tower4_text, sfTrue);
    sfSprite_setTexture(play->select4_tow, play->select4_tow_text, sfTrue);
    sfSprite_setTexture(play->range, play->range_text, sfTrue);
    sfSprite_setTexture(play->missile, play->missile_text, sfTrue);
    sfSprite_setTexture(play->bookclose, play->bookclose_text, sfTrue);
    sfSprite_setTexture(play->bookopen, play->bookopen_text, sfTrue);
    sfSprite_setTexture(play->menubook, play->menubook_text, sfTrue);
}

int check_struct_tower(play_t *play)
{
    if (!play->tower1 || !play->tower1 || !play->select_tow_text ||
        !play->select_tow || !play->tower2 || !play->tower2 ||
        !play->select2_tow_text || !play->select2_tow ||
        !play->tower3 || !play->tower3 || !play->select3_tow_text ||
        !play->select3_tow || !play->tower4 || !play->tower4 ||
        !play->select4_tow_text || !play->select4_tow)
        return 84;
    if (!play->range_text || !play->range || !play->missile_text
        || !play->missile || !play->bookclose_text || !play->bookclose
        || !play->bookopen_text || !play->bookopen || !play->menubook ||
        !play->menubook_text)
        return 1;
    return 0;
}

int init_tower(play_t *play)
{
    play->tower1_text = sfTexture_createFromFile("image/tower1.png", NULL);
    play->tower1 = sfSprite_create();
    play->select_tow_text = sfTexture_createFromFile("image/tower1_select.png", NULL);
    play->select_tow = sfSprite_create();
    play->tower2_text = sfTexture_createFromFile("image/tower2.png", NULL);
    play->tower2 = sfSprite_create();
    play->select2_tow_text = sfTexture_createFromFile("image/tower2_select.png", NULL);
    play->select2_tow = sfSprite_create();
    play->tower3_text = sfTexture_createFromFile("image/tower3.png", NULL);
    play->tower3 = sfSprite_create();
    play->select3_tow_text = sfTexture_createFromFile("image/tower3_select.png", NULL);
    play->select3_tow = sfSprite_create();
    play->tower4_text = sfTexture_createFromFile("image/tower4.png", NULL);
    play->tower4 = sfSprite_create();
    play->select4_tow_text = sfTexture_createFromFile("image/tower4_select.png", NULL);
    play->select4_tow = sfSprite_create();
    if (check_struct_tower(play) > 0)
        return 1;
    return 0;
}

int init_play(play_t *play)
{
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
    if (init_tower(play) == 1)
        return 84;
    texture_tower(play);
    return 0;
}