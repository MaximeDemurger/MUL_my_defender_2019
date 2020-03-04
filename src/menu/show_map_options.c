/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** show map options
*/

#include "my.h"

char *correct_map(all_map_t *maps, int num)
{
    int position = 0;
    all_map_t *tmp = maps;

    while (position != num) {
        tmp = tmp->next; 
        position++;       
    }
    return tmp->filename;
}

char *check_bis(utils_t *utils, all_map_t *maps)
{
    if(utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 600
        && sfMouse_getPositionRenderWindow(utils->window).y <= 700) {
        utils->selection = false;
        utils->strt_menu = true;
        return correct_map(maps, 3);
    }
    if(utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 800
        && sfMouse_getPositionRenderWindow(utils->window).y <= 900) {
        utils->selection = false;
        utils->strt_menu = true;
        return correct_map(maps, 4);
    }
    return NULL;
}

char *check_events(utils_t *utils, all_map_t *maps)
{
    if (utils->event.type == sfEvtClosed) {
        utils->selection = false;
        sfRenderWindow_close(utils->window);
    } if (utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 200
        && sfMouse_getPositionRenderWindow(utils->window).y <= 300) {
        utils->selection = false;
        utils->strt_menu = true;
        return maps->filename;
    } if(utils->event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(utils->window).x >= 850
        && sfMouse_getPositionRenderWindow(utils->window).x <= 1100
        && sfMouse_getPositionRenderWindow(utils->window).y >= 400
        && sfMouse_getPositionRenderWindow(utils->window).y <= 500) {
        utils->selection = false;
        utils->strt_menu = true;
        return correct_map(maps, 2);
    }
    return check_bis(utils, maps);
}

char *show_map_options(utils_t *utils, selection_t *select, all_map_t *maps)
{
    char *map = NULL;

    sfRenderWindow_clear(utils->window, sfBlack);
    while (utils->selection == true) {
        while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
            map = check_events(utils, maps);
        }
        sfRenderWindow_drawSprite(utils->window, select->back, NULL);
        do_select_hoover(utils);
        sfRenderWindow_drawSprite(utils->window, select->map1, NULL);
        sfRenderWindow_drawSprite(utils->window, select->map2, NULL);
        sfRenderWindow_drawSprite(utils->window, select->map3, NULL);
        sfRenderWindow_drawSprite(utils->window, select->map4, NULL);
        sfRenderWindow_display(utils->window);
    }
    return map;
}