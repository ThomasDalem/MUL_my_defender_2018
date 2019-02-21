/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_window
*/
#include <SFML/Graphics/RenderWindow.h>

sfRenderWindow *create_window(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "test_buttons ", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 120);
    return (window);
}
