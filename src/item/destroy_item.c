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

void destroy_item(item_t *item)
{
    sfSprite_destroy(item->chest.sprite);
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(item->item[i].sprite);
        if (i < 2)
            sfSprite_destroy(item->inventory[i].sprite);
    }
    free(item->inventory);
    sfVertexArray_destroy(item->vertex[0].array);
    sfVertexArray_destroy(item->vertex[1].array);
    free(item->vertex);
    free(item->item);
    free(item);
}
