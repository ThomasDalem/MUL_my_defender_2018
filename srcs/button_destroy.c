/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** button_destroy
*/
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "my_defender.h"

void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfTexture_destroy(button->texture);
    free(button);
}
