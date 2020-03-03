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
    struct path_s *path;
    struct hud_s *hud;
    struct all_maps *all_maps;
}game_t;

typedef struct utils {
    sfRenderWindow *window;
    sfFont *font;
    sfEvent event;
    sfClock *clock;
    sfClock *heart;
    sfMusic *song;
    sfTexture *hoover_text;
    sfSprite *hoover;
    char **map;
    int life;
    int money;
    bool strt_menu;
    bool death;
    bool pause;
    bool settings;
    bool from_strt;
    map_t *map_pars;
    int click_on_tower;
    int click_on_tower2;
    int click_on_tower3;
    int click_on_tower4;
    int line;
    char **case_pos;
    int wave;
    int nb_ene;
    int x;
    int tow_pos_x;
    int tow_pos_y;
    sfVector2f tower2;
    sfVector2f tower3;
    sfVector2f tower4;
    int open_book;
    int clicked;
}utils_t;

#endif /* !MAIN_STRUCT */
