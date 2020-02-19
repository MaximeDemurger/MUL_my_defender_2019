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

void do_y_move(enemy_t *ene, path_t *next, path_t *current)
{
    if (next->pos.x == current->pos.x && next->pos.y > current->pos.y)
        ene->pos.y += 3;
    else if (next->pos.x == current->pos.x && next->pos.y < current->pos.y)
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
    if (next->pos.y == current->pos.y && next->pos.x > current->pos.x)
        ene->pos.x += 3;
    else if (next->pos.y == current->pos.y && next->pos.x < current->pos.x)
        ene->pos.x -= 3;
    else 
        do_y_move(ene, next, current);
    sfSprite_setPosition(ene->sprite, ene->pos);
    sfRenderWindow_drawSprite(utils->window, ene->sprite, NULL);
    ene = ene->next;
    }
}