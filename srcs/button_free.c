/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** Frees a button and everything inside
*/
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <stdlib.h>
#include "my_defender.h"

void free_button(button_t *button)
{
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    sfTexture_destroy(button->texture);
    sfRectangleShape_destroy(button->rect);
    free(button);
}
