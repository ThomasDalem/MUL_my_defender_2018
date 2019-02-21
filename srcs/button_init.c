/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button_init
*/
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "my_defender.h"

void change_color(button_t *button)
{
    sfRectangleShape_setOutlineColor(button->rect, sfRed);
}

void init_button(button_t *button ,sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    button->texture = sfTexture_createFromFile("./assets/play.png", NULL);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineColor(button->rect, sfBlue);
    sfRectangleShape_setOutlineThickness(button->rect, 3);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    button->callback = &print_hello;
    button->hover = &change_color;
}
