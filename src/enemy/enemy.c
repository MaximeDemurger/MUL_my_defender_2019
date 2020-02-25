/*
** EPITECH PROJECT, 2019
** enemy
** File description:
** gestion of enemy
*/

#include "my.h"

path_t *get_current(enemy_t *ene, path_t *head)
{
    path_t *tmp = head;

    while (tmp) {
        if (ene->pos.x >= tmp->pos.x &&
            ene->pos.x <= tmp->pos.x + 128 &&
            ene->pos.y >= tmp->pos.y &&
            ene->pos.y <= tmp->pos.y + 135)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void do_rotation(enemy_t *ene, int status, int next_stat, path_t *current)
{
    float angle = sfSprite_getRotation(ene->sprite);

    if (is_in_middle(ene, current, status)) {
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
}

int is_in_middle(enemy_t *ene, path_t *current, int status)
{
    if (status == 1 || status == 0) {
        if (ene->pos.x >= current->pos.x + 45 &&
            ene->pos.x <= current->pos.x + 80) {
            printf("oui\n");
            return 1;
        }
    }
    if (status == 2 || status == 3) {
        if (ene->pos.y >= current->pos.y + 60 &&
            ene->pos.y <= current->pos.y + 80) {
            printf("non\n");
            return 1;
        }
    }
    return 0;
}

void do_y_move(enemy_t *ene, path_t *next, path_t *current)
{
    if (next->pos.x + 67 == current->pos.x + 67 && next->pos.y > current->pos.y) {
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

void pathfinding(enemy_t *ene, path_t *head, utils_t *utils)
{
    path_t *current;
    path_t *next;

    if (!ene)
        return;
    current = get_current(ene, head);
    next = current->next;
    while (ene) {
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
        sfSprite_setPosition(ene->sprite, ene->pos);
        sfRenderWindow_drawSprite(utils->window, ene->sprite, NULL);
        //printf("%f\n", sfSprite_getRotation(ene->sprite));
        ene = ene->next;
    }
}