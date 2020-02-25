/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

void find_line_col(utils_t *utils, int *line, int *col)
{
    int x = 0;
    int y = 0;

    while (y < my_atoi(utils->case_pos[utils->line + 1])) {
        y += 135;
        *line += 1;
    }
    while (x < my_atoi(utils->case_pos[utils->line])) {
        x += 128;
        *col += 1;
    }
}

int check_pos(utils_t *utils, int mouse_x, int mouse_y, char **tab)
{
    utils->line = 0;
    int line = 0;
    int col = 0;

    while (utils->case_pos[utils->line]) {
        if (mouse_x > my_atoi(utils->case_pos[utils->line]) - 120 &&
            mouse_x < my_atoi(utils->case_pos[utils->line]) + 120 &&
            mouse_y > my_atoi(utils->case_pos[utils->line + 1]) &&
            mouse_y < my_atoi(utils->case_pos[utils->line + 1]) + 120 &&
            utils->click_on_tower == 1) {
            find_line_col(utils, &line, &col);
            utils->tow_pos_x = my_atoi(utils->case_pos[utils->line]);
            utils->tow_pos_y = my_atoi(utils->case_pos[utils->line + 1]);
            tab[line][col] = 'N';
            get_pos_case(utils, tab);
            utils->money -= 20;
            utils->click_on_tower = 2;
            return 1;
        } else if (mouse_x < my_atoi(utils->case_pos[utils->line]) - 120 &&
        mouse_x > my_atoi(utils->case_pos[utils->line]) + 120 &&
        mouse_y < my_atoi(utils->case_pos[utils->line + 1]) &&
        mouse_y > my_atoi(utils->case_pos[utils->line + 1]) + 120 &&
        utils->click_on_tower == 1) {
            utils->click_on_tower = 0;
        }
        utils->line += 2;
    }
    return 0;
}

void click_book(game_t *game, int mouse_x, int mouse_y)
{
    if (game->utils->open_book == 0 &&
        (mouse_x > sfSprite_getPosition(game->play->bookclose).x - 160 &&
        mouse_x < sfSprite_getPosition(game->play->bookclose).x + 160 &&
        mouse_y > sfSprite_getPosition(game->play->bookclose).y - 160 &&
        mouse_y < sfSprite_getPosition(game->play->bookclose).y + 160) &&
        game->utils->clicked > 2){
        game->utils->open_book = 1;
        game->utils->clicked = 0;
    } else if (game->utils->open_book == 1 &&
        (mouse_x > sfSprite_getPosition(game->play->bookopen).x - 160 &&
        mouse_x < sfSprite_getPosition(game->play->bookopen).x + 160 &&
        mouse_y > sfSprite_getPosition(game->play->bookopen).y - 160 &&
        mouse_y < sfSprite_getPosition(game->play->bookopen).y + 160) &&
        game->utils->clicked > 2) {
        game->utils->open_book = 0;
        game->utils->clicked = 0;
    }
    game->utils->clicked++;
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
        if ((mouse_x > sprite_x - 80 && mouse_x < sprite_x + 80 &&
            mouse_y > sprite_y - 80 && mouse_y < sprite_y + 80) &&
            utils->click_on_tower == 0) {
            utils->click_on_tower = 1;
        } if (utils->click_on_tower == 1) {
            check_pos(utils, mouse_x, mouse_y, tab);
        }  
        click_book(game, mouse_x, mouse_y);
    }
}