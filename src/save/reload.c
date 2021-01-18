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

int reload(rpg_t *rpg, info_t *info)
{
    destroy_player(PLAYER);
    destroy_npc(rpg->npc);
    destroy_item(ITEM);
    if (!(PLAYER = init_player_struct(info->texture))
        || !(rpg->npc = init_npc(info->texture))
        || !(ITEM = init_item(info->texture)))
        return (ERROR);
    SCENE(1) = LINK_HOUSE;
    SCENE(2) = GF_SPEECH;
    return (SUCCESS);
}
