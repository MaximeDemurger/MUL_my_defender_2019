/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

int check_pos(utils_t *utils, int mouse_x, int mouse_y)
{
    int line = 0;

    while (utils->case_pos[line]) {
        if (mouse_x > utils->case_pos[line][0] - 120 &&
            mouse_x < utils->case_pos[line][0] + 120 &&
            mouse_y > utils->case_pos[line][1] &&
            mouse_y < utils->case_pos[line][1] + 120 &&
            utils->click_on_tower == 1)
            utils->click_on_tower = 0;
        line++;
    }
    return 0;
}

void capture_events(utils_t *utils, game_t *game, char **tab)
{
    int mouse_y = utils->event.mouseButton.y;
    int mouse_x = utils->event.mouseButton.x;
    int sprite_x = sfSprite_getPosition(game->play->tower1).x;
    int sprite_y = sfSprite_getPosition(game->play->tower1).y;

    while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
        if (utils->event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if (utils->event.type == sfEvtKeyPressed &&
            utils->event.key.code == sfKeyEscape)
            utils->pause = true;
        if (mouse_x > sprite_x - 120 && mouse_x < sprite_x + 120 &&
            mouse_y > sprite_y && mouse_y < sprite_y + 120)
            utils->click_on_tower = 1;
        //check_pos(utils, mouse_x, mouse_y);
    }
}