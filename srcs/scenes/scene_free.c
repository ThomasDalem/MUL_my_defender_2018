/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** Frees a scene and all the objects and buttons inside
*/
#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include "my_defender.h"

void free_objects(game_object_t *objects)
{
    game_object_t *prev_node = objects;

    while (objects != NULL) {
        sfSprite_destroy(objects->sprite);
        sfTexture_destroy(objects->texture);
        prev_node = objects;
        objects = objects->next;
        free(prev_node);
    }
}

void free_button(button_t *button)
{
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    sfTexture_destroy(button->texture);
    sfRectangleShape_destroy(button->rect);
    if (button->is_draggable == 1) {
        sfSprite_destroy(button->obj_sprite);
        sfTexture_destroy(button->obj_texture);
    }
    free(button);
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
    if (scene->background_sprite != NULL && scene->background != NULL) {
        sfSprite_destroy(scene->background_sprite);
        sfTexture_destroy(scene->background);
    }
    free_objects(scene->objects);
    free_buttons(scene->buttons);
    free_enemies(scene->enemies);
    free_turrets(scene->turret);
    free_checkpoints(scene->checkpoints);
    free_money(scene->money);
    free(scene);
}
