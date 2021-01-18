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

void destroy_option(option_t *opt)
{
    for (int i = 0; i < 4; i++) {
        if (i < 3)
            sfSprite_destroy(opt->menu->sprite[i]);
        sfText_destroy(opt->menu->text[i]);
    }
    my_free(opt->menu->text);
    my_free(opt->menu->sprite);
    my_free(opt->menu);
    for (int i = 0; i < 3; i++)
        sfMusic_destroy(opt->music[i]);
    my_free(opt->value);
    my_free(opt->music);
    my_free(opt);
}
