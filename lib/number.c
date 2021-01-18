/*
** EPITECH PROJECT, 2018
** number.c
** File description:
** function returns a value
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int minus = 1;

    for (int i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            minus = minus * -1;
    for (int i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        }
    return (nb * minus);
}

int get_int_size(int nb)
{
    int counter = 0;

    if (nb == 0)
        return (1);
    while (nb > 0) {
        counter++;
        nb = nb / 10;
    }
    return (counter);
}

char *int_to_str(int nb)
{
    char *dest = 0;
    int pos = 0;

    dest = malloc(sizeof(char) *(12));
    if (nb < 0) {
        nb *= -1;
        dest[pos] = '-';
        pos++;
    }
    while (nb > 9) {
        dest[pos] = nb % 10 + '0';
        nb /= 10;
        pos++;
    }
    dest[pos] = nb + '0';
    dest[pos + 1] = '\0';
    return (dest);
}
