/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** pause menu
*/

#include "my.h"

void pause_event(utils_t *utils)
{
    if (utils->event.type == sfEvtClosed) {
        utils->pause = false;
        sfRenderWindow_close(utils->window);
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500)
        utils->pause = false;
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 800
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        utils->pause = false;
        sfRenderWindow_close(utils->window);
    }
}

void pause_menu(utils_t *utils, pausemenu_t *pause)
{
    sfText *text = sfText_create();
    sfVector2f pos = {800, 250};

    sfRenderWindow_clear(utils->window, sfBlack);
    sfText_setString(text, "GAME PAUSED");
    sfText_setCharacterSize(text, 75);
    sfText_setFont(text, utils->font);
    sfText_setPosition(text, pos);
    while (utils->pause == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
            pause_event(utils);
        }
        sfRenderWindow_drawSprite(utils->window, pause->background, NULL);
        sfRenderWindow_drawSprite(utils->window, pause->play, NULL);
        sfRenderWindow_drawSprite(utils->window, pause->quit, NULL);
        sfRenderWindow_drawText(utils->window, text, NULL);
        sfRenderWindow_display(utils->window);
    }
}