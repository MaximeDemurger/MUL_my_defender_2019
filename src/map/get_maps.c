/*
** EPITECH PROJECT, 2020
** my defender
** File description:
** get all maps
*/

#include "my.h"

all_map_t *add_map(all_map_t *elem, char const *filepath)
{
    all_map_t *tmp = malloc(sizeof(all_map_t));

    if (!tmp)
        return NULL;
    tmp->filename = my_strdup(filepath);
    tmp->next = elem;
    return tmp;
}

int get_maps(all_map_t *all_maps, char const *dir_name)
{
    DIR *fd;
    struct dirent *files;

    if (!dir_name)
        return 1;
    if ((fd = opendir(dir_name)) == NULL)
        return 1;
    while ((files = readdir(fd)) != NULL) {
        if (files->d_name[0] != '.') {
            all_maps = add_map(all_maps, concat(dir_name, files->d_name));
        }
    }
    return 1;
}