/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** draw hud
*/

#include "my.h"

void draw_heart(utils_t *utils, hud_t *hud)
{
    char *life = convert_to_string(utils->life);
    sfVector2f scale_text = {3, 3};

    sfText_setString(hud->life, life);
    sfText_setScale(hud->life, scale_text);
    sfText_setFont(hud->life, utils->font);
    free(life);
    sfSprite_setTextureRect(hud->heart, hud->heart_r);
    sfRenderWindow_drawSprite(utils->window, hud->heart, NULL);
    sfRenderWindow_drawText(utils->window, hud->life, NULL);
}

void draw_hud(hud_t *hud, utils_t *utils)
{
    char *coin_text = convert_to_string(utils->money);
    sfVector2f scale_text = {3, 3};

    sfText_setString(hud->coin_txt, coin_text);
    sfText_setScale(hud->coin_txt, scale_text);
    sfText_setFont(hud->coin_txt, utils->font);
    free(coin_text);
    sfSprite_setTextureRect(hud->coin, hud->coin_r);
    sfRenderWindow_drawSprite(utils->window, hud->coin, NULL);
    sfRenderWindow_drawText(utils->window, hud->coin_txt, NULL);
    draw_heart(utils, hud);
}