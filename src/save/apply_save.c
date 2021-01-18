/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

static int apply_saved_stat(info_t *i, rpg_t *rpg, int k)
{
    for (int j = 0; j < 2; j++)
        i->scene[1 + j] = i->saved_stat[k][j];
    PLAYER->player_sp.pos.x = i->saved_stat[k][2];
    PLAYER->player_sp.pos.y = i->saved_stat[k][3];
    PLAYER->player_sp.map_pos[0] = (float)i->saved_stat[k][4];
    PLAYER->player_sp.map_pos[1] = (float)i->saved_stat[k][5];
    for (int j = 0; j < 5; j++)
        PLAYER->player_sp.statistic[j] = i->saved_stat[k][6 + j];
    rpg->npc[0]->c.pos.x = i->saved_stat[k][11];
    rpg->npc[0]->c.pos.y = i->saved_stat[k][12];
    ITEM->open[0] = i->saved_stat[k][13];
    for (int j = 0; j < 4; j++)
        ITEM->possesses[j][0] = i->saved_stat[k][14 + j];
    return (SUCCESS);
}

int apply_save(info_t *i, rpg_t *rpg, int k)
{
    const char *str = NULL;

    sfMusic_setLoop(rpg->opt->music[0], sfTrue);
    sfMusic_stop(OPT->music[1]);
    sfMusic_play(rpg->opt->music[0]);
    if (k > 2 || apply_saved_stat(i, rpg, k))
        return (SUCCESS);
    for (int z = 0; z < 3; z++)
        sfSprite_setScale(PLAYER->heart[z]->sprite, (VF){5, 3.21});
    sfSprite_setScale(PLAYER->player_sp.sprite, (VF){2, 2});
    str = sfText_getString(MENU->player_name[k]->text);
    rpg->player_name = my_strcpy(rpg->player_name, str);
    i->num_of_scene = k;
    sfView_destroy(i->view[3]);
    i->view[3] = sfView_createFromRect((sfFloatRect){0, 0, 1280, 720});
    if (!i->view[3])
        return (ERROR);
    sfView_move(i->view[3], (VF){-640 + PLAYER->player_sp.pos.x,
        -360 + PLAYER->player_sp.pos.y});
    return (!rpg->player_name ? ERROR: SUCCESS);
}

int init_saves(info_t *info, rpg_t *rpg, char **tab)
{
    char **name = init_tab(3);
    char **saves = read_dir(&name, NULL, 0);

    for (int i = 0, value = 0; saves && saves[i]; i++, free_tab(tab)) {
        if (!(tab = str_to_array(saves[i], '\n')))
            return (ERROR);
        if ((value = decrypt_save(tab, info, i)) == ERROR)
            return (ERROR);
        info->save[i] = !value ? 1: 0;
    }
    free_tab(saves);
    for (int i = 0, j = 0; rpg->menu->player_name && name[i]; i++, j = 0) {
        for (; rpg->menu->player_name && name[i][j] && name[i][j] != '.'; j++);
        name[i][j] = '\0';
        rpg->menu->player_name = info->save[i] ?
        add_name(info, rpg, &name[i], 0): rpg->menu->player_name;
    }
    free_tab(name);
    return (rpg->menu->player_name ? SUCCESS: ERROR);
}
