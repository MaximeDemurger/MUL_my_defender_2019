/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** enemys movements
*/

#include "my.h"

int next_status_diff(enemy_t *ene, path_t *next, path_t *current)
{
    if (ene->status == 1 || ene->status == 0) {
        if (next->pos.y != current->pos.y)
            return 1;
    }
    if (ene->status == 2 || ene->status == 3) {
        if (next->pos.x != current->pos.y)
            return 1;
    }
    return 0;
}

void do_y_move(enemy_t *ene, path_t *next, path_t *current)
{
    if (next->pos.x == current->pos.x && next->pos.y > current->pos.y) {
        ene->pos.y += 3;
        sfSprite_setRotation(ene->sprite, 90);
        ene->status = 2;
    }
    else if (next->pos.x == current->pos.x && next->pos.y < current->pos.y) {
        ene->pos.y -= 3;
        sfSprite_setRotation(ene->sprite, -90);
        ene->status = 3;
    }
}

void change_status(enemy_t *ene, path_t *current, path_t *next)
{
    if (next->pos.y == current->pos.y && next->pos.x > current->pos.x) {
        ene->pos.x += 3;
        sfSprite_setRotation(ene->sprite, 0);
        ene->status = 0;
    }
    else if (next->pos.y == current->pos.y && 
            next->pos.x < current->pos.x) {
        ene->pos.x -= 3;
        sfSprite_setRotation(ene->sprite, 270);
        ene->status = 1;
    }
    else
        do_y_move(ene, next, current);
}