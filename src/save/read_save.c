/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

char *read_save(char *file)
{
    FILE *fd = fopen(file, "r");
    char *line = NULL;
    char *str = NULL;
    char *tmp = NULL;
    size_t length = 0;

    if (!fd)
        return (my_perror("Error opening %s\n", file), NULL);
    while (getline(&line, &length, fd) != -1) {
        tmp = str;
        str = my_strcat(line, str);
        my_free(tmp);
    }
    my_free(line);
    fclose(fd);
    return (str);
}

char **read_dir(char ***tab, char *str, int i)
{
    DIR *dir = opendir("res/save/");
    char **save = malloc(sizeof(char *) * 4);

    if (!dir || !save || !(*tab))
        return (my_free(save), NULL);
    for (struct dirent *dirent = readdir(dir); dirent
        && i < 3; dirent = readdir(dir)) {
        if (dirent->d_name[0] == '.' || my_strcmp(dirent->d_name
            + (my_strlen(dirent->d_name) - 5), ".save"))
            continue;
        (*tab)[i] = my_strcpy((*tab)[i], dirent->d_name);
        if (!(str = my_strcat(dirent->d_name, "res/save/")))
            return (NULL);
        save[i] = read_save(str);
        free(str);
        if (!save[i])
            return (closedir(dir), free(save), NULL);
        i++;
    }
    return (closedir(dir), save[i] = NULL, (*tab)[i] = NULL, save);
}
