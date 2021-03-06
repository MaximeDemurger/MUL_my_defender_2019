/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** attack castle
*/

#include "my.h"

int enemys_left(enemy_t *ene)
{
    enemy_t *tmp = ene;
    int count = 0;

    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count * 5;
}

void clear_enemys(enemy_t **ene)
{
    enemy_t *free_ene;

    while (*ene) {
        free_ene = *ene;
        sfSprite_destroy((*ene)->sprite);
        (*ene) = (*ene)->next;
        free(free_ene);
    }
}

void attack_castle(enemy_t **ene, utils_t *utils)
{
    if (*ene) {
        if ((*ene)->pos.x > 1770) {
            utils->life -= enemys_left(*ene);
            clear_enemys(ene);
        }
    }
}