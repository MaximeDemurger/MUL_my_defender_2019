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

    if (game->utils->click_on_tower == 0) {
        sfSprite_setPosition(game->play->tower1, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower1,
                                  NULL);
    } if (game->utils->click_on_tower == 1) {
        sfSprite_setPosition(game->play->select_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                  NULL);
    }
    tower_onset(game, pos, set_tow);
}

void put_book(game_t *game)
{
    sfVector2f pos_menu_book = {370, 100};
    sfVector2f pos_book = {1780, 0};

    sfSprite_setPosition(game->play->menubook, pos_menu_book);
    sfSprite_setPosition(game->play->bookclose, pos_book);
    sfSprite_setPosition(game->play->bookopen, pos_book);
    if (game->utils->open_book == 0)
        sfRenderWindow_drawSprite(game->utils->window, game->play->bookclose, NULL);
    else if (game->utils->open_book == 1) {
        sfRenderWindow_drawSprite(game->utils->window, game->play->bookopen, NULL);
        sfRenderWindow_drawSprite(game->utils->window, game->play->menubook, NULL);
    }
}

void gameplay(game_t *game, path_t *path)
{
    put_tower(game);
    attack_castle(&game->enemy, game->utils);
    pathfinding(game->enemy, path, game->utils);
    put_book(game);
}