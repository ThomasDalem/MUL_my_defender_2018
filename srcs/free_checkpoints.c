/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_checkpoints
*/
#include "my_defender.h"

void free_checkpoint(checkpoint_t *checkpoint)
{
    sfSprite_destroy(checkpoint->sprite);
    sfTexture_destroy(checkpoint->texture);
}

void free_checkpoints(checkpoint_t *checkpoints)
{
    while (checkpoints != NULL) {
        free_checkpoint(checkpoints);
        checkpoints = checkpoints->next;
    }
}
