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

void destroy_house(house_t **house)
{
    for (int i = 0; house[i]; i++) {
        sfSprite_destroy(house[i]->sp.sprite);
        sfSprite_destroy(house[i]->sprite);
        free_tab(house[i]->map);
        my_free(house[i]->spawn);
        my_free(house[i]->spawn_coord);
        my_free(house[i]);
    }
    my_free(house);
}
