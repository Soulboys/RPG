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

static int check_orientation(sfEvent event, char **map, short pos[2], int or[2])
{
    if (event.key.code == sfKeyO && event.type == sfEvtKeyReleased) {
        if ((map[pos[0] + 1][pos[1]] == or[1] && or[0] == DOWN)
            || (map[pos[0] - 1][pos[1]] == or[1] && or[0] == UP)
            || (map[pos[0]][pos[1] + 1] == or[1] && or[0] == RIGHT)
            || (map[pos[0]][pos[1] - 1] == or[1] && or[0] == LEFT))
            return (1);
    }
    return (0);
}

int link_house_event(sfEvent event, info_t *info, rpg_t *rpg)
{
    if (event.key.code == sfKeyEnter && event.type == sfEvtKeyReleased
        && SCENE(2) == GF_SPEECH) {
        SCENE(2) = SPEECH->rec.statistic[0] == 1 ? GF_MOVE: GF_SPEECH;
        SPEECH->skip[0] = SPEECH->rec.statistic[0] == 0 ? 1: 1;
    } else {
        ITEM->open[0] = ITEM->open[0] == 0 ?
        check_orientation(event, rpg->house[1]->map,
            (short[2]){(int)PLAYER->player_sp.map_pos[0],
            (int)PLAYER->player_sp.map_pos[1]},
            (int[2]){STAT(0), 'C'}): 1;
        restart_clock(info, 1);
    }
    return (SUCCESS);
}

int none_house_event(sfEvent event, info_t *info, rpg_t *rpg)
{
    if (event.key.code == sfKeyO && event.type == sfEvtKeyReleased
        && check_orientation(event, rpg->house[0]->map,
        (short[2]){(int)PLAYER->player_sp.map_pos[0],
        (int)PLAYER->player_sp.map_pos[1]}, (int[2]){STAT(0), 'O'})) {
        if (SCENE(2) == GF_DIE_EQUIPED)
            SCENE(2) = GF_DIE_SPEECH;
        else if (SCENE(2) == GF_DIE_UNEQUIPED && rpg->enemy->killed == 5)
            SCENE(2) = BUY;
    }
    if (event.key.code == sfKeyEnter && event.type == sfEvtKeyReleased) {
        if (SPEECH->skip[SCENE(2) == GF_DIE_SPEECH ? 1: 2] == 1)
            SCENE(2) = GF_DIE_UNEQUIPED;
        SPEECH->skip[SCENE(2) == GF_DIE_SPEECH ? 1: 2] = 1;
    }
    return (SUCCESS);
}
