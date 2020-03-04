/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** hoover selection menu
*/

#include "my.h"

void select_hoover_bis(utils_t *utils)
{
    sfVector2f pos1 = {825, 590};
    sfVector2f pos2 = {825, 790};

    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        sfSprite_setPosition(utils->hoover, pos1);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 800
        && sfMouse_getPositionRenderWindow(utils->window).y <= 900) {
        sfSprite_setPosition(utils->hoover, pos2);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
}

void do_select_hoover(utils_t *utils)
{
    sfVector2f pos1 = {825, 190};
    sfVector2f pos2 = {825, 390};

    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 200
        && sfMouse_getPositionRenderWindow(utils->window).y <= 300) {
        sfSprite_setPosition(utils->hoover, pos1);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
    if (sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500) {
        sfSprite_setPosition(utils->hoover, pos2);
        sfRenderWindow_drawSprite(utils->window, utils->hoover, NULL);
    }
    select_hoover_bis(utils);
}