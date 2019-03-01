/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_turrets
*/
#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>
#include "my_defender.h"

void free_turret(turret_t *turret)
{
    sfSprite_destroy(turret->sprite);
    sfTexture_destroy(turret->texture);
    sfCircleShape_destroy(turret->range_circle);
    free(turret);
}

void free_turrets(turret_t *turrets)
{
    while (turrets != NULL) {
        free_turret(turrets);
        turrets = turrets->next;
    }
}
