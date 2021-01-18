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

int init_sprite(sprite_t *object, sfTexture *texture, IR rec,
const float size[2])
{
    if (!texture || !object)
        return (ERROR);
    object->sprite = create_sprite(texture, rec, size);
    if (!object->sprite)
        return (ERROR);
    object->rec = rec;
    object->pos = (VF) {0, 0};
    object->next = NULL;
    return (SUCCESS);
}

sprite_t **init_sprite_t(int size, IR rec[size], float scale[size][2],
sfTexture *texture)
{
    sprite_t **object = malloc(sizeof(sprite_t *) * (size + 1));

    if (!object)
        return (NULL);
    object[size] = NULL;
    for (int i = 0; i < size; i++) {
        object[i] = malloc(sizeof(sprite_t));
        if (!object[i] || init_sprite(object[i], texture, rec[i], scale[i]))
            return (NULL);
    }
    return (object);
}

void draw_sprite_t(sprite_t *object, sfRenderWindow *win)
{
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setTextureRect(object->sprite, object->rec);
    sfRenderWindow_drawSprite(win, object->sprite, NULL);
}

void destroy_sprite(sprite_t *object)
{
    sfSprite_destroy(object->sprite);
}

void free_sprite_t(sprite_t **object)
{
    for (int i = 0; object[i]; i++) {
        sfSprite_destroy(object[i]->sprite);
        my_free(object[i]);
    }
    my_free(object);
}
