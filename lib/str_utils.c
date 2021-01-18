/*
** EPITECH PROJECT, 2018
** str_utils.c
** File description:
** utils for str
*/

#include <stdlib.h>
#include "lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i]; i++);
    return (i);
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    if (!src)
        return (NULL);
    if (!dest) {
        dest = malloc(sizeof(char) * (my_strlen(src) + 1));
        if (!dest)
            return (NULL);
    }
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i]= '\0';
    return (dest);
}

char *my_revstr(char *str)
{
    int x = my_strlen(str) - 1;
    char y;

    for (int i = 0; i < x; i++, x--) {
        y = str[i];
        str[i] = str[x];
        str[x] = y;
    }
    return (str);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (1);
    for (int i = 0; s1[i] && s2[i]; i++)
        if (s1[i] > s2[i])
            return (1);
        else if (s1[i] < s2[i])
            return (-1);
    if (my_strlen(s1) > my_strlen(s2))
        return (1);
    else if (my_strlen(s1) < my_strlen(s2))
        return (-1);
    return (0);
}

char *my_strcat(char *to_join, char *str)
{
    char *new = NULL;
    int i = 0;
    int j = 0;

    if (!to_join)
        return (str);
    new = malloc(sizeof(char) * (my_strlen(to_join) + my_strlen(str) + 3));
    if (!new)
        return (NULL);
    if (str)
        for (; str[i]; i++)
            new[i] = str[i];
    for (; to_join[j]; j++)
        new[i + j] = to_join[j];
    new[i + j] = '\0';
    return (new);
}
