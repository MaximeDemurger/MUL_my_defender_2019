/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** menu_structs
*/

#ifndef MENU
#define MENU

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"
#include <stdbool.h>

typedef struct start_menu {
    sfTexture *background_text;
    sfSprite *background;
    sfTexture *play_text;
    sfSprite *play;
    sfTexture *quit_text;
    sfSprite *quit;
    sfTexture *set_text;
    sfSprite *settings;
}strtmenu_t;

typedef struct settings_s {
    sfTexture *bg_text;
    sfSprite *bg;
    sfTexture *plus_text;
    sfSprite *plus;
    sfTexture *minus_text;
    sfSprite *minus;
    sfTexture *quit_text;
    sfSprite *quit;
    float volume;
}settings_t;

typedef struct pause_menu {
    sfTexture *background_text;
    sfSprite *background;
    sfTexture *play_text;
    sfSprite *play;
    sfTexture *quit_text;
    sfSprite *quit;
}pausemenu_t;

typedef struct death_menu {
    sfText *text;
    sfFont *font;
    sfTexture *background_text;
    sfSprite *background;
    sfTexture *play_text;
    sfSprite *play;
    sfTexture *quit_text;
    sfSprite *quit;
}deathmenu_t;

#endif /* !MENU */
