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

int change_value(info_t *info, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WIN);
    sfFloatRect hitbox_2 = sfSprite_getGlobalBounds(OPT->menu->sprite[2]);
    sfFloatRect hitbox_1 = sfSprite_getGlobalBounds(OPT->menu->sprite[1]);

    if (sfFloatRect_contains(&hitbox_1, m.x, m.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        m.y < 300 && OPT->value[0] -20 >= 0 ? OPT->value[0] -= 20 : 0;
        m.y > 300 && m.y < 500
            && OPT->value[1] - 20 > 0 ? OPT->value[1] -= 20 : 0;
        m.y > 500 && OPT->value[2] - 5 > 0 ? OPT->value[2] -= 5 : 0;
    }
    if (sfFloatRect_contains(&hitbox_2, m.x, m.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        m.y < 300 && OPT->value[0] + 20 <= 100 ? OPT->value[0] += 20 : 0;
        m.y > 300 && m.y < 500
        && OPT->value[1] + 20 <= 100 ? OPT->value[1] += 20 : 0;
        m.y > 500 && OPT->value[2] + 5 < 120 ? OPT->value[2] += 5 : 0;
    }
    return (0);
}

void draw_button(info_t *info, rpg_t *rpg)
{
    int pos[6] = {212, 212, 372, 372, 532, 532};

    for (int i = 0; i < 6; i++) {
        draw_sprite(OPT->menu->sprite[i % 2 == 0 ? 1: 2],
            (VF){i % 2 == 0 ? 190: 1000, pos[i]},
            (IR){i % 2 == 0 ? 0: 26, 0, 26, 15}, WIN);
        change_value(info, rpg);
    }
}

void display_opt_menu(info_t *info, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        info->scene[0] = GAME;
    draw_sprite(OPT->menu->sprite[0], (VF){0, 0},
        (IR) {0, 0, 253, 221}, WIN);
    draw_text(OPT->menu->text[0], (VF) {515, 45}, WIN);
    draw_text(OPT->menu->text[1], (VF) {500, 212}, WIN);
    draw_text(OPT->menu->text[2], (VF) {503, 372}, WIN);
    draw_text(OPT->menu->text[3], (VF) {605, 532}, WIN);
    draw_button(info, rpg);
}

option_menu_t *init_option_menu(info_t *info, sfTexture **texture)
{
    option_menu_t *new = malloc(sizeof(option_menu_t));
    char *str[] = {"OPTIONS\n\t(press escape to back)", "AMBIANT VOLUME",
        "SOUND VOLUME", "FPS"};

    if (!new || !(new->text = malloc(sizeof(sfText *) * 4))
        || !(new->sprite = malloc(sizeof(sfSprite *) * 3)))
        return (NULL);
    for (int i = 0; i < 4; i++) {
        if (!(new->text[i] =
            create_text(str[i], i == 0 ? 60: 40, info->font[0])))
            return (NULL);
    }
    for (int i = 0; i < 3; i++) {
        new->sprite[i] = create_sprite(texture[i == 0 ? 14: 15],
            (IR){i == 2 ? 0: 26, 0, i > 0 ? 26: 221, i > 0 ? 15: 253},
            (float[2]){i == 0 ? 5.1: 3.3, 3.3});
        if (!new->sprite[i])
            return (NULL);
    }
    return (new->status = 1, new);
}

option_t *init_option(void)
{
    option_t *new = malloc(sizeof(option_t));
    char *str[] = {"res/music/back.ogg", "res/music/intro.ogg",
                    "res/music/attack.ogg"};

    if (!new)
        return (NULL);
    new->value = malloc(sizeof(int) * 3);
    new->music = malloc(sizeof(sfMusic *) * 3);
    if (!new->value || !new->music)
        return (NULL);
    for (int i = 0; i < 3; i++) {
        new->music[i] = sfMusic_createFromFile(str[i]);
        if (!new->music[i])
            return (NULL);
    }
    sfMusic_setVolume(new->music[1], 20.0);
    new->value[0] = 20;
    new->value[1] = 50;
    new->value[2] = 60;
    return (new);
}
