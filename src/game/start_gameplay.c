/*
** EPITECH PROJECT, 2020
** gamepaly
** File description:
** gameplay
*/

#include "my.h"

void put_tower(game_t *game)
{
    sfVector2f pos = {645, 945};

    sfSprite_setPosition(game->play->tower1, pos);
    sfRenderWindow_drawSprite(game->utils->window, game->play->tower1, NULL);
}

void gameplay(game_t *game)
{
    put_tower(game);
}