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
        printf("money: %d\n", scene->money->money); // TOREMOVE
    }
    free_scene(scene);
    return (0);
}
