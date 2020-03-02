/*
** EPITECH PROJECT, 2020
** range
** File description:
** range tower
*/

#include "my.h"
#include <math.h>

void set_rotation(game_t *game, sfVector2f set_tow)
{
    float y;
    sfVector2f origin = {27, 10};
    static int pass = 0;
    int tow_pos_X = sfSprite_getPosition(game->play->tower1).x;
    int enemy_pos_X = sfSprite_getPosition(game->enemy->sprite).x;
    int tow_pos_Y = sfSprite_getPosition(game->play->tower1).y;
    int enemy_pos_Y = sfSprite_getPosition(game->enemy->sprite).y;
    double a = enemy_pos_X - tow_pos_X;
    double b = enemy_pos_Y - tow_pos_Y;

    y = -atan2(a, b) * 180 / 3.14;
    sfSprite_setOrigin(game->play->missile, origin);
    sfSprite_setRotation(game->play->tower1, y);
    if (pass == 0) {
        game->play->pos_missile = set_tow;
        pass++;
    }
    tower_shot(game);
}

void range_tower(game_t *game, sfVector2f set_tow)
{
    sfVector2f tower_pos = sfSprite_getPosition(game->play->range);
    sfVector2f enemy_pos = sfSprite_getPosition(game->enemy->sprite);
    sfClock *clock;
    
    if (enemy_pos.x > tower_pos.x &&
        enemy_pos.x < tower_pos.x + 500 &&
        enemy_pos.y > tower_pos.y &&
        enemy_pos.y < tower_pos.y + 500) {
        set_rotation(game, set_tow);
        //enemy_hit(game->enemy, 20);
    }
}

void tower_onset(game_t *game, sfVector2f pos, sfVector2f set_tow)
{
    sfVector2f origin = {45, 65};
    sfVector2f range = {set_tow.x, set_tow.y};

    set_tow.x += 64;
    set_tow.y += 70;
    range.x -= 185;
    range.y -= 185;
    if (game->utils->click_on_tower == 2) {
        sfSprite_setOrigin(game->play->tower1, origin);
        range_tower(game, set_tow);
        sfSprite_setPosition(game->play->range, range);
        sfRenderWindow_drawSprite(game->utils->window,
                                    game->play->range, NULL);
        sfSprite_setPosition(game->play->tower1, set_tow);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower1,
                                                                        NULL);
    }
}