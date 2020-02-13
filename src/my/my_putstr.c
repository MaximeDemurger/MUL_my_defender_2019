/*
** EPITECH PROJECT, 2019
** my putstr
** File description:
** my putstr
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}
