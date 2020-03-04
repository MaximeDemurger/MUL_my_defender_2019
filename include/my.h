/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** my.h
*/

#ifndef PROTO
#define PROTO

#include <unistd.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "play_struct.h"
#include "map_struct.h"
#include "menu_struct.h"
#include "main_struct.h"
#include "hud.h"
#include "enemi.h"

#ifndef READ_SIZE
#define READ_SIZE 4096
#endif


/* MENU */
int init_start(strtmenu_t *, pausemenu_t *);
int init_death(deathmenu_t *);
int init_settings(settings_t *);
void settings_menu(utils_t *, settings_t *);
void death_menu(utils_t *, deathmenu_t *);
void starting_menu(utils_t *, strtmenu_t *);
void pause_menu(utils_t *, pausemenu_t *);
int init_select(selection_t *);
char *show_map_options(utils_t *, selection_t *, all_map_t *);
void do_select_hoover(utils_t *);

/* DESTROY */
void destroy_game(game_t *);
void destroy_menu(strtmenu_t *, pausemenu_t *);
void destroy_settings(settings_t *);
void destroy_select(selection_t *);
void destroy_death(deathmenu_t *);
void destroy_path(path_t *);
void destroy_allmaps(all_map_t *);

/* MY LIB*/
int my_atoi(char const *stack);
int my_putstr(char const *);
int my_putchar(char);
char *convert_to_string(int);
int my_strlen(char const *str); 
char *my_revstr(char *);
char *my_strdup(char const *str);
char *get_next_line(int fd);
char *concat(char *, char *);

/* MAIN GAME */
int open_window(utils_t *, game_t *, char **av);
void capture_events(utils_t *, game_t *, char **tab);
int check_pos(game_t *game, int mouse_x, int mouse_y, char **tab);


/* MAP GAME */
char **gettingMap_fromFile(char *);
int init_map(map_t *map);
void printing_map(char **tab, utils_t *utils);
char **normal_map(void);
int checking_map(char const *str);
int print_basement(char **tab, utils_t *utils, map_t *map);
int get_maps(all_map_t **, char *);

/* GAME */
int get_pos_case(utils_t *utils, char **map);
int init_play(play_t *play);
int result_case_good1(game_t *game, int line, int col, char **tab);
int result_case_good2(game_t *game, int line, int col, char **tab);
int result_case_good3(game_t *game, int line, int col, char **tab);
int result_case_good4(game_t *game, int line, int col, char **tab);
int check_mouse_case(int mouse_x, int mouse_y, utils_t *utils);
void find_line_col(utils_t *utils, int *line, int *col);
void gameplay(game_t *game, path_t *, char **map);
void range_tower(game_t *game, sfVector2f set_tow);
void tower_onset(game_t *game, sfVector2f pos, sfVector2f set_tow);
void tower_shot(game_t *game);
void put_tower1(game_t *game, sfVector2f pos, sfVector2f mouse);
void put_tower2(game_t *game, sfVector2f mouse);
void put_tower3(game_t *game, sfVector2f mouse);
void put_tower4(game_t *game, sfVector2f mouse);

/* ENEMY */
void enemy_wave(enemy_t **, int, utils_t *, path_t *);
void pathfinding(enemy_t *, path_t *, utils_t *);
enemy_t *enemy_hit(enemy_t *ene, int damage);
path_t *get_path(char **);
void attack_castle(enemy_t **, utils_t *);
int next_status_diff(enemy_t *, path_t *, path_t *);
void change_status(enemy_t *, path_t *, path_t *);

/* HUD */
int init_hud(hud_t *);
void draw_hud(hud_t *, utils_t *);

#endif /* !PROTO */
