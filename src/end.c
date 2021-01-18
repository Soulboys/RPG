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

end_t *init_end(sfTexture *texture, sfFont *font)
{
    end_t *end = malloc(sizeof(end_t));

    if (!end)
        return (NULL);
    end->rec = sfRectangleShape_create();
    if (!end->rec)
        return (NULL);
    sfRectangleShape_setSize(end->rec, (VF){1, 1});
    sfRectangleShape_setFillColor(end->rec, sfBlack);
    end->game_over = create_sprite(texture, (IR){0, 0, 500, 500},
        (float[2]){1, 1});
    end->text = create_text("buy the dlc to continue the game", 60, font);
    if (!end->game_over || !end->text)
        return (NULL);
    sfSprite_setOrigin(end->game_over, (VF){250, 250});
    return (end);
}

void display_dlc(int scene, sfVector2f pos, sfText *text, sfRenderWindow *win)
{
    if (scene == BUY)
        draw_text(text, (VF){pos.x - 350, pos.y + 200}, win);
}

void display_end(end_t *end, info_t *info, sprite_t player)
{
    int ti = get_time(info->pclock, &info->clock_c[6], 1000);
    VF vector;

    if (SCENE(2) != END && SCENE(2) != BUY)
        return;
    if (!ti) {
        vector = sfRectangleShape_getSize(end->rec);
        vector = (VF){vector.x < 1280 ? vector.x + 10: 1280,
            vector.y < 720 ? vector.y + 5: 720};
        sfRectangleShape_setSize(end->rec, vector);
        sfRectangleShape_setOrigin(end->rec,
            (VF){vector.x / 2, vector.y / 2});
        sfRectangleShape_setPosition(end->rec, player.pos);
    }
    sfRenderWindow_drawRectangleShape(info->win, end->rec, NULL);
    if (vector.x >= 1280 && vector.y >= 720) {
        draw_sprite(end->game_over, player.pos, (IR){0, 0, 500, 500},
            info->win);
        display_dlc(SCENE(2), player.pos, end->text, info->win);
    }
}

void destroy_end(end_t *end)
{
    sfRectangleShape_destroy(end->rec);
    sfSprite_destroy(end->game_over);
    sfText_destroy(end->text);
    free(end);
}
