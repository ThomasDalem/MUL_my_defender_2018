/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** follow_mouse
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void change_is_dragging(scene_t *scene)
{
    create_turret(&scene->turret);
    if (scene->is_dragging == 1) {
        scene->is_dragging = 0;
    }
    else if (scene->is_dragging == 0) {
        scene->is_dragging = 1;
    }
}

void follow_mouse(scene_t *scene)
{
    sfVector2i mouse_position;
    sfVector2f sprite_position;
    sfVector2f middle_sprite;
    sfFloatRect sprite_bounds;

    if (scene->is_dragging == 1) {
        sprite_bounds = sfSprite_getGlobalBounds(scene->turret->sprite);
        middle_sprite.x = sprite_bounds.width / 4;
        middle_sprite.y = sprite_bounds.height / 4;
        mouse_position = sfMouse_getPositionRenderWindow(scene->window);
        sprite_position.x = mouse_position.x - mouse_position.x % 100 + middle_sprite.x - 25.0;
        sprite_position.y = mouse_position.y - mouse_position.y % 100 + middle_sprite.y - 22.0;
        sfSprite_setPosition(scene->turret->sprite, sprite_position);
    }
}
