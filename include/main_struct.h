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
#include <SFML/Audio.h>
#include "SFML/System/Types.h"

typedef struct game_s {
    struct start_menu *start;
    struct pause_menu *pause;
    struct death_menu *death;
    struct utils *utils;
    struct settings_s *settings;
    struct play_s *play;
    struct enemy_s *enemy;
}game_t;

typedef struct utils {
    sfRenderWindow *window;
    sfFont *font;
    sfEvent event;
    sfClock *clock;
    sfMusic *song;
    sfTexture *hoover_text;
    sfSprite *hoover;
    char **map;
    int life;
    int score;
    bool strt_menu;
    bool death;
    bool pause;
    bool settings;
    bool from_strt;
    map_t *map_pars;
    int click_on_tower;
    int line;
    char **case_pos;
    int wave;
    int nb_ene;
}utils_t;

#endif /* !MAIN_STRUCT */
