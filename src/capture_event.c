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

int check_other_clicks(utils_t *utils, int i)
{
    if (i == 1) {
        if (utils->click_on_tower2 != 1 && utils->click_on_tower3 != 1 &&
            utils->click_on_tower4 != 1)
            return 1;
    } if (i == 2) {
        if (utils->click_on_tower1 != 1 && utils->click_on_tower3 != 1 &&
            utils->click_on_tower4 != 1)
            return 1;
    } if (i == 3) {
        if (utils->click_on_tower2 != 1 && utils->click_on_tower1 != 1 &&
            utils->click_on_tower4 != 1)
            return 1;
    } if (i == 4) {
        if (utils->click_on_tower2 != 1 && utils->click_on_tower3 != 1 &&
            utils->click_on_tower1 != 1)
            return 1;
    }
    return 0;
}

void check_which_tower(utils_t *utils, play_t *play, int mouse_x, int mouse_y)
{
    sfVector2f tower1 = sfSprite_getPosition(play->tower1);
    sfVector2f tower2 = sfSprite_getPosition(play->tower2);
    sfVector2f tower3 = sfSprite_getPosition(play->tower3);
    sfVector2f tower4 = sfSprite_getPosition(play->tower4);

    if ((mouse_x > tower1.x && mouse_x < tower1.x + 50 &&
        mouse_y > tower1.y && mouse_y < tower1.y + 50) &&
        utils->click_on_tower1 == 0 && check_other_clicks(utils, 1) == 1)
        utils->click_on_tower1 = 1;
    if ((mouse_x > tower2.x && mouse_x < tower2.x + 50 &&
        mouse_y > tower2.y && mouse_y < tower2.y + 50) &&
        utils->click_on_tower2 == 0 && check_other_clicks(utils, 2) == 1)
        utils->click_on_tower2 = 1;
    if ((mouse_x > tower3.x && mouse_x < tower3.x + 50 &&
        mouse_y > tower3.y && mouse_y < tower3.y + 50) &&
        utils->click_on_tower3 == 0 && check_other_clicks(utils, 3) == 1)
        utils->click_on_tower3 = 1;
    if ((mouse_x > tower4.x && mouse_x < tower4.x + 50 &&
        mouse_y > tower4.y && mouse_y < tower4.y + 50) &&
        utils->click_on_tower4 == 0 && check_other_clicks(utils, 4) == 1)
        utils->click_on_tower4 = 1;
}

void get_tower_pos(game_t *game)
{
    game->play->tower2_pos = sfSprite_getPosition(game->play->tower2);
    game->play->tower3_pos = sfSprite_getPosition(game->play->tower3);
    game->play->tower4_pos = sfSprite_getPosition(game->play->tower4);
}

void capture_events(utils_t *utils, game_t *game, char **tab)
{
    int mouse_y = utils->event.mouseButton.y;
    int mouse_x = utils->event.mouseButton.x;

    get_tower_pos(game);
    while (sfRenderWindow_pollEvent(utils->window, &utils->event)) {
        if (utils->event.type == sfEvtClosed)
            sfRenderWindow_close(utils->window);
        if (utils->event.type == sfEvtKeyPressed &&
            utils->event.key.code == sfKeyEscape)
            utils->pause = true;
        check_which_tower(game->utils, game->play, mouse_x, mouse_y);
        if (utils->click_on_tower1 == 1 || utils->click_on_tower2 == 1 ||
            utils->click_on_tower3 == 1 || utils->click_on_tower4 == 1)
            check_pos(game, mouse_x, mouse_y, tab);
        click_book(game, mouse_x, mouse_y);
    }
}