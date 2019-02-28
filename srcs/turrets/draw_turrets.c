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
    sfVector2f circle_pos;

    while (turret != NULL) {
        circle_pos.x = turret->range / 3.5;
        circle_pos.y = turret->range / 3.5;
        turret_pos = sfSprite_getPosition(turret->sprite);
        circle_pos.x += turret_pos.x;
        circle_pos.y += turret_pos.y;
        sfRenderWindow_drawSprite(window, turret->sprite, NULL);
        if (turret->display_range == 1) {
            sfCircleShape_setPosition(turret->range_circle, circle_pos);
            sfRenderWindow_drawCircleShape(window, turret->range_circle, NULL);
        }
        turret = turret->next;
    }
}
