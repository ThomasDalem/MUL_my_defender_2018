/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_healthbar
*/
#include <stdlib.h>
#include "my_defender.h"

void free_health_bar(health_bar_t *health_bar)
{
    sfRectangleShape_destroy(health_bar->green_bar);
    sfRectangleShape_destroy(health_bar->red_bar);
    free(health_bar);
}
