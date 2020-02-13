/*
** EPITECH PROJECT, 2020
** my runner
** File description:
** init death
*/

#include "my.h"

void set_death(deathmenu_t *death)
{
    sfVector2f play_pos = {850, 400};
    sfVector2f quit_pos = {850, 600};
    sfVector2f text_pos = {900, 300};

    sfText_setFont(death->text, death->font);
    sfText_setString(death->text, "YOU DIED");
    sfText_setCharacterSize(death->text, 50);
    sfText_setPosition(death->text, text_pos);
    sfSprite_setTexture(death->background, death->background_text, sfTrue);
    sfSprite_setTexture(death->play, death->play_text, sfTrue);
    sfSprite_setTexture(death->quit, death->quit_text, sfTrue);
    sfSprite_setPosition(death->play, play_pos);
    sfSprite_setPosition(death->quit, quit_pos);
}

int init_death(deathmenu_t *death)
{
    death->font = sfFont_createFromFile("image/police.otf");
    death->text = sfText_create();
    death->background_text = sfTexture_createFromFile("image/war.jpg", NULL);
    death->background = sfSprite_create();
    death->play_text = sfTexture_createFromFile("image/start.png", NULL);
    death->play = sfSprite_create();
    death->quit_text = sfTexture_createFromFile("image/quit.png", NULL);
    death->quit = sfSprite_create();
    if (!death->background_text || !death->background ||
        !death->play_text || !death->play || !death->text ||
        !death->quit_text || !death->quit || !death->font)
        return 1;
    set_death(death);
    return 0;
}