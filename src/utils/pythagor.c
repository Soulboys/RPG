/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include "lib.h"
#include "define.h"
#include "prototype.h"
#include <math.h>

int pythagor(sfSprite *player, sfSprite *enemy, int range)
{
    VF pos_player = sfSprite_getPosition(player);
    VF pos_enemy = sfSprite_getPosition(enemy);
    double x_pos = pow(pos_enemy.x - pos_player.x, 2);
    double y_pos = pow(pos_enemy.y - pos_player.y, 2);
    double dist = sqrt(x_pos + y_pos);

    if (dist < 0)
        dist = dist * -1;
    if (dist <= range)
        return (SUCCESS);
    return (1);
}
