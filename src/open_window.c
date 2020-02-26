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

void move_rects(utils_t *utils, hud_t *hud)
{
    if (sfClock_getElapsedTime(utils->heart).microseconds
        / 1000000.0 >= 0.1) {
        hud->heart_r.left += 139;
        if (hud->heart_r.left >= 1800)
            hud->heart_r.left = 0;
        sfClock_restart(utils->heart);
    }
    if (sfClock_getElapsedTime(utils->clock).microseconds
        / 1000000.0 >= 0.05) {
        hud->coin_r.left += 56;
        if (hud->coin_r.left >= 560)
            hud->coin_r.left = 0;
        sfClock_restart(utils->clock);
    }
}

void function_caller(game_t *game, utils_t *utils, char **map, path_t *path)
{
        check_utils(utils, game);
        capture_events(utils, game, map);
        printing_map(map, utils);
        gameplay(game, path, map);
        move_rects(utils, game->hud);
        draw_hud(game->hud, utils);
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
        function_caller(game, utils, map, path);
        if (!game->enemy) enemy_wave(&game->enemy, 5, utils, path);
        if (utils->life <= 0) utils->death = true;
        print_basement(map, utils, utils->map_pars);
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}