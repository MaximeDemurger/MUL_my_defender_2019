/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    char *dest = NULL;
    int i = 0;

    if (str == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!dest)
        return NULL;
    while (str[i] != 0) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}