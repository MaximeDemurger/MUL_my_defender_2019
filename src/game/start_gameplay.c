/*
** EPITECH PROJECT, 2020
** gamepaly
** File description:
** gameplay
*/

#include "my.h"

void put_book(game_t *game)
{
    sfVector2f pos_menu_book = {370, 100};
    sfVector2f pos_book = {1780, 0};

    sfSprite_setPosition(game->play->menubook, pos_menu_book);
    sfSprite_setPosition(game->play->bookclose, pos_book);
    sfSprite_setPosition(game->play->bookopen, pos_book);
    if (game->utils->open_book == 0)
        sfRenderWindow_drawSprite(game->utils->window, game->play->bookclose,
                                                                        NULL);
    else if (game->utils->open_book == 1) {
        sfRenderWindow_drawSprite(game->utils->window, game->play->bookopen,
                                                                        NULL);
        sfRenderWindow_drawSprite(game->utils->window, game->play->menubook,
                                                                        NULL);
    }
}

void print_inventory(char **tab, utils_t *utils)
{
    int col = 0;
    int x = 0;
    sfVector2f pos = {x, 945};

    while (tab[7][col]) {
        if (tab[7][col] == 'R') {
            sfSprite_setPosition(utils->map_pars->rock, pos);
            sfRenderWindow_drawSprite(utils->window, utils->map_pars->rock,
                                                                    NULL);
        }
        if (tab[7][col] == 'I') {
            sfSprite_setPosition(utils->map_pars->inventory, pos);
            sfSprite_setPosition(utils->map_pars->rock, pos);
            sfRenderWindow_drawSprite(utils->window, utils->map_pars->rock,
                                                                    NULL);
            sfRenderWindow_drawSprite(utils->window,
                                        utils->map_pars->inventory, NULL);
        }
        pos.x += 128;
        col++;
    }
}

void gameplay(game_t *game, path_t *path, char **tab)
{
    int x = sfMouse_getPositionRenderWindow(game->utils->window).x;
    int y = sfMouse_getPositionRenderWindow(game->utils->window).y;
    sfVector2f pos = {660, 945};
    sfVector2f mouse = {x - 32, y - 32};
    sfVector2f set_tow = {game->play->tow1_pos_x, game->play->tow1_pos_y};

    tower_onset(game, pos, set_tow);
    attack_castle(&game->enemy, game->utils);
    pathfinding(game->enemy, path, game->utils);
    put_book(game);
    print_inventory(tab, game->utils);
    put_tower1(game, pos, mouse);
    put_tower2(game, mouse);
    put_tower3(game, mouse);
    put_tower4(game, mouse);
}