/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** test_scene
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

int test_scene(sfRenderWindow *window)
{
    scene_t *test_scene = create_scene_test();

    test_scene->is_dragging = 0;
    test_scene->window = window;
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, test_scene);
        follow_mouse(test_scene);
        draw_scene(window, test_scene);
        if (close_window(0) > 0) {
            sfRenderWindow_close(window);
        }
    }
    free_scene(test_scene);
    return (0);
}