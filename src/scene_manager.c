/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

static const scene_t SCENE[] = {
    {INTRO, &disp_intro}, {CREATE, &disp_create}, {SELECT, &disp_select},
    {GAME, &disp_game}, {PAUSE, &disp_pause}, {OPTION, &display_opt_menu},
    {HELP, &display_help}
};

void disp_scene(info_t *info, rpg_t *rpg)
{
    for (int i = 0; i < 7; i++)
        if (SCENE[i].scene == info->scene[0])
            SCENE[i].function(info, rpg);
}
