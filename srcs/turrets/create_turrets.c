/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_turrets
*/
#include <stdlib.h>
#include <SFML/Graphics/CircleShape.h>
#include "my_defender.h"

void set_circle_origin(sfCircleShape *circle)
{
    float circle_radius = sfCircleShape_getRadius(circle);
    sfVector2f final_position;

    final_position.x = circle_radius;
    final_position.y = circle_radius;
    sfCircleShape_setOrigin(circle, final_position);
}

sfCircleShape *create_circle_shape(int size)
{
    sfCircleShape *range_circle = sfCircleShape_create();

    sfCircleShape_setRadius(range_circle, size);
    sfCircleShape_setFillColor(range_circle, sfTransparent);
    sfCircleShape_setOutlineColor(range_circle, sfRed);
    sfCircleShape_setOutlineThickness(range_circle, 2);
    set_circle_origin(range_circle);
    return (range_circle);
}

int create_turret1(turret_t **turrets)
{
    turret_t *new_turret = malloc(sizeof(turret_t));
    char *path = "./assets/turret1.png";

    if (new_turret == NULL)
        return (84);
    new_turret->display_range = 1;
    new_turret->range = 200;
    new_turret->texture = sfTexture_createFromFile(path, NULL);
    new_turret->sprite = sfSprite_create();
    sfSprite_setTexture(new_turret->sprite, new_turret->texture, sfFalse);
    new_turret->range_circle = create_circle_shape(new_turret->range);
    new_turret->is_dragged = 1;
    new_turret->fire_rate = 0.5;
    new_turret->damage = 10;
    new_turret->clock = sfClock_create();
    new_turret->target = NULL;
    new_turret->next = *turrets;
    *turrets = new_turret;
    return (0);
}

int create_turret2(turret_t **turrets)
{
    turret_t *new_turret = malloc(sizeof(turret_t));
    char *path = "./assets/spike.png";

    if (new_turret == NULL)
        return (84);
    new_turret->display_range = 1;
    new_turret->range = 400;
    new_turret->texture = sfTexture_createFromFile(path, NULL);
    new_turret->sprite = sfSprite_create();
    sfSprite_setTexture(new_turret->sprite, new_turret->texture, sfFalse);
    new_turret->range_circle = create_circle_shape(new_turret->range);
    new_turret->is_dragged = 1;
    new_turret->fire_rate = 2;
    new_turret->damage = 25;
    new_turret->clock = sfClock_create();    
    new_turret->target = NULL;
    new_turret->next = *turrets;
    *turrets = new_turret;
    return (0);
}
