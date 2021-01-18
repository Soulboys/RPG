/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

int loop(info_t *info, rpg_t *rpg)
{
    sfMusic_setVolume(rpg->opt->music[1], (float)(rpg->opt->value[0]));
    sfMusic_setLoop(rpg->opt->music[1], sfTrue);
    sfMusic_play(rpg->opt->music[1]);
    while (sfRenderWindow_isOpen(info->win)) {
        restart_clock(info, 5000000);
        if (event_panel(info, rpg))
            return (ERROR);
        sfMusic_setVolume(rpg->opt->music[0], (float)(rpg->opt->value[0]));
        sfRenderWindow_setView(info->win, info->view[info->scene[0]]);
        sfRenderWindow_clear(info->win, sfBlack);
        disp_scene(info, rpg);
        sfRenderWindow_display(info->win);
    }
    return (SUCCESS);
}
