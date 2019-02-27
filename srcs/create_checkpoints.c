/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_checkpoint
*/
#include <stdlib.h>
#include "my_defender.h"

void create_checkpoint(checkpoint_t **head, sfVector2f pos)
{
    checkpoint_t *new_checkpoint = malloc(sizeof(checkpoint_t));
    sfVector2f scale;

    scale.x = 0.3;
    scale.y = 0.3;
    new_checkpoint->pos = pos;
    new_checkpoint->texture = sfTexture_createFromFile("./assets/spike.png", NULL);
    new_checkpoint->sprite = sfSprite_create();
    sfSprite_setTexture(new_checkpoint->sprite, new_checkpoint->texture, sfFalse);
    sfSprite_setScale(new_checkpoint->sprite, scale);
    sfSprite_setPosition(new_checkpoint->sprite, pos);
    new_checkpoint->next = *head;
    *head = new_checkpoint;
}

checkpoint_t *create_checkpoints(void)
{
    checkpoint_t *checkpoints = NULL;
    sfVector2f pos;

    pos.x = 500;
    pos.y = 300;
    create_checkpoint(&checkpoints, pos);
    pos.x = 300;
    pos.y = 300;
    create_checkpoint(&checkpoints, pos);
    pos.x = 300;
    pos.y = 50;
    create_checkpoint(&checkpoints, pos);
    return (checkpoints);
}
