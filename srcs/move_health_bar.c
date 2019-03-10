/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** move_health_bar
*/
#include "my_defender.h"

void move_health_bar(health_bar_t *health_bar, sfVector2f pos)
{
    sfRectangleShape_setPosition(health_bar->red_bar, pos);
    sfRectangleShape_setPosition(health_bar->green_bar, pos);
}
