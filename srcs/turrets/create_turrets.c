/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_turrets
*/
#include <stdlib.h>
#include <SFML/Graphics/CircleShape.h>
#include "my_defender.h"

void set_circle_origin(sfCircleShape *circle, sfSprite *turret_sprite)
{
    float circle_radius = sfCircleShape_getRadius(circle);
    sfVector2f final_position;

    final_position.x = circle_radius - circle_radius / 2;
    final_position.y = circle_radius - circle_radius / 2;
    sfCircleShape_setOrigin(circle, final_position);
}

sfCircleShape *create_circle_shape(int size, sfSprite *turret_sprite)
{
    sfCircleShape *range_circle = sfCircleShape_create();

    sfCircleShape_setRadius(range_circle, size);
    sfCircleShape_setFillColor(range_circle, sfTransparent);
    sfCircleShape_setOutlineColor(range_circle, sfRed);
    sfCircleShape_setOutlineThickness(range_circle, 1);
    set_circle_origin(range_circle, turret_sprite);
    return (range_circle);
}

int create_turret(turret_t **turrets)
{
    turret_t *new_turret = malloc(sizeof(turret_t));
    sfVector2f scale;

    if (new_turret == NULL) {
        return (84);
    }
    scale.x = 1;
    scale.y = 1;
    new_turret->display_range = 1;
    new_turret->range = 100;
    new_turret->texture = sfTexture_createFromFile("./assets/turret1.png", NULL);
    new_turret->sprite = sfSprite_create();
    sfSprite_setTexture(new_turret->sprite, new_turret->texture, sfFalse);
    sfSprite_setScale(new_turret->sprite, scale);
    new_turret->range_circle = create_circle_shape(100, new_turret->sprite);
    new_turret->target = NULL;
    new_turret->next = *turrets;
    *turrets = new_turret;
    return (0);
}
