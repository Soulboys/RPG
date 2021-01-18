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

void destroy_enemy(enemy_t *enemy)
{
    for (int i = 0; i < ENEMY_MAX; i++) {
        sfSprite_destroy(enemy->mobs[i]->sprite);
        my_free(enemy->mobs[i]);
    }
    my_free(enemy->mobs);
    my_free(enemy);
}
