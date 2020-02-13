/*
** EPITECH PROJECT, 2019
** myrunner
** File description:
** destroy game
*/

#include "my.h"

void destroy_game(game_t *game)
{
    destroy_menu(game->start, game->pause);
    sfRenderWindow_destroy(game->utils->window);
    free(game->utils);
    free(game->start);
    free(game->pause);
    free(game);
}