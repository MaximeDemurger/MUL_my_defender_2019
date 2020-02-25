/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** init hud
*/

#include "my.h"

int init_hud(hud_t *hud)
{
    sfVector2f pos_coin = {1800, 950};
    sfVector2f pos_coin_txt = {1700, 900};
    sfVector2f pos_heart = {1800, 850};
    sfVector2f pos_life = {1800, 800};

    hud->coin_text = sfTexture_createFromFile("image/coin.png", NULL);
    hud->coin = sfSprite_create();
    hud->heart_text = sfTexture_createFromFile("image/coin.png", NULL);
    hud->heart = sfSprite_create();
    hud->life = sfText_create();
    hud->coin_txt = sfText_create();
    if (!hud->coin_text || !hud->coin || !hud->heart_text ||
        !hud->heart || !hud->life || !hud->coin_txt)
        return 1;
    sfSprite_setTexture(hud->coin, hud->coin_text, sfTrue);
    sfSprite_setTexture(hud->heart, hud->heart_text, sfTrue);
    sfSprite_setPosition(hud->coin, pos_coin);
    sfSprite_setPosition(hud->heart, pos_heart);
    sfText_setPosition(hud->coin_txt, pos_coin_txt);
    sfText_setPosition(hud->life, pos_life);
    return 0;
}