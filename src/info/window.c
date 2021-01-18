/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "lib.h"
#include "define.h"
#include "prototype.h"

sfRenderWindow *create_win(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1280, 720, 64};
    sfImage *image = sfImage_createFromFile("res/icon.jpg");
    const sfUint8 *pixel = sfImage_getPixelsPtr(image);

    window = sfRenderWindow_create(video_mode, "Game of Hyrule",
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 200, 200, pixel);
    sfImage_destroy(image);
    return (window);
}
