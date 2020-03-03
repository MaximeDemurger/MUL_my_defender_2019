/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** enemy hit
*/

#include "my.h"

enemy_t *kill_enemy(enemy_t *ene)
{
    enemy_t *tmp = ene;

    sfSprite_destroy(ene->sprite);
    free(tmp);
    ene = ene->next;
    return ene;
}

enemy_t *enemy_hit(enemy_t *ene, int damage)
{
    if (!ene)
        return NULL;
    ene->life -= damage;
    if (ene->life <= 0)
        ene = kill_enemy(ene);
    return ene;
}