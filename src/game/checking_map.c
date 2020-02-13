/*
** EPITECH PROJECT, 2020
** checking map
** File description:
** checking map file
*/

int checking_map(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (str[i] != 'O' || str[i] != 'X' || str[i] != '\n')
            return 1;
        i++;
    }
    return 0;
}