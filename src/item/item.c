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

sprite_t *init_inventory(sfTexture *texture)
{
    sprite_t *inventory = malloc(sizeof(sprite_t) * 2);

    if (!inventory)
        return (NULL);
    if (init_sprite(&inventory[0], texture, (IR){8, 8, 256, 224},
        (float[2]){5, 3.21}) || init_sprite(&inventory[1], texture,
        (IR){464, 328, 32, 32}, (float[2]){5, 3}))
        return (NULL);
    inventory[0].pos.y = 720;
    inventory[1].pos.y = 720;
    inventory[1].pos.x = 0;
    inventory[1].statistic[0] = 0;
    inventory[1].statistic[1] = 0;
    inventory[1].statistic[2] = 0;
    return (inventory);
}

static const sfVector2f POS[1] = {
    {354, 225},
};

static const sfIntRect IREC[4] = {
    {0, 32, 16, 16}, {48, 0, 16, 16}, {16, 0, 16, 16}, {16, 96, 16, 16},
};

pixel_t *init_particle(int j)
{
    pixel_t *vertex = malloc(sizeof(pixel_t) * 2);
    sfVector2f pos;

    if (!vertex)
        return (NULL);
    for (int i = 0; i < 2; i++) {
        pos = (sfVector2f){POS[j].x + 16, POS[j].y + 16};
        vertex[i].array = create_vertex_array(pos, sfYellow,
            !i ? sfLines: sfPoints, 50);
        vertex[i].life = 10;
    }
    return (vertex);
}

item_t *init_item(sfTexture **texture)
{
    item_t *item = malloc(sizeof(item_t));
    sprite_t *objects = malloc(sizeof(sprite_t) * 4);

    if (!item || !objects || init_sprite(&item->chest, texture[10],
        (IR){136, 53, 16, 16}, (float[2]){2, 2})
        || !(item->inventory = init_inventory(texture[12])))
        return (NULL);
    for (int i = 0; i < 4; i++) {
        if (init_sprite(&objects[i], texture[11], IREC[i], (float[2]){2, 2}))
            return (NULL);
        item->possesses[i][0] = 0;
        objects[i].pos.y = 720;
    }
    for (int i = 0; i < 1; i++) {
        item->chest_pos[i] = POS[i];
        item->open[i] = 0;
    }
    item->vertex = init_particle(0);
    if (!item->vertex)
        return (NULL);
    return (item->select = -1, item->item = objects, item);
}
