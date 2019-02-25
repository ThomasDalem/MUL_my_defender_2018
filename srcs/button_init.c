/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button_init
*/
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <stdio.h>
#include "my_defender.h"

void change_color(button_t *button)
{
    sfRectangleShape_setOutlineColor(button->rect, sfRed);
}

sfVector2f calculate_text_pos(button_t *button, float outline_size)
{
    sfVector2f text_pos;
    sfFloatRect rect_rect = sfRectangleShape_getGlobalBounds(button->rect);
    sfFloatRect text_rect = sfText_getGlobalBounds(button->text);
    int button_middle_x = rect_rect.width / 2;
    int text_middle_x = text_rect.width / 2;
    int text_middle_y = text_rect.height / 2;

    text_pos.x = rect_rect.left + button_middle_x - text_middle_x;
    text_pos.y = rect_rect.top + text_middle_y - outline_size;
    return (text_pos);
}

void place_text(button_t *button)
{
    float outline_size = sfRectangleShape_getOutlineThickness(button->rect);
    sfVector2f correct_text_pos = calculate_text_pos(button, outline_size);

    sfText_setPosition(button->text, correct_text_pos);
}

void button_set_text(button_t *button, char *text)
{
    sfText_setString(button->text, text);
    sfText_setColor(button->text, sfRed);
    place_text(button);
}

void init_button(button_t *button ,sfVector2f position, sfVector2f size)
{
    button->is_draggable = 0;
    button->rect = sfRectangleShape_create();
    button->texture = sfTexture_createFromFile("./assets/play.png", NULL);
    button->font = sfFont_createFromFile("./assets/Comfortaa-Light.ttf");
    button->text = sfText_create();
    sfText_setFont(button->text, button->font);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineColor(button->rect, sfBlue);
    sfRectangleShape_setOutlineThickness(button->rect, 3);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    button->callback = &print_hello;
    button->hover = &change_color;
}
