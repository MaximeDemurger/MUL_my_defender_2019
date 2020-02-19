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
    sfVector2f pos = {645, 945};
    sfVector2f mouse = {x - 32, y - 32};
    sfVector2f set_tow = {my_atoi(game->utils->case_pos[game->utils->line]),
                        my_atoi(game->utils->case_pos[game->utils->line + 1])};

    sfSprite_setPosition(game->play->tower1, pos);
    sfRenderWindow_drawSprite(game->utils->window, game->play->tower1, NULL);
    if (game->utils->click_on_tower == 1) {
        sfSprite_setPosition(game->play->select_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                  NULL);
    }
    if (game->utils->click_on_tower == 2) {
        sfSprite_setPosition(game->play->tower1, set_tow);
        sfRenderWindow_drawSprite(game->utils->window,
                                    game->play->tower1, NULL);
    }
}

void gameplay(game_t *game)
{
    put_tower(game);
}