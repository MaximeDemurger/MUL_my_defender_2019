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

void do_rotation(enemy_t *ene, int status, int next_stat, path_t *current)
{
    float angle = sfSprite_getRotation(ene->sprite);

        if (angle == 0 && status == 0 && next_stat == 2)
            sfSprite_setRotation(ene->sprite, 90);
        if (angle == 0 && status == 0 && next_stat == 3)
            sfSprite_setRotation(ene->sprite, -90);
        if (angle == 90 && status == 2 && next_stat == 0)
            sfSprite_setRotation(ene->sprite, 0);
        if (angle == 90 && status == 2 && next_stat == 1)
            sfSprite_setRotation(ene->sprite, 180);
        if (angle == 180 && status == 1 && next_stat == 2)
            sfSprite_setRotation(ene->sprite, -90);
        if (angle == 180 && status == 1 && next_stat == 3)
            sfSprite_setRotation(ene->sprite, 270);
        if (angle == 270 && status == 3 && next_stat == 0)
            sfSprite_setRotation(ene->sprite, 0);
        if (angle == 270 && status == 3 && next_stat == 1)
            sfSprite_setRotation(ene->sprite, 180);
}

void do_y_move(enemy_t *ene, path_t *next, path_t *current)
{
    if (next->pos.x == current->pos.x && next->pos.y > current->pos.y) {
        ene->pos.y += 3;
        do_rotation(ene, ene->status, 2, current);
        ene->status = 2;
    }
    else if (next->pos.x == current->pos.x && next->pos.y < current->pos.y) {
        ene->pos.y -= 3;
        do_rotation(ene, ene->status, 3, current);
        ene->status = 3;
    }
}

void change_status(enemy_t *ene, path_t *current, path_t *next)
{
    if (next->pos.y == current->pos.y && next->pos.x > current->pos.x) {
        ene->pos.x += 3;
        do_rotation(ene, ene->status, 0, current);
        ene->status = 0;
    }
    else if (next->pos.y == current->pos.y && 
            next->pos.x < current->pos.x) {
        ene->pos.x -= 3;
        do_rotation(ene, ene->status, 1, current);
        ene->status = 1;
    }
    else
        do_y_move(ene, next, current);
}