/*
** EPITECH PROJECT, 2020
** init mpa
** File description:
** init map
*/

#include "map_struct.h"

void init_map(map_t *map)
{
    map->grass_text = sfTexture_createFromFile("image/grass.png", NULL);
    map->soil_text = sfTexture_createFromFile("image/soil.jpg", NULL);
    map->tower_pos_text = sfTexture_createFromFile("image/tower_pos.png", NULL);
    map->grass = sfSprite_create();
    map->soil = sfSprite_create();
    map->tower_pos = sfSprite_create();
    sfSprite_setTexture(map->grass, map->grass_text, sfTrue);
    sfSprite_setTexture(map->soil, map->soil_text, sfTrue);
    sfSprite_setTexture(map->tower_pos, map->tower_pos_text, sfTrue);
}