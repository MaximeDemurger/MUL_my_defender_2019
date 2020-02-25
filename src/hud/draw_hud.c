/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** draw hud
*/

#include "my.h"

void draw_hud(hud_t *hud, utils_t *utils)
{
    sfIntRect rect = sfSprite_getTextureRect(hud->coin);
    char *coin_text = convert_to_string(utils->money);

    sfText_setString(hud->coin_txt, coin_text);
    sfText_setFont(hud->coin_txt, utils->font);
    free(coin_text);
    if (sfClock_getElapsedTime(utils->clock).microseconds
        / 1000000.0 >= 0.05) {
        rect.left += 56;
        if (rect.left >= 560)
            rect.left = 0;
        sfSprite_setTextureRect(hud->coin, rect);
        sfClock_restart(utils->clock);
    }
    sfRenderWindow_drawSprite(utils->window, hud->coin, NULL);
    sfRenderWindow_drawText(utils->window, hud->coin_txt, NULL);
}