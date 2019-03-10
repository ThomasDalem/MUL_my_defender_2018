/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** test_scene
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "my_defender.h"

int test_scene(sfRenderWindow *window)
{
    scene_t *scene = create_scene_test();
    castle_t *castle = init_castle();
    scene->money = 500;

    scene->is_dragging = 0;
    scene->window = window;
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, scene);
        turrets_shooting(scene->turret, scene->enemies);
        follow_mouse(scene);
        move_enemies(scene->enemies);
        draw_scene(window, scene, castle);
        castle->health -= 0.1; // A retirer
        scene->money += turrets_shooting(scene->turret, scene->enemies);
        remove_dead_enemies(scene);
        if (close_window(0) > 0)
            sfRenderWindow_close(window);
        printf("money: %d\n", scene->money); // A retirer
    }
    free_scene(scene);
    return (0);
}
