/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** draw_turrets
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/CircleShape.h>
#include "my_defender.h"

void draw_turrets(turret_t *turret, sfRenderWindow *window)
{
    sfVector2f turret_pos;

    while (turret != NULL) {
        turret_pos = sfSprite_getPosition(turret->sprite);
        sfCircleShape_setPosition(turret->range_circle, turret_pos);
        sfRenderWindow_drawSprite(window, turret->sprite, NULL);
        if (turret->display_range == 1) {
            sfRenderWindow_drawCircleShape(window, turret->range_circle, NULL);
        }
        turret = turret->next;
    }
}
