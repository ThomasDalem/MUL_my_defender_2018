/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main_menu
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

int main_menu(sfRenderWindow *window)
{
    scene_t *menu_scene = create_scene_main_menu();

    menu_scene->is_dragging = 0;
    menu_scene->window = window;
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, menu_scene);
        follow_mouse(menu_scene);
        draw_scene(window, menu_scene);
        if (close_window(0) > 0) {
            sfRenderWindow_close(window);
        }
    }
    free_scene(menu_scene);
    return (0);
}
