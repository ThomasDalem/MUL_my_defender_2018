/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_test_scene
*/
#include <stdlib.h>
#include "my_defender.h"

static button_t *create_button_drag(void)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f button_size;
    sfVector2f button_position;

    if (button == NULL) {
        return (NULL);
    }
    button->is_draggable = 1;
    button_size.x = 100;
    button_size.y = 100;
    button_position.x = 300;
    button_position.y = 200;
    init_button(button, button_position, button_size);
    button_add_sprite(button, "./assets/turret1.png");
    return (button);
}

static button_t **create_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);

    if (buttons == NULL) {
        return (NULL);
    }
    buttons[0] = create_button_drag();
    buttons[0]->callback = &change_is_dragging;
    buttons[1] = NULL;
    return (buttons);
}

scene_t *create_scene_test(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL) {
        return (NULL);
    }
    scene->objects = NULL;
    scene->buttons = create_buttons();
    scene->checkpoints = create_checkpoints();
    scene->enemies = create_enemies(scene->checkpoints);
    scene->turret = NULL;
    return (scene);
}
