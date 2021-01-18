/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

int init_intro(sprite_t *intro, sfTexture *spritesheet, text_t *text,
sfFont *font)
{
    text->text = create_text("press enter to skip", 50, font);
    text->pos = (VF){470, 620};
    text->size = 50;
    if (!text || init_sprite(intro, spritesheet, (IR){0, 0, 600, 338},
    (float[2]){2.13, 2.13}))
        return (ERROR);
    return (SUCCESS);
}

sfIntRect move_spritesheet(IR rec, info_t *i, text_t *enter)
{
    static int move = 0;

    if (restart_clock(i, 100000))
        return (rec);
    enter->size += (!move) ? 1: -1;
    enter->pos.x += (!move) ? -5: 5;
    if (enter->size == 60 || enter->size == 50)
        move = (!move) ? 1: 0;
    if (rec.left >= 600 && rec.top >= 6083)
        return (rec);
    rec.left += 600;
    if (rec.left >= 3000) {
        rec.left = 0;
        rec.top += 338;
    }
    return (rec);
}

void disp_intro(info_t *info, rpg_t *rpg)
{
    rpg->intro.rec = move_spritesheet(rpg->intro.rec, info,
    &rpg->intro_text);
    draw_sprite_t(&rpg->intro, info->win);
    sfText_setCharacterSize(rpg->intro_text.text, rpg->intro_text.size);
    draw_text(rpg->intro_text.text, rpg->intro_text.pos, info->win);
}
