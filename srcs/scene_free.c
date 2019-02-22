/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** Frees a scene and all the objects and buttons inside
*/
#include <stdlib.h>
#include "my_defender.h"

void free_objects(game_object_t **objects)
{
    int i = 0;

    while (objects[i] != NULL) {
        free(objects[i]);
        i++;
    }
    free(objects);
}

void free_buttons(button_t **buttons)
{
    int i = 0;

    while (buttons[i] != NULL) {
        free_button(buttons[i]);
        i++;
    }
    free(buttons);
}

void free_scene(scene_t *scene)
{
    free_objects(scene->objects);
    free_buttons(scene->buttons);
    free(scene);
}
