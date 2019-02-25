/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_object
*/
#include <stdlib.h>
#include "my_defender.h"

void create_object(scene_t *scene)
{
    game_object_t *new_object = malloc(sizeof(game_object_t));
    sfVector2f scale;

    scale.x = 0.3;
    scale.y = 0.3;
    new_object->sprite = sfSprite_create();
    new_object->texture = sfTexture_createFromFile("./assets/spike.png", NULL);
    sfSprite_setTexture(new_object->sprite, new_object->texture, sfFalse);
    sfSprite_setScale(new_object->sprite, scale);
    new_object->next = scene->objects;
    scene->objects = new_object;
}
