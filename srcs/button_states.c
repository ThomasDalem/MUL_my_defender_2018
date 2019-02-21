/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button_on_click
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

int button_is_hovered(button_t *button, sfVector2i mouse_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);
    int offset_x = button_pos.x + button_size.x;
    int offset_y = button_pos.y + button_size.y;

    if (mouse_position.x < button_pos.x || mouse_position.x > offset_x) {
        return (0);
    }
    if (mouse_position.y < button_pos.y || mouse_position.y > offset_y) {
        return (0);
    }
    return (1);
}

int button_is_clicked(button_t *button, sfVector2f click_position)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);
    int offset_x = button_pos.x + button_size.x;
    int offset_y = button_pos.y + button_size.y;

    if (click_position.x < button_pos.x || click_position.x > offset_x) {
        return (0);
    }
    if (click_position.y < button_pos.y || click_position.y > offset_y) {
        return (0);
    }
    return (1);
}
