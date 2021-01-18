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

static const sfIntRect RECT[] = {
    {0, 0, 100, 130}, {0, 0, 1200, 1200}, {0, 0, 1280, 720}, {0, 0, 1280, 720}
};

static const float SIZE[][2] = {
    {2, 2}, {0.5, 0.5}, {0.5, 0.5}, {0.5, 0.5}
};

static const sfVector2f VPOS[] = {
    {650, 300}, {350, 300}, {450, 375}, {450, 375}
};

help_t *init_help(sfTexture **texture, sfFont *font)
{
    help_t *help = malloc(sizeof(help_t));
    sprite_t *action = malloc(sizeof(sprite_t) * 5);
    sfText **text = malloc(sizeof(sfText *) * 5);
    char *use[4] = {"use left/right/up/down keys to move the player",
        "use o to interact with environnement",
        "use y to display inventory", "use space to attack"};

    if (!help || !action || !text)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        if (init_sprite(&action[i], texture[18 + i], RECT[i], (float[2]){0, 0}))
            return (NULL);
        sfSprite_setOrigin(action[i].sprite, (VF){RECT[i].width / 2,
            RECT[i].height / 2});
        text[i] = create_text(use[i], 50, font);
        if (!text[i])
            return (NULL);
    }
    help->text = text;
    return (help->action = action, help);
}

void display_help(info_t *info, rpg_t *rpg)
{
    sfVector2f pos = (VF){300, 600};
    sfVector2f scale =
        sfSprite_getScale(rpg->help->action[SCENE(1) - 1].sprite);
    int ti = get_time(info->pclock, &info->clock_c[5], 50000);
    float add = SCENE(1) - 1 == 0 ? 0.1: 0.025;

    if (!ti && (scale.x < SIZE[SCENE(1) - 1][0]
        || scale.y < SIZE[SCENE(1) - 1][1]))
        sfSprite_setScale(rpg->help->action[SCENE(1) - 1].sprite,
            (VF){scale.x + add, scale.y + add});
    draw_sprite(rpg->help->action[SCENE(1) - 1].sprite, VPOS[SCENE(1) - 1],
        rpg->help->action[SCENE(1) - 1].rec, info->win);
    draw_text(rpg->help->text[SCENE(1) - 1], pos, info->win);
}

void destroy_help(help_t *help)
{
    for (int i = 0; i < 4; i++) {
        sfSprite_destroy(help->action[i].sprite);
        sfText_destroy(help->text[i]);
    }
    my_free(help->action);
    my_free(help->text);
    my_free(help);
}
