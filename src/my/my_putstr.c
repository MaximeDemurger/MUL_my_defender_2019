/*
** EPITECH PROJECT, 2019
** my putstr
** File description:
** my putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i]) {
        if (my_putchar(str[i]))
            return 84;
        i++;
    }
    return 0;
}
