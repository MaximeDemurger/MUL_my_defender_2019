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
#include "map_struct.h"
#include "menu_struct.h"
#include "main_struct.h"

#ifndef READ_SIZE
#define READ_SIZE 4096
#endif

/* MENU */
int init_start(strtmenu_t *, pausemenu_t *);
int init_death(deathmenu_t *);
void death_menu(utils_t *, deathmenu_t *);
void starting_menu(utils_t *, strtmenu_t *);
void pause_menu(utils_t *, pausemenu_t *);

/* DESTROY */
void destroy_game(game_t *);
void destroy_menu(strtmenu_t *, pausemenu_t *);

/* MY LIB*/
void my_putstr(char const *);
void my_putchar(char);
char *convert_to_string(int);
int my_strlen(char const *str); 
char *my_revstr(char *);
char *my_strdup(char const *str);
char *get_next_line(int fd);

/* MAIN GAME */
void open_window(utils_t *, game_t *, char **av);
void capture_events(utils_t *, game_t *);

/* MAP GAME */
void init_map(map_t *map);
int map_parsing(utils_t *utils, char **av);
int checking_map(char const *str);

#endif /* !PROTO */
