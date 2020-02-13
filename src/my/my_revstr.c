/*
** EPITECH PROJECT, 2019
** my evil str
** File description:
** my evil str
*/

#include <stdio.h>

int my_len(char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int start = 0;
    int end = 0;
    char tempo;

    if (!str)
        return NULL;
    end = my_len(str) - 1;
    while (start < end) {
        tempo = str[start];
        str[start] = str[end];
        str[end] = tempo;
        end--;
        start++;
    }
    return str;
}
