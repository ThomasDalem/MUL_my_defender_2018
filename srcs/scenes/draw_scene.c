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
        if (buttons[i]->is_draggable == 1)
           sfRenderWindow_drawSprite(window, buttons[i]->obj_sprite, NULL);
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
    sfVector2f pos;

    while (enemies != NULL) {
        pos = sfSprite_getPosition(enemies->sprite);
        move_health_bar(enemies->health_bar, pos);        
        sfRenderWindow_drawSprite(window, enemies->sprite, NULL);
        draw_health(enemies->health_bar, enemies->health, window);
        enemies = enemies->next;
    }
}

void draw_scene(sfRenderWindow *window, scene_t *scene, castle_t *castle)
{
    sfRenderWindow_clear(window, sfBlack);
    if (scene->background_sprite != NULL)
        sfRenderWindow_drawSprite(window, scene->background_sprite, NULL);
    if (castle != NULL)
        draw_castle_health(castle, window);
    draw_buttons(scene->buttons, window);
    draw_objects(scene->objects, window);
    draw_checkpoints(scene->checkpoints, window);
    draw_enemies(scene->enemies, window);
    draw_turrets(scene->turret, window);
    if (scene->money != NULL)
        sfRenderWindow_drawText(window, scene->money->text, NULL);
    sfRenderWindow_display(window);
}
