/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** enemies_free
*/
#include <stdlib.h>
#include "my_defender.h"

void free_enemy(enemy_t *enemy)
{
    sfClock_destroy(enemy->clock);
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    free(enemy);
}

void free_enemies(enemy_t *enemies)
{
    enemy_t *prev_enemy = NULL;

    while (enemies != NULL) {
        prev_enemy = enemies;
        enemies = enemies->next;
        free_enemy(prev_enemy);
    }
}
