/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_test_scene
*/
#include <stdlib.h>
#include "my_defender.h"

button_t *create_button_play(void)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f button_size;
    sfVector2f button_position;

    if (button == NULL) {
        return (NULL);
    }
    button_size.x = 200;
    button_size.y = 50;
    button_position.x = 300;
    button_position.y = 200;
    init_button(button, button_position, button_size);
    button_set_text(button, "PLAY");
    return (button);
}

button_t *create_button_quit(void)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f button_size;
    sfVector2f button_position;

    if (button == NULL) {
        return (NULL);
    }
    button_size.x = 200;
    button_size.y = 50;
    button_position.x = 300;
    button_position.y = 400;
    init_button(button, button_position, button_size);
    button_set_text(button, "QUIT");
    button->callback = &quit;
    return (button);
}

button_t **create_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    if (buttons == NULL) {
        return (NULL);
    }
    buttons[0] = create_button_play();
    buttons[1] = create_button_quit();
    buttons[2] = NULL;
    return (buttons);
}

scene_t *create_scene_main_menu(void)
{
    scene_t *scene = malloc(sizeof(scene_t));

    if (scene == NULL) {
        return (NULL);
    }
    scene->objects = malloc(sizeof(game_object_t *) * 1);
    scene->objects[0] = NULL;
    scene->buttons = create_buttons();
    return (scene);
}
