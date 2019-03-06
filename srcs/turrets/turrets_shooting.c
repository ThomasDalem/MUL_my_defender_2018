/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** turrets_shooting
*/
#include "my_defender.h"

int is_in_circle(sfVector2f enemy, sfVector2f turret, int range)
{
    int rev_range = range * -1;

    if (enemy.x - turret.x >= range || enemy.x - turret.x <= rev_range)
        return (0);
    if (enemy.y - turret.y >= range || enemy.y - turret.y <= rev_range)
        return (0);
    return (1);
}

enemy_t *get_enemy_in_range(turret_t *turret, enemy_t *enemy)
{
    sfVector2f turret_pos = sfSprite_getPosition(turret->sprite);
    sfVector2f enemy_pos;

    while (enemy != NULL) {
        enemy_pos = sfSprite_getPosition(enemy->sprite);
        if (is_in_circle(enemy_pos, turret_pos, turret->range) == 1)
            return (enemy);
        enemy = enemy->next;
    }
    return (NULL);
}

int can_shoot(turret_t *turret)
{
    sfTime time;
    float elapsed_time = 0;

    time = sfClock_getElapsedTime(turret->clock);
    elapsed_time = sfTime_asSeconds(time);
    if (turret->target && !turret->is_dragged) {
        if (elapsed_time >= turret->fire_rate)
            return (1);
    }
    return (0);
}

int turrets_shooting(turret_t *turret, enemy_t *enemy)
{
    int money_earned = 0;

    while (turret != NULL) {
        turret->target = get_enemy_in_range(turret, enemy);
        if (can_shoot(turret)) {
            sfClock_restart(turret->clock);
            turret->target->health -= 10;
            money_earned += 100;
        }
        turret = turret->next;
    }
    return (money_earned);
}
