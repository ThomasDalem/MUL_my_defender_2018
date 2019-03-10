/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init_health_bar
*/
#include <stdlib.h>
#include "my_defender.h"

health_bar_t *create_health_bar(sfVector2f size, sfVector2f pos)
{
    health_bar_t *new_health_bar = malloc(sizeof(health_bar_t));

    if (new_health_bar == NULL)
        return (NULL);
    new_health_bar->red_bar = sfRectangleShape_create();
    new_health_bar->green_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(new_health_bar->red_bar, size);
    sfRectangleShape_setSize(new_health_bar->green_bar, size);
    sfRectangleShape_setFillColor(new_health_bar->red_bar, sfRed);
    sfRectangleShape_setFillColor(new_health_bar->green_bar, sfGreen);
    sfRectangleShape_setPosition(new_health_bar->red_bar, pos);
    sfRectangleShape_setPosition(new_health_bar->green_bar, pos);
    return (new_health_bar);
}
