/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** death menu
*/

#include "my.h"

void death_menu_event(utils_t *utils)
{
    if (utils->event.type == sfEvtClosed) {
        utils->strt_menu = false;
        sfRenderWindow_close(utils->window);
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500) {
        utils->death = false;
        utils->score = 0;
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 800
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        utils->death = false;
        sfRenderWindow_close(utils->window);
        }
}

void death_menu(utils_t *utils, deathmenu_t *death)
{
    sfRenderWindow_clear(utils->window, sfBlack);
    while (utils->death == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)){
            death_menu_event(utils);
        }
        sfRenderWindow_drawSprite(utils->window, death->background, NULL);
        sfRenderWindow_drawSprite(utils->window, death->play, NULL);
        sfRenderWindow_drawSprite(utils->window, death->quit, NULL);
        sfRenderWindow_drawText(utils->window, death->text, NULL);
        sfRenderWindow_display(utils->window);
    }
}