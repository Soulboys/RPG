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

static const key_move_t MOVE[5] = {
    {sfKeyDown, 0, 1, DOWN}, {sfKeyRight, 1, 0, RIGHT},
    {sfKeyLeft, -1, 0, LEFT}, {sfKeyUp, 0, -1, UP}, {sfKeySpace, 0, 0, 0}
};

static void inv_move_event(rpg_t *rpg, int i)
{
    if (ITEM->inventory[1].statistic[1] + MOVE[i].x < 4
        && ITEM->inventory[1].statistic[1] + MOVE[i].x > -1) {
        ITEM->inventory[1].statistic[1] += MOVE[i].x;
        REC.pos.x += MOVE[i].x * 160;
    }
    if (ITEM->inventory[1].statistic[2] + MOVE[i].y < 5
        && ITEM->inventory[1].statistic[2] + MOVE[i].y > -1) {
        ITEM->inventory[1].statistic[2] += MOVE[i].y;
        if (ITEM->inventory[1].statistic[2] == 3)
            REC.pos.y = 400;
        else if (ITEM->inventory[1].statistic[2] == 2)
            REC.pos.y = 2 * 96;
        else
            REC.pos.y += MOVE[i].y * 96;
    }
}

int inventory_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    int i = 0;

    if (event.key.code == sfKeyY && event.type == sfEvtKeyReleased) {
        info->scene[3] = info->scene[3] ? 0: 1;
        if (info->scene[3]) {
            ITEM->inventory[0].pos.y = 720;
            REC.pos.y = 720;
        }
        for (int i = 0; info->scene[3] && i < 3; i++)
            ITEM->item[i].pos.y = 720;
    }
    for (int i = 0; i < 4; i++)
        if (sfKeyboard_isKeyPressed(sfKeyEnter) && SCENE(3) == 1 &&
            ITEM->inventory[1].statistic[1] == i && ITEM->possesses[i][0])
            rpg->item->select = i;
    for (; i < 5 && event.key.code != MOVE[i].key; i++);
    if (i == 5 || event.type != sfEvtKeyReleased)
        return (SUCCESS);
    if (info->scene[3])
        inv_move_event(rpg, i);
    return (SUCCESS);
}
