/*
** EPITECH PROJECT, 2020
** struct map
** File description:
** map struct
*/

#ifndef MAP_STRUCT_
#define MAP_STRUCT_

#include "SFML/Window.h"
#include "SFML/Graphics.h"
#include "SFML/System/Export.h"
#include "SFML/System/Time.h"
#include "SFML/System/Types.h"

typedef struct map_s {
    sfTexture *grass_text;
    sfTexture *soil_text;
    sfTexture *rock_text;
    sfTexture *inventory_text;
    sfSprite *inventory;
    sfSprite *rock;
    sfSprite *grass;
    sfSprite *soil;
    sfTexture *tower_pos_text;
    sfSprite *tower_pos;
    sfTexture *basement_text;
    sfSprite *basement;
} map_t;

typedef struct all_maps {
    char *filename;
    struct all_maps *next;
} all_map_t;


#endif /* !MAP_STRUCT_ */
