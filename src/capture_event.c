/*
** EPITECH PROJECT, 2019
** runner
** File description:
** capture events
*/

#include "my.h"

void click_book(game_t *game, int mouse_x, int mouse_y)
{
    sfVector2f book_pos = sfSprite_getPosition(game->play->bookclose);

    if (game->utils->open_book == 0 && (mouse_x > book_pos.x - 160 &&
        mouse_x < book_pos.x + 160 && mouse_y > book_pos.y - 160 &&
        mouse_y < book_pos.y + 160) && game->utils->clicked > 2){
        game->utils->open_book = 1;
        game->utils->clicked = 0;
    } else if (game->utils->open_book == 1 && (mouse_x > book_pos.x - 160 &&
        mouse_x < book_pos.x + 160 && mouse_y > book_pos.y - 160 &&
        mouse_y < book_pos.y + 160) && game->utils->clicked > 2) {
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
        } if (utils->click_on_tower == 1)
            check_pos(utils, mouse_x, mouse_y, tab);
        click_book(game, mouse_x, mouse_y);
    }
}