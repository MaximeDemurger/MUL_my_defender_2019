/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** init start
*/

#include "my.h"

int init_pause(pausemenu_t *pause)
{
    sfVector2f play_pos = {850, 400};
    sfVector2f quit_pos = {850, 600};

    pause->background_text = sfTexture_createFromFile("image/war.jpg", NULL);
    pause->background = sfSprite_create();
    pause->play_text = sfTexture_createFromFile("image/start.png", NULL);
    pause->play = sfSprite_create();
    pause->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    pause->quit = sfSprite_create();
    if (!pause->background_text || !pause->background ||
        !pause->play_text || !pause->play ||
        !pause->quit_text || !pause->quit)
        return 1;
    sfSprite_setTexture(pause->background, pause->background_text, sfTrue);
    sfSprite_setTexture(pause->play, pause->play_text, sfTrue);
    sfSprite_setTexture(pause->quit, pause->quit_text, sfTrue);
    sfSprite_setPosition(pause->play, play_pos);
    sfSprite_setPosition(pause->quit, quit_pos);
    return 0;
}

int init_start(strtmenu_t *start, pausemenu_t *pause)
{
    sfVector2f play_pos = {850, 400};
    sfVector2f quit_pos = {850, 600};

    start->background_text = sfTexture_createFromFile("image/war.jpg", NULL);
    start->background = sfSprite_create();
    start->play_text = sfTexture_createFromFile("image/start.png", NULL);
    start->play = sfSprite_create();
    start->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    start->quit = sfSprite_create();
    if (!start->background_text || !start->background ||
        !start->play_text || !start->play ||
        !start->quit_text || !start->quit)
        return 1;
    sfSprite_setTexture(start->background, start->background_text, sfTrue);
    sfSprite_setTexture(start->play, start->play_text, sfTrue);
    sfSprite_setTexture(start->quit, start->quit_text, sfTrue);
    sfSprite_setPosition(start->play, play_pos);
    sfSprite_setPosition(start->quit, quit_pos);
    return init_pause(pause);
}