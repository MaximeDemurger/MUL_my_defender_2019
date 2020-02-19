/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** enemi
*/

#ifndef ENEMI
#define ENEMI

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>

typedef struct enemy_s {
    sfSprite *sprite;
    sfVector2f pos;
    int life;
    struct enemy_s *next;
}enemy_t;

typedef struct path_s {
    sfVector2f pos;
    struct path_s *next;
} path_t;

#endif /* !ENEMI */
