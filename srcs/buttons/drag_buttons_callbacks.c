/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** drag_buttons_callbacks
*/
#include "my_defender.h"

void add_turret1(scene_t *scene)
{
    if (scene->money >= 500) {
        create_turret1(&scene->turret);
        scene->money -= 500;
        if (scene->is_dragging == 1)
            scene->is_dragging = 0;
        else if (scene->is_dragging == 0)
            scene->is_dragging = 1;
    }
}

void add_turret2(scene_t *scene)
{
    if (scene->money >= 1000) {
        create_turret2(&scene->turret);
        scene->money -= 1000;
        if (scene->is_dragging == 1)
            scene->is_dragging = 0;
        else if (scene->is_dragging == 0)
            scene->is_dragging = 1;
    }
}
