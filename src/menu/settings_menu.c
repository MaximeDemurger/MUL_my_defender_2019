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
        && sfMouse_getPositionRenderWindow(utils->window).x >= 1150
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1200
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 450) {
        set->volume = sfMusic_getVolume(utils->song);
        (set->volume + 10 < 101) ? set->volume += 10 : 0;
        sfMusic_setVolume(utils->song, set->volume);
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 775
        && sfMouse_getPositionRenderWindow(utils->window).x <= 825
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 450) {
        set->volume = sfMusic_getVolume(utils->song);
        (set->volume - 10 > 0) ? set->volume -= 10 : 0;
        sfMusic_setVolume(utils->song, set->volume);
    }
}

void settings_menu(utils_t *utils, settings_t *set)
{
    sfText *vol = sfText_create();
    sfVector2f txt_pos = {915, 350};

    sfRenderWindow_clear(utils->window, sfBlack);
    set->volume = sfMusic_getVolume(utils->song);
    sfText_setPosition(vol, txt_pos);
    sfText_setFont(vol, utils->font);
    sfText_setCharacterSize(vol, 100);
    while (utils->settings == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
            settings_event(utils);
        }
        modif_volume(utils, set);
        sfText_setString(vol, convert_to_string(set->volume));
        sfRenderWindow_drawSprite(utils->window, set->bg, NULL);
        sfRenderWindow_drawSprite(utils->window, set->plus, NULL);
        sfRenderWindow_drawSprite(utils->window, set->minus, NULL);
        sfRenderWindow_drawSprite(utils->window, set->quit, NULL);
        sfRenderWindow_drawText(utils->window, vol, NULL);
        sfRenderWindow_display(utils->window);
    }
}