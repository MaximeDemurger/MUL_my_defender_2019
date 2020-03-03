/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my strlen function
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0')
        i++;
    return i;
}