/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** draw_scene
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void draw_objects(game_object_t *objects, sfRenderWindow *window)
{
    while (objects != NULL) {
        sfRenderWindow_drawSprite(window, objects->sprite, NULL);
        objects = objects->next;
    }
}

void draw_buttons(button_t **buttons, sfRenderWindow *window)
{
    int i = 0;

    while (buttons[i] != NULL) {
        sfRenderWindow_drawRectangleShape(window, buttons[i]->rect, NULL);
        sfRenderWindow_drawText(window, buttons[i]->text, NULL);
        sfRenderWindow_drawSprite(window, buttons[i]->obj_sprite, NULL);
        i++;
    }
}

void draw_scene(sfRenderWindow *window, scene_t *scene)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_buttons(scene->buttons, window);
    draw_objects(scene->objects, window);
    sfRenderWindow_display(window);
}
