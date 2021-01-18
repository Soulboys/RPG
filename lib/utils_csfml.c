/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** utils.c
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Rect.h>
#include <unistd.h>
#include "lib.h"

sfSprite *create_sprite(sfTexture *texture, sfIntRect rec, const float size[2])
{
    sfSprite *sprite;
    sfVector2f scale = {size[0], size[1]};

    sprite = sfSprite_create();
    if (!sprite)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setTextureRect(sprite, rec);
    return (sprite);
}

sfText *create_text(char *string, int size, sfFont *font)
{
    sfText *text;

    text = sfText_create();
    if (!text)
        return (NULL);
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    return (text);
}

void draw_sprite(sfSprite *sprite, sfVector2f position, sfIntRect rec,
sfRenderWindow *window)
{
    sfSprite_setPosition(sprite, position);
    sfSprite_setTextureRect(sprite, rec);
    sfRenderWindow_drawSprite(window , sprite, NULL);
}

void draw_text(sfText *text, sfVector2f position, sfRenderWindow *window)
{
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
}

sfFloatRect mouse_resize(sfRenderWindow *window, sfFloatRect pos)
{
    sfVector2u win = sfRenderWindow_getSize(window);
    float x = (float)win.x / (float)1280;
    float y = (float)win.y / (float)720;

    pos.width *= x;
    pos.height *= y;
    pos.top *= y;
    pos.left *= x;
    return (pos);
}
