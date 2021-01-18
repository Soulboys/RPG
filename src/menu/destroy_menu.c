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

void destroy_menu(menu_t *menu)
{
    free_sprite_t(menu->rec);
    free_text_t(menu->player_name);
    free_text_t(menu->title);
    free_text_t(menu->alpha);
    free_text_t(menu->supp);
    my_free(menu->name);
    my_free(menu);
}
