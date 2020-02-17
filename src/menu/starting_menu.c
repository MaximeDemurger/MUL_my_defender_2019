/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** starting menu
*/

#include "my.h"

void event_bis(utils_t *utils)
{
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 800
        && sfMouse_getPositionRenderWindow(utils->window).y <= 900) {
        utils->strt_menu = false;
        sfRenderWindow_close(utils->window);
    }
}

void strt_menu_event(utils_t *utils)
{
    if (utils->event.type == sfEvtClosed) {
        utils->strt_menu = false;
        sfRenderWindow_close(utils->window);
    }
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500)
        utils->strt_menu = false;
    if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 800
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        utils->strt_menu = false;
        utils->settings = true;
        utils->from_strt = true;
        }
    event_bis(utils);
}

void hoover_button_bis(utils_t *utils)
{
    sfVector2f pos3 = {825, 390};

    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500) {
        sfSprite_setPosition(utils->hoover, pos3);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
}

void hoover_button(utils_t *utils)
{
    sfVector2f pos1 = {825, 790};
    sfVector2f pos2 = {825, 590};

    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 800
        && sfMouse_getPositionRenderWindow(utils->window).y <= 900) {
        sfSprite_setPosition(utils->hoover, pos1);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        sfSprite_setPosition(utils->hoover, pos2);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
    hoover_button_bis(utils);
}

void starting_menu(utils_t *utils, strtmenu_t *start)
{
    sfText *text = sfText_create();
    sfVector2f pos = {600, 250};

    sfText_setString(text, "WELCOME TO MY_DEFENDER");
    sfText_setCharacterSize(text, 75);
    sfText_setFont(text, utils->font);
    sfText_setPosition(text, pos);
    sfRenderWindow_clear(utils->window, sfBlack);
    while (utils->strt_menu == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)){
            strt_menu_event(utils);
        }
        sfRenderWindow_drawSprite(utils->window, start->background, NULL);
        hoover_button(utils);
        sfRenderWindow_drawSprite(utils->window, start->play, NULL);
        sfRenderWindow_drawSprite(utils->window, start->quit, NULL);
        sfRenderWindow_drawSprite(utils->window, start->settings, NULL);
        sfRenderWindow_drawText(utils->window, text, NULL);
        sfRenderWindow_display(utils->window);
    }
}