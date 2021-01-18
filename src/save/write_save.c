/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

int add_to_write(char *name, int nb, int fd, int last)
{
    char *new = my_revstr(int_to_str(nb));
    char *str = NULL;
    char *tmp = NULL;

    if (!new)
        return (ERROR);
    str = my_strcat(":", name);
    tmp = my_strcat(new, str);
    my_free(str);
    my_free(new);
    if (!last) {
        str = my_strcat("\n", tmp);
        my_free(tmp);
    } else
        str = tmp;
    if (!str)
        return (ERROR);
    write(fd, str, my_strlen(str));
    return (my_free(str), SUCCESS);
}

int affect_other_save(rpg_t *rpg, int fd)
{
    for (int i = 0; i < 5; i++)
        if (add_to_write("stat", rpg->player->player_sp.statistic[i], fd, 0))
            return (ERROR);
    if (add_to_write("npc[0]pos[0]", rpg->npc[0]->c.pos.x, fd, 0)
        || add_to_write("npc[0]pos[1]", rpg->npc[0]->c.pos.y, fd, 0)
        || add_to_write("opened[0]", ITEM->open[0], fd, 0))
        return (ERROR);
    for (int i = 0; i < 4; i++)
        if (add_to_write("possesses", ITEM->possesses[i][0], fd, i == 3 ? 1: 0))
            return (ERROR);
    return (SUCCESS);
}

int affect_to_save(rpg_t *rpg, int fd, info_t *info)
{
    if (add_to_write("scene[1]", info->scene[1], fd, 0)
        || add_to_write("scene[2]", info->scene[2], fd, 0)
        || add_to_write("pos[0]", rpg->player->player_sp.pos.x, fd, 0)
        || add_to_write("pos[1]", rpg->player->player_sp.pos.y, fd, 0)
        || add_to_write("mpos[0]", (int)PLAYER->player_sp.map_pos[0], fd, 0)
        || add_to_write("mpos[1]", (int)PLAYER->player_sp.map_pos[1], fd, 0)
        || affect_other_save(rpg, fd))
        return (ERROR);
    return (SUCCESS);
}

int write_save(rpg_t *rpg, char *name, info_t *info)
{
    char *tmp = NULL;
    char *str = NULL;
    int fd;

    if (!name)
        return (SUCCESS);
    tmp = my_strcat(name, "res/save/");
    if (!tmp)
        return (ERROR);
    str = my_strcat(".save", tmp);
    if (!str)
        return (ERROR);
    fd = open(str, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd == -1)
        return (ERROR);
    affect_to_save(rpg, fd, info);
    close(fd);
    return (free(str), free(tmp), SUCCESS);
}
