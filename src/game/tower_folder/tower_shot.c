/*
** EPITECH PROJECT, 2020
** tower_shot
** File description:
** tower_shot
*/

#include "my.h"
#include <math.h>

void tower_shot(game_t *game)
{
    float y;
    sfVector2f pos_missile = sfSprite_getPosition(game->play->tower1);
    static int pass = 0;
    int tow_pos_X = sfSprite_getPosition(game->play->tower1).x;
    int enemy_pos_X = sfSprite_getPosition(game->enemy->sprite).x;
    int tow_pos_Y = sfSprite_getPosition(game->play->tower1).y;
    int enemy_pos_Y = sfSprite_getPosition(game->enemy->sprite).y;
    double a = enemy_pos_X - tow_pos_X;
    double b = enemy_pos_Y - tow_pos_Y;

    if (pass == 0) {
        pos_missile.x -= 60;
        pos_missile.y -= 60;
        pass++;
    }
    y = -atan2(a, b) * 180 / 3.14;
    sfSprite_setRotation(game->play->missile, y);
    sfSprite_setPosition(game->play->missile, pos_missile);
    sfRenderWindow_drawSprite(game->utils->window, game->play->missile, NULL);
}