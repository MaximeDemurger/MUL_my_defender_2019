/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

int check_pos(utils_t *utils, int mouse_x, int mouse_y)
{
    utils->line = 0;

    while (utils->case_pos[utils->line]) {
        if (mouse_x > my_atoi(utils->case_pos[utils->line]) - 120 &&
            mouse_x < my_atoi(utils->case_pos[utils->line]) + 120 &&
            mouse_y > my_atoi(utils->case_pos[utils->line + 1]) &&
            mouse_y < my_atoi(utils->case_pos[utils->line + 1]) + 120 &&
            utils->click_on_tower == 1) {
            utils->click_on_tower = 2;
            return 0;
        }
        utils->line += 2;
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
        if (utils->click_on_tower == 1)
            check_pos(utils, mouse_x, mouse_y);
    }
}