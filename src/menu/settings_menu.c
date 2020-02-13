/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** settings_menu
*/

#include "my.h"

void settings_event(utils_t *utils)
{
    if (utils->event.type == sfEvtClosed) {
        utils->settings = false;
        sfRenderWindow_close(utils->window);
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 800
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        utils->settings = false;
        if (utils->from_strt == true)
            utils->strt_menu = true;
        else
            utils->pause = true;
        }
}

void modif_volume(utils_t *utils, settings_t *set)
{
    if (utils->event.type == sfEvtMouseButtonPressed
            && sfMouse_getPositionRenderWindow(utils->window).x >= 1200
            && sfMouse_getPositionRenderWindow(utils->window).x <= 1250
            && sfMouse_getPositionRenderWindow(utils->window).y >= 650
            && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
            //set->volume = sfMusic_getVolume(utils->click);
            (set->volume + 10 < 101) ? set->volume += 10 : 0;
            //sfMusic_setVolume(->click, set->volume);
        }
}

void settings_menu(utils_t *utils, settings_t *set)
{
    sfRenderWindow_clear(utils->window, sfBlack);
    while (utils->settings == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
            settings_event(utils);
        }
        //modif_volume(utils, set);
        sfRenderWindow_drawSprite(utils->window, set->bg, NULL);
        sfRenderWindow_drawSprite(utils->window, set->plus, NULL);
        sfRenderWindow_drawSprite(utils->window, set->minus, NULL);
        sfRenderWindow_drawSprite(utils->window, set->quit, NULL);
        sfRenderWindow_display(utils->window);
    }
}