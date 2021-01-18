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

static int my_isnb(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (ERROR);
    return (SUCCESS);
}

static int apply_to_game(int(*stat)[18], int i, char *str)
{
    int nb;

    if (my_isnb(str))
        return (ERROR);
    nb = my_getnbr(str);
    (*stat)[i] = nb;
    return (SUCCESS);
}

int decrypt_save(char **save, info_t *info, int lines)
{
    char **stat = NULL;

    if (tab_size(save) != 18)
        return (my_perror("Save not good formatted\n"), 1);
    for (int i = 0; save[i]; i++, free_tab(stat)) {
        stat = str_to_array(save[i], ':');
        if (!stat)
            return (ERROR);
        if (tab_size(stat) != 2 || apply_to_game(&info->saved_stat[lines],
            i, stat[1]))
            return (my_perror("Save not good formatted\n"), free_tab(stat), 1);
    }
    return (SUCCESS);
}
