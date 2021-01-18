/*
** EPITECH PROJECT, 2018
** put.c
** File description:
** functions that displays
*/

#include <unistd.h>
#include "lib.h"

int my_putchar(char c)
{
    return (write(1, &c, 1), 1);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}

void my_put_nbr(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9 || nb < -9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar('0' + nb);
}

char *my_strlowcase(char *str)
{
    for (int loop = 0; str[loop]; loop++)
        if (str[loop] >= 'A' && str[loop] <= 'Z')
            str[loop] += 32;
    return (str);
}
