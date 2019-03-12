/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** test_scene
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include "my_defender.h"

void free_castle(castle_t *castle)
{
    free_health_bar(castle->health_bar);
    free(castle);
}

int test_scene(sfRenderWindow *window)
{
    scene_t *scene = create_scene_test();
    castle_t *castle = init_castle();

    scene->is_dragging = 0;
    scene->window = window;
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, scene);
        turrets_shooting(scene->turret, scene->enemies);
        follow_mouse(scene);
        move_enemies(scene->enemies);
        draw_scene(window, scene, castle);
        scene->money->money += turrets_shooting(scene->turret, scene->enemies);
        remove_dead_enemies(scene);
        if (close_window(0) > 0)
            sfRenderWindow_close(window);
    }
    free_scene(scene);
    free_castle(castle);
    return (0);
}
