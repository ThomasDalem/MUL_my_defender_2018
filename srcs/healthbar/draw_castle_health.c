/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** draw_castle_health
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void draw_castle_health(castle_t *castle, sfRenderWindow *window)
{
    draw_health(castle->health_bar, castle->health, window);
}
