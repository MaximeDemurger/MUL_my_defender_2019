/*
** EPITECH PROJECT, 2020
** tower_shot
** File description:
** tower_shot
*/

#include "my.h"

void tower_shot(game_t *game)
{
    int enemy_x = sfSprite_getPosition(game->enemy->sprite).x;
    int enemy_y = sfSprite_getPosition(game->enemy->sprite).y;
    int delta_x = enemy_x - game->play->pos_missile.x;
    int delta_y = enemy_y - game->play->pos_missile.y;

    if (delta_x < 0 && delta_y > 0) {
        game->play->pos_missile.x -= 2;
        game->play->pos_missile.y += 2;
    }
    if (delta_x > 0 && delta_y < 0) {
        game->play->pos_missile.x += 2;
        game->play->pos_missile.y -= 2;
    }
    if (delta_x > 0 && delta_y > 0) {
        game->play->pos_missile.x += 2;
        game->play->pos_missile.y += 2;
    }
    if (delta_x < 0 && delta_y < 0) {
        game->play->pos_missile.x -= 2;
        game->play->pos_missile.y -= 2;
    }
    sfSprite_setPosition(game->play->missile, game->play->pos_missile);
    sfRenderWindow_drawSprite(game->utils->window, game->play->missile, NULL);
}