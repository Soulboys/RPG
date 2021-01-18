/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib.h"
#include "define.h"
#include "prototype.h"
#include <math.h>

static const VF tab[8] = {
    {1008, 1570}, {232, 593}, {1776, 960}, {1496, 1968}, {296, 1936}
};

static const int map[8][2] = {
    {143, 122}, {50, 25}, {85, 218}, {181, 183}, {178, 33}
};

enemy_t *init_enemy(sfTexture *texture)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    IR rec[] = {(IR){0, 0, 18, 28}, (IR){0, 0, 18, 28},
                        (IR){0, 0, 18, 28}, (IR){0, 0, 18, 28},
                        (IR){0, 0, 18, 28}};
    float scale[][2] = {{2, 2}, {2, 2}, {2, 2}, {2, 2}, {2, 2}};

    if (!enemy)
        return (NULL);
    enemy->mobs = init_sprite_t(ENEMY_MAX, rec, scale, texture);
    for (int i = 0; i < ENEMY_MAX; i++) {
        enemy->mobs[i]->pos = (VF)tab[i];
        enemy->mobs[i]->map_pos[0] = map[i][0];
        enemy->mobs[i]->map_pos[1] = map[i][1];
        enemy->mobs[i]->statistic[0] = 2;
        enemy->mobs[i]->statistic[1] = 0.5;
        enemy->mobs[i]->statistic[2] = 0;
        enemy->mobs[i]->statistic[3] = 0;
    }
    return (enemy);
}
