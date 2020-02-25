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

int open_window(utils_t *utils, game_t *game, char **av)
{
    utils->map_pars = malloc(sizeof(map_t));
    char **map = gettingMap_fromFile(av);
    path_t *path = NULL;

    if (!map)
        return 1;
    get_pos_case(utils, map);
    init_map(utils->map_pars, av);
    path = get_path(map);
    //sfMusic_play(utils->song);
    enemy_wave(&game->enemy, 5, utils, path);
    while (sfRenderWindow_isOpen(utils->window)) {
        check_utils(utils, game);
        capture_events(utils, game, map);
        printing_map(map, utils);
        gameplay(game, path);
        draw_hud(game->hud, utils);
        if (!game->enemy) enemy_wave(&game->enemy, 5, utils, path);
        if (utils->life <= 0) utils->death = true;
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}