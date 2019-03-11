/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_test_scene
*/
#include <stdlib.h>
#include "my_defender.h"

button_t *create_button_drag(sfVector2f pos, int turret_id)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f button_size;
    //sfVector2f button_position;

    if (button == NULL)
        return (NULL);
    button->is_draggable = 1;
    button_size.x = 100;
    button_size.y = 100;
    //button_position.x = 100;
    //button_position.y = 100;
    init_button(button, pos, button_size);
    assign_turret_to_button(button, turret_id);
    return (button);
}

button_t **create_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    sfVector2f pos;

    if (buttons == NULL)
        return (NULL);
    pos.x = 100;
    pos.y = 100;
    buttons[0] = create_button_drag(pos, 1);
    buttons[0]->callback = &add_turret1;
    pos.x = 300;
    pos.y = 100;
    buttons[1] = create_button_drag(pos, 2);
    buttons[1]->callback = &add_turret2;
    buttons[2] = NULL;
    return (buttons);
}

scene_t *create_scene_test(void)
{
    scene_t *scene = malloc(sizeof(scene_t));
    char *background_path = "./assets/background.jpg";

    if (scene == NULL)
        return (NULL);
    scene->objects = NULL;
    scene->buttons = create_buttons();
    scene->checkpoints = create_checkpoints();
    scene->enemies = create_enemies(scene->checkpoints);
    scene->turret = NULL;
    scene->background = sfTexture_createFromFile(background_path, NULL);
    scene->background_sprite = sfSprite_create();
    sfSprite_setTexture(scene->background_sprite, scene->background, sfFalse);
    return (scene);
}
