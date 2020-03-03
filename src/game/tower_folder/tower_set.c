/*
** EPITECH PROJECT, 2020
** tower1
** File description:
** file
*/

#include "my.h"

void put_tower4(game_t *game, sfVector2f mouse)
{
    sfVector2f pos = {1044, 940};

    if (game->utils->click_on_tower4 == 0) { 
        sfSprite_setPosition(game->play->tower4, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower4,
                                                                        NULL);
    } if (game->utils->click_on_tower4 == 1) {
        sfSprite_setPosition(game->play->select4_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select4_tow,
                                  NULL);
    } if (game->utils->click_on_tower4 == 2) {
        sfSprite_setPosition(game->play->select4_tow, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select4_tow,
                                                                        NULL);
    }
}

void put_tower3(game_t *game, sfVector2f mouse)
{
    sfVector2f pos = {916, 950};

    if (game->utils->click_on_tower3 == 0) { 
        sfSprite_setPosition(game->play->tower3, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower3,
                                                                        NULL);
    } if (game->utils->click_on_tower3 == 1) {
        sfSprite_setPosition(game->play->select3_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select3_tow,
                                  NULL);
    } if (game->utils->click_on_tower3 == 2) {
        sfSprite_setPosition(game->play->select3_tow, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select3_tow,
                                                                        NULL);
    }
}

void put_tower2(game_t *game, sfVector2f mouse)
{
    sfVector2f pos = {788, 950};

    if (game->utils->click_on_tower2 == 0) { 
        sfSprite_setPosition(game->play->tower2, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower2,
                                                                    NULL);
    } if (game->utils->click_on_tower2 == 1) {
        sfSprite_setPosition(game->play->select2_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select2_tow,
                                  NULL);
    } if (game->utils->click_on_tower2 == 2) {
        sfSprite_setPosition(game->play->select2_tow, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select2_tow,
                                                                        NULL);
    }
}

void put_tower1(game_t *game, sfVector2f pos, sfVector2f mouse)
{

    if (game->utils->click_on_tower1 == 0) {
        sfSprite_setPosition(game->play->tower1, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->tower1,
                                  NULL);
    } if (game->utils->click_on_tower1 == 1) {
        sfSprite_setPosition(game->play->select_tow, mouse);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                  NULL);
    } if (game->utils->click_on_tower1 == 2) {
        sfSprite_setPosition(game->play->select_tow, pos);
        sfRenderWindow_drawSprite(game->utils->window, game->play->select_tow,
                                                                        NULL);
    }
}