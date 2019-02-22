/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** draw_scene
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void draw_objects(game_object_t **objects, sfRenderWindow *window)
{
    int i = 0;

    while (objects[i] != NULL) {
        sfRenderWindow_drawSprite(window, objects[i]->sprite, NULL);
        i++;
    }
}

void draw_buttons(button_t **buttons, sfRenderWindow *window)
{
    int i = 0;

    while (buttons[i] != NULL) {
        sfRenderWindow_drawRectangleShape(window, buttons[i]->rect, NULL);
        sfRenderWindow_drawText(window, buttons[i]->text, NULL);
        i++;
    }
}

void draw_scene(sfRenderWindow *window, scene_t *scene)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_objects(scene->objects, window);
    draw_buttons(scene->buttons, window);
    sfRenderWindow_display(window);
}
