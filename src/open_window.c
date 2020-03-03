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
    capture_events(utils, game, map);
    printing_map(map, utils);
    gameplay(game, path, map);
    move_rects(utils, game->hud);
    draw_hud(game->hud, utils);
}

int do_map_selection(utils_t *utils, char ***map, path_t **path, game_t *game)
{
    char *selected_file = 
        show_map_options(utils, game->select, game->all_maps);

    *map = gettingMap_fromFile(selected_file);
    if (!(*map))
        return 1;
    get_pos_case(utils, *map);
    init_map(utils->map_pars);
    *path = get_path(*map);
    enemy_wave(&game->enemy, 5, utils, *path);
    return 0;
}

int open_window(utils_t *utils, game_t *game, char **av)
{
    utils->map_pars = malloc(sizeof(map_t));
    char **map = NULL;
    path_t *path = NULL;

    //sfMusic_play(utils->song);
    while (sfRenderWindow_isOpen(utils->window)) {
        if (utils->selection == true)
            if (do_map_selection(utils, &map, &path, game))
                return 1;
        check_utils(utils, game);
        function_caller(game, utils, map, path);
        if (!game->enemy) enemy_wave(&game->enemy, 5, utils, path);
        if (utils->life <= 0) utils->death = true;
        print_basement(map, utils, utils->map_pars);
        sfRenderWindow_display(utils->window);
        sfRenderWindow_clear(utils->window, sfBlack);
    }
    return 0;
}