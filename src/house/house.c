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

static const sfVector2f CSFML_POS[2][4] = {
    {{208, 269}},
    {{0, 0}, {700 * 2, 1305 * 2}},
};

static const int MAP_POS[2][4][2] = {
    {{23, 21}},
    {{0, 0}, {242, 171}}
};

static house_t *init_a_house(sfTexture *texture, IR rec, char *map,
float scale[2])
{
    house_t *link = malloc(sizeof(house_t));

    if (!link)
        return (NULL);
    link->sprite = NULL;
    link->map = get_map(map);
    if (init_sprite(&link->sp, texture, rec, scale))
        return (NULL);
    if (!link->map)
        return (NULL);
    return (link);
}

static int init_house_spawn(house_t *house, int j, int size)
{
    house->spawn = malloc(sizeof(sfVector2f) * (size + 1));

    house->spawn_coord = malloc(sizeof(int *) * (size + 1));
    if (!house->spawn || !house->spawn_coord)
        return (ERROR);
    for (int i = 0; i < size; i++) {
        house->spawn[i] = CSFML_POS[j][i];
        house->spawn_coord[i][0] = MAP_POS[j][i][0];
        house->spawn_coord[i][1] = MAP_POS[j][i][1];
    }
    return (SUCCESS);
}

void disp_house(house_t *house, sfRenderWindow *win)
{
    draw_sprite_t(&house->sp, win);
}

house_t **init_house(sfTexture **texture)
{
    house_t **house = malloc(sizeof(house_t *) * 3);

    if (!house)
        return (NULL);
    house[2] = NULL;
    house[1] = init_a_house(texture[8], (IR){0, 0, 226, 178},
        "res/map/house/link.txt", (float[2]){2, 2});
    house[0] = init_a_house(texture[13], (IR){0, 0, 1024, 1536},
        "res/map/outside_dungeon.txt", (float[2]){2, 2});
    if (!house[1] || !house[0] || init_house_spawn(house[1], 0, 1)
        || init_house_spawn(house[0], 1, 2))
        return (NULL);
    house[0]->sprite = create_sprite(texture[16], (IR){0, 0, 1024, 1536},
        (float[2]){2, 2});
    return (!house[0]->sprite ? NULL: house);
}
