/*
** EPITECH PROJECT, 2018
** tab_lib.c
** File description:
** utils for lib
*/

#include <stdlib.h>
#include "lib.h"

void free_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

int tab_size(char **tab)
{
    int i = 0;

    if (!tab)
        return (0);
    for (; tab[i]; i++);
    return (i);
}

char **init_tab(int size)
{
    char **tab = malloc(sizeof(char *) * (size + 1));

    if (!tab)
        return (NULL);
    for (int i = 0; i < size + 1; i++)
        tab[i] = NULL;
    return (tab);
}

char **tab_copy(char **tab)
{
    int value = tab_size(tab);
    char **new_tab = malloc(sizeof(char *) * (value + 1));

    if (!new_tab)
        return (NULL);
    for (int i = 0; i < value + 1; i++)
        new_tab[i] = NULL;
    for (int i = 0; tab[i]; i++) {
        new_tab[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        if (!new_tab[i])
            return (NULL);
        my_strcpy(new_tab[i], tab[i]);
    }
    return (new_tab);
}
