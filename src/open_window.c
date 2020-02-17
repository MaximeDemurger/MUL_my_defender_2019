/*
** EPITECH PROJECT, 2019
** runnner
** File description:
** open window
*/

#include "my.h"

void check_utils(utils_t *utils, game_t *game)
{
    if (utils->pause == true)
        pause_menu(utils, game->pause);
    if (utils->strt_menu == true)
        starting_menu(utils, game->start);
    if (utils->death == true)
        death_menu(utils, game->death);
    if (utils->settings == true)
        settings_menu(utils, game->settings);
}

void open_window(utils_t *utils, game_t *game, char **av)
{
    sfMusic_play(utils->song);
    while (sfRenderWindow_isOpen(utils->window)) {
        check_utils(utils, game);
        capture_events(utils, game);
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
}