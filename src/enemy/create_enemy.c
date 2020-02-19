/*
** EPITECH PROJECT, 2019
** create_enemy
** File description:
** linked list enemy
*/

#include "my.h"

int see_the_begining(int **map)
{
    int i = 0;

    while (i < 6) {
        if (map[i][0] == 'X')
            return i;
        i += 1;
    }
    return i;
}

sfSprite *create_sprite(sfVector2f position, sfTexture *text)
{
    sfSprite *s_sp = sfSprite_create();

    sfSprite_setPosition(s_sp, position);
    sfSprite_setTexture(s_sp, text, sfTrue);
    return s_sp;
}

enemy_t *put_enemy(enemy_t *list, utils_t *utils, path_t *path)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    sfTexture *text = sfTexture_createFromFile("image/tower1.png", NULL);

    if (!new)
        return NULL;
    new->life = 100;
    new->pos.x = path->pos.x;
    new->pos.y = (path->pos.y) + ((rand() % 50));
    new->sprite = create_sprite(new->pos, text);
    new->next = list;
    return new;
}

void enemy_wave(enemy_t **list, int nb, utils_t *utils, path_t *head)
{
    int i = 0;

    utils->wave += 1;
    utils->nb_ene = nb + (3 * (utils->wave - 1));
    while (i++ < nb + (3 * (utils->wave - 1))) {
        (*list) = put_enemy(*list, utils, head);
    }
}

