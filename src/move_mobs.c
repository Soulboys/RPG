/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "lib.h"
#include "define.h"
#include "prototype.h"

int move_mobs(sprite_t *mob, float speed, int max, int utils[3])
{
    if (!utils[1]) {
        mob->pos.x += speed;
        mob->map_pos[1] += speed / 8;
    } else {
        mob->pos.y += speed;
        mob->map_pos[0] += speed / 10.5;
    }
    if (mob->rec.left > max || mob->rec.left < utils[0])
        mob->rec.left = utils[0];
    if (mob->rec.left >= max)
        mob->rec.left = utils[0];
    else
        mob->rec.left += utils[2];
    return (SUCCESS);
}
