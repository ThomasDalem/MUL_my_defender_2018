/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_defender.h"

int close_window(int add)
{
    static int close = 0;

    if (add == 1) {
        close++;
    }
    return (close);
}

void print_hello(void)
{
    write(1, "hello\n", 6);
}

int main(void)
{
    sfRenderWindow *window = create_window(800, 600);
    scene_t *scene = create_scene_main_menu();

    if (scene == NULL) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        return (84);
    }
    while (sfRenderWindow_isOpen(window) == 1) {
        handle_events(window, scene);
        draw_scene(window, scene);
        if (close_window(0) > 0) {
            sfRenderWindow_close(window);
        }
    }
    sfRenderWindow_destroy(window);
    free_scene(scene);
    return (0);
}
