/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** main structs
*/

#ifndef MAIN_STRUCT
#define MAIN_STRUCT

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"

typedef struct game_s {
    struct start_menu *start;
    struct pause_menu *pause;
    struct death_menu *death;
    struct utils *utils;
    struct settings_s *settings;
}game_t;

typedef struct utils {
    sfRenderWindow *window;
    sfFont *font;
    sfEvent event;
    sfClock *clock;
    char **map;
    int life;
    int score;
    bool strt_menu;
    bool death;
    bool pause;
    bool settings;
}utils_t;

#endif /* !MAIN_STRUCT */
