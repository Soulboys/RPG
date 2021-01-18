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

static const ressource_t RES[] = {
    {NULL, {178, 6, 256, 224}, {0, 0}, {5, 3.21}},
    {NULL, {178, 236, 256, 224}, {0, 0}, {5, 3.21}},
    {NULL, {210, 470, 18, 17}, {125, 210}, {5, 3.21}},
};

text_t **init_alphabet(char *str, sfFont *font)
{
    text_t **alpha = malloc(sizeof(text_t *) * (my_strlen(str) + 1));
    char new[2] = {'a', 0};

    if (!alpha)
        return (NULL);
    alpha[my_strlen(str)] = NULL;
    for (int i = 0, j = 0, k = 0; str[i]; i++) {
        alpha[i] = malloc(sizeof(text_t));
        if (!alpha[i])
            return (NULL);
        new[0] = str[i];
        alpha[i]->text = create_text(new, 50, font);
        alpha[i]->pos = (VF){160 + k * 75, 400 + 60 * j };
        j += k == 9 ? 1: 0;
        k += k == 9 ? -9: 1;
    }
    return (alpha);
}

text_t **init_title(sfFont *font)
{
    text_t **alpha = malloc(sizeof(text_t *) * 3);
    char *tab[] = {"register your name", "player select"};

    if (!alpha)
        return (NULL);
    alpha[2] = NULL;
    for (int i = 0; i < 2; i++) {
        alpha[i] = malloc(sizeof(text_t));
        if (!alpha[i])
            return (NULL);
        alpha[i]->text = create_text(tab[i], 60, font);
        alpha[i]->pos = i == 0 ? (VF){190, 115}: (VF){190, 60};
    }
    return (alpha);
}

sprite_t **init_rec(sfTexture *texture)
{
    sprite_t **rec = malloc(sizeof(sprite_t *) * 4);

    if (!rec)
        return (NULL);
    for (int i = 0; i < 3; i++) {
        rec[i] = malloc(sizeof(sprite_t));
        if (!rec[i])
            return (NULL);
    }
    if (init_sprite(rec[0], texture, RES[0].rec, RES[0].size)
        || init_sprite(rec[1], texture, RES[1].rec, RES[1].size)
        || init_sprite(rec[2], texture, RES[2].rec, RES[2].size))
        return (NULL);
    rec[0]->pos = RES[0].pos;
    rec[1]->pos = RES[0].pos;
    rec[2]->pos = RES[2].pos;
    rec[3] = NULL;
    return (rec);
}

text_t **init_supp(sfFont *font)
{
    text_t **alpha = malloc(sizeof(text_t *) * 10);
    char *tab[] = {"end", "del", "1.", "2.", "3.", "erase player",
    "add player", "how to play", "quit"};
    VF pos[] = {{1000, 400}, {1000, 500}, {350, 200}, {350, 300},
    {350, 400}, {200, 570}, {200, 500}, {700, 500}, {700, 570}};

    if (!alpha)
        return (NULL);
    alpha[9] = NULL;
    for (int i = 0; i < 9; i++) {
        alpha[i] = malloc(sizeof(text_t));
        if (!alpha[i])
            return (NULL);
        alpha[i]->text = create_text(tab[i], i < 2 ? 60: i > 4 ? 80:50, font);
        alpha[i]->pos = pos[i];
    }
    return (alpha);
}

menu_t *init_menu(sfTexture *texture, sfFont *font)
{
    menu_t *menu = malloc(sizeof(menu_t));
    text_t **name = malloc(sizeof(text_t *) * 4);

    if (!menu || !font || !name)
        return (NULL);
    menu->rec = init_rec(texture);
    menu->alpha = init_alphabet("abcdefghijklmnopqrstuvwxyz", font);
    menu->title = init_title(font);
    menu->supp = init_supp(font);
    menu->name = NULL;
    menu->player_name = name;
    menu->del_mode[0] = 0;
    menu->del_mode[1] = 0;
    for (int i = 0; i < 4; i++)
        menu->player_name[i] = NULL;
    return (!menu->supp || !menu->rec || !menu->alpha ||
        !menu->title ? NULL: menu);
}
