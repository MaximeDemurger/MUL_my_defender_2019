/*
** EPITECH PROJECT, 2020
** init mpa
** File description:
** init map
*/

#include "map_struct.h"

void set_texture_map(map_t *map)
{
    sfSprite_setTexture(map->inventory, map->inventory_text, sfTrue);
    sfSprite_setTexture(map->grass, map->grass_text, sfTrue);
    sfSprite_setTexture(map->soil, map->soil_text, sfTrue);
    sfSprite_setTexture(map->tower_pos, map->tower_pos_text, sfTrue);
    sfSprite_setTexture(map->rock, map->rock_text, sfTrue);
    sfSprite_setTexture(map->basement, map->basement_text, sfTrue);
}

int init_map(map_t *map)
{
    map->grass_text = sfTexture_createFromFile("image/grass.png", NULL);
    map->soil_text = sfTexture_createFromFile("image/soil.jpg", NULL);
    map->tower_pos_text = sfTexture_createFromFile("image/tower_pos.png", NULL);
    map->rock_text = sfTexture_createFromFile("image/stone.png", NULL);
    map->inventory_text = sfTexture_createFromFile("image/inventory.png", NULL);
    map->inventory = sfSprite_create();
    map->grass = sfSprite_create();
    map->soil = sfSprite_create();
    map->tower_pos = sfSprite_create();
    map->rock = sfSprite_create();
    map->basement_text = sfTexture_createFromFile("image/basement.png", NULL);
    map->basement = sfSprite_create();
    if (!map->rock || !map->soil || !map->tower_pos || !map->grass ||
    !map->inventory || !map->inventory_text || !map->rock_text ||
    !map->tower_pos_text || !map->soil_text || !map->grass_text)
        return 84;
    set_texture_map(map);
    return 0;
}