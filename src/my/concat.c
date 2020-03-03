/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** concat name
*/

#include "my.h"

char *concat(char *fst_str, char *scd_str)
{
    char *dest = malloc(sizeof(char) *
                (my_strlen(fst_str) + my_strlen(scd_str)) + 1);
    int count = 0;
    int index = 0;

    while (fst_str[count] != '\0') {
        dest[index] = fst_str[count];
        index++;
        count++;
    }
    count = 0;
    dest[index++] = '/';
    while (scd_str[count] != '\0') {
        dest[index] = scd_str[count];
        index++;
        count++;
    }
    dest[index] = '\0';
    return (dest);
}