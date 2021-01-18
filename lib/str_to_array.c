/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** main.c
*/

#include <stdlib.h>
#include "lib.h"

static int get_nb_of_line(char *str, char var)
{
    int size = 0;

    for (int i = 0; str[i]; i++)
        size += (str[i] == var) ? 1: 0;
    return (size + 1);
}

char *my_malloc_array(char *str, char *array, char var, int counter)
{
    for (; str[counter] != var && str[counter] != '\0'; counter++);
    array = malloc(sizeof(char) * (counter + 1));
    return (array);
}

char **str_to_array(char *str, char var)
{
    int size = get_nb_of_line(str, var);
    char **array = malloc(sizeof(char *) * (size + 1));
    int line = 0;
    int character = 0;

    for (int i = 0; i < size + 1; i++)
        array[i] = NULL;
    array[line] = my_malloc_array(str, array[line], var, 0);
    for (int i = 0; str[i]; i++, character++) {
        if (str[i] == var) {
            array[line][character] = '\0';
            line++;
            character = -1;
            array[line] = my_malloc_array(str, array[line], var, i + 1);
        } else
            array[line][character] = str[i];
    }
    array[line][character] = '\0';
    return (array);
}
