/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** check_enemy_death
*/
#include "my_defender.h"

void remove_enemy(enemy_t *enemy_to_remove, enemy_t *enemy_list)
{
    enemy_t *prev_enemy = enemy_list;

    while (enemy_list != enemy_to_remove) {
        if (enemy_list == NULL)
            return;
        prev_enemy = enemy_list;
        enemy_list = enemy_list->next;
    }
    prev_enemy->next = enemy_list->next;
    free_enemy(enemy_list);
}

void remove_dead_enemies(scene_t *scene)
{
    enemy_t *cursor = scene->enemies;

    while (cursor != NULL) {
        if (cursor->health <= 0 && cursor == scene->enemies) {
            free_enemy(cursor);
            scene->enemies = scene->enemies->next;
        }
        else if (cursor->health <= 0)
            remove_enemy(cursor, scene->enemies);
        cursor = cursor->next;
    }
}
