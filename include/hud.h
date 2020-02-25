/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** hud.h
*/

#ifndef HUD
#define HUD

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>

typedef struct hud_s {
    sfTexture *coin_text;
    sfSprite *coin;
    sfTexture *heart_text;
    sfSprite *heart;
    sfText *coin_txt;
    sfText *life;
}hud_t;

#endif /* !HUD */
