/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** init start
*/

#include "my.h"

void set_pause(pausemenu_t *pause)
{
    sfVector2f play_pos = {850, 400};
    sfVector2f set_pos = {850, 600};
    sfVector2f quit_pos = {850, 800};

    sfSprite_setTexture(pause->background, pause->background_text, sfTrue);
    sfSprite_setTexture(pause->play, pause->play_text, sfTrue);
    sfSprite_setTexture(pause->quit, pause->quit_text, sfTrue);
    sfSprite_setTexture(pause->settings, pause->set_text, sfTrue);
    sfSprite_setPosition(pause->play, play_pos);
    sfSprite_setPosition(pause->quit, quit_pos);
    sfSprite_setPosition(pause->settings, set_pos);
}

int init_pause(pausemenu_t *pause)
{

    pause->background_text = sfTexture_createFromFile("image/war.jpg", NULL);
    pause->background = sfSprite_create();
    pause->play_text = sfTexture_createFromFile("image/start.png", NULL);
    pause->play = sfSprite_create();
    pause->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    pause->quit = sfSprite_create();
    pause->set_text = sfTexture_createFromFile("image/settings.png", NULL);
    pause->settings = sfSprite_create();
    if (!pause->background_text || !pause->background || !pause->settings ||
        !pause->play_text || !pause->play || !pause->set_text ||
        !pause->quit_text || !pause->quit)
        return 1;
    set_pause(pause);
    return 0;
}

void set_start(strtmenu_t *start)
{
    sfVector2f play_pos = {850, 400};
    sfVector2f set_pos = {850, 600};
    sfVector2f quit_pos = {850, 800};

    sfSprite_setTexture(start->background, start->background_text, sfTrue);
    sfSprite_setTexture(start->play, start->play_text, sfTrue);
    sfSprite_setTexture(start->quit, start->quit_text, sfTrue);
    sfSprite_setTexture(start->settings, start->set_text, sfTrue);
    sfSprite_setPosition(start->play, play_pos);
    sfSprite_setPosition(start->quit, quit_pos);
    sfSprite_setPosition(start->settings, set_pos);
}

int init_start(strtmenu_t *start, pausemenu_t *pause)
{
    start->background_text = sfTexture_createFromFile("image/war.jpg", NULL);
    start->background = sfSprite_create();
    start->play_text = sfTexture_createFromFile("image/start.png", NULL);
    start->play = sfSprite_create();
    start->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    start->quit = sfSprite_create();
    start->set_text = sfTexture_createFromFile("image/settings.png", NULL);
    start->settings = sfSprite_create();
    if (!start->background_text || !start->background ||
        !start->play_text || !start->play || !start->set_text ||
        !start->quit_text || !start->quit || !start->settings)
        return 1;
    set_start(start);
    return init_pause(pause);
}