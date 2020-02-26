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

int is_in_middle(enemy_t *ene, path_t *current, int status)
{
    if (status == 1 || status == 0) {
        if (ene->pos.x >= current->pos.x + 45 &&
            ene->pos.x <= current->pos.x + 80) {
            return 1;
        }
    }
    if (status == 2 || status == 3) {
        if (ene->pos.y >= current->pos.y + 60 &&
            ene->pos.y <= current->pos.y + 80) {
            return 1;
        }
    }
    return 0;
}

void normal_move(enemy_t *ene)
{
    if (ene->status == 0)
        ene->pos.x += 3;
    if (ene->status == 1)
        ene->pos.x -= 3;
    if (ene->status == 2)
        ene->pos.y += 3;
    if (ene->status == 3)
        ene->pos.y -= 3;
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
        if (next_status_diff(ene, next, current)) {
            if (is_in_middle(ene, current, ene->status))
                change_status(ene, current, next);
            else
                normal_move(ene);
        }
        else
            normal_move(ene);
        sfSprite_setPosition(ene->sprite, ene->pos);
        sfRenderWindow_drawSprite(utils->window, ene->sprite, NULL);
        ene = ene->next;
    }
}