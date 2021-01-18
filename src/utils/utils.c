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

void my_free(void *to_free)
{
    if (to_free)
        free(to_free);
}

void free_text_t(text_t **text)
{
    for (int i = 0; text && text[i]; i++) {
        sfText_destroy(text[i]->text);
        my_free(text[i]);
    }
    my_free(text);
}

int text_contain(sfRenderWindow *win, sfText *text, sfVector2i m)
{
    sfFloatRect r = sfText_getGlobalBounds(text);

    r = mouse_resize(win, r);
    if (sfFloatRect_contains(&r, m.x, m.y))
        return (1);
    return (0);
}

sfText *resize_a_text(sfText *text, sfVector2i m, int norma, int new)
{
    sfFloatRect r;

    r = sfText_getGlobalBounds(text);
    if (sfFloatRect_contains(&r, m.x, m.y))
        sfText_setCharacterSize(text, new);
    else
        sfText_setCharacterSize(text, norma);
    return (text);
}
