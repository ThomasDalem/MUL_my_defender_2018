/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** object_destroy
*/
#include "my_defender.h"

void object_destroy(game_object_t *object, scene_t *scene)
{
    game_object_t *cursor = scene->objects;
    game_object_t *prev_object = cursor;
    game_object_t *next_object = NULL;

    while (cursor != object) {
        prev_object = cursor;
        cursor = cursor->next;
        next_object = cursor->next;
    }
    if (object == cursor) {
        scene->objects = object->next;
    } else {
        prev_object->next = next_object;
    }
    free(object);
}