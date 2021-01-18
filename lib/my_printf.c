/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <unistd.h>
#include "lib.h"

static const print_t PRINT[3] = {
    {'c', &count_putchar}, {'s', &count_putstr}, {'d', &count_putnbr},
};

int count_putchar(va_list to_print)
{
    char c = va_arg(to_print, int);

    return (write(1, &c, 1), 1);
}

int count_putstr(va_list to_print)
{
    int i = 0;
    char *str = va_arg(to_print, char *);

    for (; str[i]; i++);
    return (write(1, str, i), i - 1);
}

int count_putnbr(va_list to_print)
{
    long long int nb = va_arg(to_print, long long int);

    my_put_nbr(nb);
    return (get_int_size(nb));
}

int type(char var)
{
    int i = 0;

    for (; PRINT[i].type != var; i++);
    return (i);
}

int my_printf(char *str, ...)
{
    va_list to_print;
    long long int printed = 0;

    va_start(to_print, str);
    for (int i = 0; str[i]; i++)
        if (str[i] == '%' && str[i + 1] != '%') {
            printed += PRINT[type(str[i + 1])].function(to_print);
            i++;
        } else
            printed += my_putchar(str[i]);
    va_end(to_print);
    return (printed);
}
