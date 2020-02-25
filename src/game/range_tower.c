/*
** EPITECH PROJECT, 2020
** range
** File description:
** range tower
*/

#include "my.h"

void set_rotation(game_t *game, sfVector2f set_tow)
{
    float y;
    static int pass = 0;
    int tow_pos_X = sfSprite_getPosition(game->play->tower1).x;
    int enemy_pos_X = sfSprite_getPosition(game->enemy->sprite).x;
    int tow_pos_Y = sfSprite_getPosition(game->play->tower1).y;
    int enemy_pos_Y = sfSprite_getPosition(game->enemy->sprite).y;
    double a = enemy_pos_X - tow_pos_X;
    double b = enemy_pos_Y - tow_pos_Y;

    y = -atan2(a, b) * 180 / 3.14;
    sfSprite_setRotation(game->play->tower1, y);
    if (pass == 0) {
        game->play->pos_missile = set_tow;
        pass++;
    }
    if (sfSprite_getPosition(game->enemy->sprite).x == game->play->pos_missile.x &&
        sfSprite_getPosition(game->enemy->sprite).y == game->play->pos_missile.y) {
        game->play->pos_missile.x = set_tow.x;
        game->play->pos_missile.y = set_tow.y;
        write(1, "ok", 1);
    }
    tower_shot(game);
}

void range_tower(game_t *game, sfVector2f set_tow)
{
    sfVector2f tower_pos = sfSprite_getPosition(game->play->tower1);
    sfVector2f enemy_pos = sfSprite_getPosition(game->enemy->sprite);
    
    if ((tower_pos.x - 250 < enemy_pos.x ||
        tower_pos.x + 250 < enemy_pos.x) &&
        (tower_pos.y - 250 > enemy_pos.y ||
        tower_pos.y + 250 > enemy_pos.y)) {
        set_rotation(game, set_tow);
    } 
}

void tower_onset(game_t *game, sfVector2f pos, sfVector2f set_tow)
{
    sfVector2f origin = {64, 67.5};
    static int i = 0;

    set_tow.x += 68;
    set_tow.y += 68;
    if (game->utils->click_on_tower == 2) {
        sfSprite_setOrigin(game->play->tower1, origin);
        range_tower(game, set_tow);
        sfSprite_setPosition(game->play->tower1, set_tow);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower1,
                                                                        NULL);                                      
        sfSprite_setPosition(game->play->select_tow, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                                                        NULL);
    }
}