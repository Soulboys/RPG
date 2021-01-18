/*
** EPITECH PROJECT, 2018
** math.c
** File description:
** math function
*/

int my_pow(int nb, int p)
{
    int result = 0;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = nb * my_pow(nb, p - 1);
    return (result);
}

int my_sqrt(int nb)
{
    int i = 1;

    for (; i * i < nb; i++)
        if (i * i > nb)
            return (i - 1);
    return (i);
}
