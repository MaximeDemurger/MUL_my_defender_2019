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
    utils->life = 1;
    utils->score = 0;
    utils->strt_menu = true;
    utils->death = false;
    utils->pause = false;
    utils->font = sfFont_createFromFile("image/police.otf");
    if (!utils->font)
        return 1;
    return 0;
}

int init_game(game_t *game)
{
    game->start = malloc(sizeof(strtmenu_t));
    game->pause = malloc(sizeof(pausemenu_t));
    game->death = malloc(sizeof(deathmenu_t));
    game->utils = malloc(sizeof(utils_t));
    if (!game->start || !game->pause || !game->death
        || !game->utils) {
        return 1;
    }
    if (init_utils(game->utils) || init_start(game->start, game->pause)
        || init_death(game->death)){
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
    if (!game)
        return 84;
    if (init_game(game)) {
        destroy_game(game);
        return 84;
    }
    game->utils->window = sfRenderWindow_create(view_mode, "MY RUNNER",
                    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->utils->window, 30);
    if (!game->utils->window) return 84;
    open_window(game->utils, game);
    destroy_game(game);
}