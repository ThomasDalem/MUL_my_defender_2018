/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** draw_health_bar
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void draw_health(health_bar_t *health_bar, int health, sfRenderWindow *window)
{
    sfVector2f size = sfRectangleShape_getSize(health_bar->red_bar);

    size.x = size.x * health / 100.0;
    sfRectangleShape_setSize(health_bar->green_bar, size);
    sfRenderWindow_drawRectangleShape(window, health_bar->red_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, health_bar->green_bar, NULL);
}
