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
        if (buttons[i]->is_draggable == 1) {
           sfRenderWindow_drawSprite(window, buttons[i]->obj_sprite, NULL);
        }
        i++;
    }
}

void draw_checkpoints(checkpoint_t *checkpoints, sfRenderWindow *window)
{
    while (checkpoints != NULL) {
        sfRenderWindow_drawSprite(window, checkpoints->sprite, NULL);
        checkpoints = checkpoints->next;
    }
}

void draw_enemies(enemy_t *enemies, sfRenderWindow *window)
{
    while (enemies != NULL) {
        sfRenderWindow_drawSprite(window, enemies->sprite, NULL);
        enemies = enemies->next;
    }
}

void draw_scene(sfRenderWindow *window, scene_t *scene)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_buttons(scene->buttons, window);
    draw_objects(scene->objects, window);
    draw_checkpoints(scene->checkpoints, window);
    draw_enemies(scene->enemies, window);
    draw_turrets(scene->turret, window);
    sfRenderWindow_display(window);
}
