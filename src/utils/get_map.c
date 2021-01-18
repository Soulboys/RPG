/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

char *get_str(char *file)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    char *str = NULL;
    size_t length = 0;

    if (!fd) {
        write(2, "Error opening\n", 14);
        return (NULL);
    }
    for (char *tmp = NULL; getline(&line, &length, fd) != -1; free(tmp)) {
        if (!line)
            return (NULL);
        tmp = str;
        str = my_strcat(line, tmp);
        if (!str)
            return (NULL);
    }
    fclose(fd);
    free(line);
    return (str);
}

char **get_map(char *file)
{
    char *str = get_str(file);
    char **array = NULL;
    int size = 0;

    if (!str)
        return (NULL);
    array = str_to_array(str, '\n');
    free(str);
    if (!array)
        return (NULL);
    size = tab_size(array) - 1;
    if (size > -1 && !my_strcmp(array[size], "\0")) {
        free(array[size]);
        array[size] = NULL;
    }
    return (array);
}
