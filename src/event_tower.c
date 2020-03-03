/*
** EPITECH PROJECT, 2020
** tower_event
** File description:
** event
*/

#include "my.h"

int check_mouse_case(int mouse_x, int mouse_y, utils_t *utils)
{
    if (mouse_x < my_atoi(utils->case_pos[utils->line]) - 120 &&
        mouse_x > my_atoi(utils->case_pos[utils->line]) + 120 &&
        mouse_y < my_atoi(utils->case_pos[utils->line + 1]) &&
        mouse_y > my_atoi(utils->case_pos[utils->line + 1]) + 120) {
        if (utils->click_on_tower1 == 1)
            utils->click_on_tower1 = 0;
        if (utils->click_on_tower2 == 1)
            utils->click_on_tower2 = 0;
        if (utils->click_on_tower3 == 1)
            utils->click_on_tower3 = 0;
        if (utils->click_on_tower4 == 1)
            utils->click_on_tower4 = 0;
    }
    return 0;
}

int check_selected_tower(game_t *game, char **tab, int line, int col)
{
    if (game->utils->click_on_tower1 == 1)
        result_case_good1(game, line, col, tab);
    if (game->utils->click_on_tower2 == 1)
        result_case_good2(game, line, col, tab);
    if (game->utils->click_on_tower3 == 1)
        result_case_good3(game, line , col, tab);
    if (game->utils->click_on_tower4 == 1)
        result_case_good4(game, line , col, tab);
    return 0;
}

int check_pos(game_t *game, int mouse_x, int mouse_y, char **tab)
{
    game->utils->line = 0;
    int line = 0;
    int col = 0;

    while (game->utils->case_pos[game->utils->line]) {
        if (mouse_x > my_atoi(game->utils->case_pos[game->utils->line]) - 120 &&
            mouse_x < my_atoi(game->utils->case_pos[game->utils->line]) + 120 &&
            mouse_y > my_atoi(game->utils->case_pos[game->utils->line + 1]) &&
            mouse_y < my_atoi(game->utils->case_pos[game->utils->line + 1]) + 120)
            check_selected_tower(game, tab, line, col);
        check_mouse_case(mouse_x, mouse_y, game->utils);
        game->utils->line += 2;
    }
    return 0;
}