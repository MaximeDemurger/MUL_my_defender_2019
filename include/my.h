/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** my.h
*/

#ifndef PROTO
#define PROTO

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"
#include <stdbool.h>
#include "menu_struct.h"
#include "main_struct.h"

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

/* MAIN GAME */
void open_window(utils_t *, game_t *);

#endif /* !PROTO */
