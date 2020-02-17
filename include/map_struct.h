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
    sfSprite *grass;
    sfSprite *soil;
    int x;
    int y;
} map_t;


#endif /* !MAP_STRUCT_ */
