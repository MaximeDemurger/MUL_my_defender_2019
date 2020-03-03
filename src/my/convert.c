/*
** EPITECH PROJECT, 2018
** convert
** File description:
** converts ints to char *
*/

#include "my.h"

int int_len(int nb)
{
    int len = 0;

    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}

char *convert_to_string(int nb)
{
    char *string = malloc(sizeof(char) * int_len(nb) + 1);
    int i = 0;

    if (!string)
        return NULL;
    if (nb <= 0) {
        return ("0");
    }
    while (nb > 0) {
        string[i] = (nb % 10)  + 48;
        nb = nb/ 10;
        i++;
    }
    string[i] = '\0';
    return (my_revstr(string));
}
