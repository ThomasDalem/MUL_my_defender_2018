/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init_castle
*/
#include <stdlib.h>
#include "my_defender.h"

castle_t *init_castle(void)
{
    castle_t *new_castle = malloc(sizeof(castle_t));
    sfVector2f size;
    sfVector2f pos;

    if (new_castle == NULL)
        return (NULL);
    size.x = 100;
    size.y = 10;
    pos.x = 1200;
    pos.y = 10;
    new_castle->health = 100;
    new_castle->health_bar = create_health_bar(size, pos);
    return (new_castle);
}
