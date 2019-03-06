/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** enemy_movement
*/
#include <SFML/System/Clock.h>
#include "my_defender.h"

int set_x_direction(int checkpoint_x, int enemy_pos_x)
{
    if (enemy_pos_x < checkpoint_x)
        return (1);
    else if (enemy_pos_x > checkpoint_x)
        return (-1);
    return (0);
}

int set_y_direction(int checkpoint_y, int enemy_pos_y)
{
    if (enemy_pos_y < checkpoint_y)
        return (1);
    else if (enemy_pos_y > checkpoint_y)
        return (-1);
    return (0);
}

void move_enemy(enemy_t *enemy)
{
    sfTime clock_time = sfClock_getElapsedTime(enemy->clock);
    float time_elapsed = sfTime_asMilliseconds(clock_time);
    sfVector2f next_waypoint_pos;
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f offset;

    next_waypoint_pos = sfSprite_getPosition(enemy->next_checkpoint->sprite);
    if (time_elapsed >= 0.5) {
        offset.x = set_x_direction(next_waypoint_pos.x, enemy_pos.x);
        offset.y = set_y_direction(next_waypoint_pos.y, enemy_pos.y);
        if (offset.x == 0 && offset.y == 0 && enemy->next_checkpoint->next != NULL)
            enemy->next_checkpoint = enemy->next_checkpoint->next;
        sfSprite_move(enemy->sprite, offset);
        sfClock_restart(enemy->clock);
    }
}

void move_enemies(enemy_t *enemies)
{
    while (enemies != NULL) {
        move_enemy(enemies);
        enemies = enemies->next;
    }
}
