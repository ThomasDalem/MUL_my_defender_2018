/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button_add_sprite
*/
#include "my_defender.h"

sfVector2f place_sprite(button_t *button)
{
    sfVector2f sprite_position;
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(button->obj_sprite);
    sfFloatRect button_bounds = sfRectangleShape_getGlobalBounds(button->rect);
    int outline_size = sfRectangleShape_getOutlineThickness(button->rect);
    int button_middle_x = button_bounds.width / 2;
    int button_middle_y = button_bounds.height / 2;
    int sprite_middle_x = sprite_bounds.width / 2;
    int sprite_middle_y = sprite_bounds.height / 2;

    sprite_position.x = button_bounds.left + button_middle_x - sprite_middle_x;
    sprite_position.y = button_bounds.top + button_middle_y - sprite_middle_y - outline_size;
    return (sprite_position);
}

void button_add_sprite(button_t *button, char const *filepath)
{
    sfVector2f sprite_scale;
    sfVector2f sprite_position;

    sprite_scale.x = 0.9;
    sprite_scale.y = 0.9;
    button->is_draggable = 1;
    button->obj_texture = sfTexture_createFromFile(filepath, NULL);
    button->obj_sprite = sfSprite_create();
    sfSprite_setTexture(button->obj_sprite, button->obj_texture, sfFalse);
    sfSprite_setScale(button->obj_sprite, sprite_scale);
    sprite_position = place_sprite(button);
    sfSprite_setPosition(button->obj_sprite, sprite_position);
}
