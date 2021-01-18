/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include <math.h>
#include "lib.h"

sfVertexArray *create_vertex_array(sfVector2f emitter, sfColor color,
sfPrimitiveType type, int nb)
{
    sfVertex point;
    sfVertexArray *array = sfVertexArray_create();

    if (!array)
        return (NULL);
    for (int j = 0; j < nb; j ++) {
        point.position = emitter;
        point.color = color;
        sfVertexArray_append(array, point);
    }
    sfVertexArray_setPrimitiveType(array, type);
    return (array);
}

void update_vertex(sfVertexArray *array, sfVector2f emmitter, float j)
{
    size_t nb = sfVertexArray_getVertexCount(array);
    sfVertex *vertex;
    float angle = M_PI * 2 / nb;

    for (size_t i = 0; i < nb; i++) {
        vertex = sfVertexArray_getVertex(array, i);
        vertex->position.x = cos(angle * i) * j + emmitter.x;
        vertex->position.y = sin(angle * i) * j + emmitter.y;
    }
}

void update_fog(pixel_t pixelart)
{
    size_t nb = sfVertexArray_getVertexCount(pixelart.array);
    sfVertex *vertex;

    for (size_t i = 0; i < nb; i++) {
        vertex = sfVertexArray_getVertex(pixelart.array, i);
        vertex->position.x -= rand() % 2 == 1 ? 2: -2;
        vertex->position.y -= rand() % 2 == 1 ? 2: 1;;
        if (vertex->position.y < pixelart.emmitter.y - 40)
            vertex->position.y += 40;
        if (vertex->position.x > pixelart.emmitter.x + 30 ||
            vertex->position.x < pixelart.emmitter.x - 30)
            vertex->position.x = pixelart.emmitter.x;
    }
}
