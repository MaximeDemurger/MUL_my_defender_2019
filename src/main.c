/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** main
*/

#include "my.h"

void print_help(void)
{
    my_putstr("HELP PAGE TO DO\n");
}

int init_utils(utils_t *utils)
{
    utils->life = 100;
    utils->money = 30;
    utils->wave = 0;
    utils->strt_menu = true;
    utils->death = false;
    utils->pause = false;
    utils->settings = false;
    utils->from_strt = false;
    utils->song = sfMusic_createFromFile("image/song.ogg");
    utils->font = sfFont_createFromFile("image/police.otf");
    utils->hoover_text = sfTexture_createFromFile("image/hoover.png", NULL);
    utils->hoover = sfSprite_create();
    utils->clock = sfClock_create();
    utils->heart = sfClock_create();
    if (!utils->font || !utils->song || !utils->hoover || !utils->hoover_text
        || !utils->clock || !utils->heart)
        return 1;
    sfSprite_setTexture(utils->hoover, utils->hoover_text, sfTrue);
    return 0;
}

int init_game(game_t *game)
{
    game->start = malloc(sizeof(strtmenu_t));
    game->pause = malloc(sizeof(pausemenu_t));
    game->death = malloc(sizeof(deathmenu_t));
    game->utils = malloc(sizeof(utils_t));
    game->settings = malloc(sizeof(settings_t));
    game->play = malloc(sizeof(play_t));
    game->hud = malloc(sizeof(hud_t));
    if (!game->start || !game->pause || !game->death || !game->hud
        || !game->utils || !game->settings || !game->play) {
        return 1;
    }
    if (init_utils(game->utils) || init_start(game->start, game->pause)
        || init_death(game->death) || init_settings(game->settings)
        || init_play(game->play) || init_hud(game->hud)) {
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode view_mode = {1920, 1080, 32};

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        print_help();
    if (!game) return 84;
    game->all_maps = NULL;
    if (init_game(game)) {
        destroy_game(game);
        return 84;
    } game->utils->window = sfRenderWindow_create(view_mode, "MY DEFENDER",
                    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->utils->window, 30);
    if (!game->utils->window) return 84;
    if (open_window(game->utils, game, av) == 1) {
        my_putstr("Wrong Map");
        destroy_game(game);
        return 84;
    }
    destroy_game(game);
    return 0;
}