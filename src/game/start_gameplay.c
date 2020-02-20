/*
** EPITECH PROJECT, 2020
** gamepaly
** File description:
** gameplay
*/

#include "my.h"

void put_tower(game_t *game)
{
    int x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    int y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    int in_pos_x = game->utils->tow_pos_x;
    int in_pos_y = game->utils->tow_pos_y;
    sfVector2f pos = {645, 945};
    sfVector2f mouse = {x - 32, y - 32};
    sfVector2f set_tow = {in_pos_x, in_pos_y};

    if (game->utils->click_on_tower < 2) {
        sfSprite_setPosition(game->play->tower1, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower1,
                                  NULL);
    } if (game->utils->click_on_tower == 1) {
        sfSprite_setPosition(game->play->select_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                  NULL);
    }
    tower_onset(game, pos, set_tow);
    //tower_shot(game, set_tow);
}

void gameplay(game_t *game, path_t *path)
{
    put_tower(game);
    attack_castle(&game->enemy, game->utils);
    pathfinding(game->enemy, path, game->utils);
}