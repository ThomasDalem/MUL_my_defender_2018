/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** create_enemy
*/
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "my_defender.h"

void init_sprite(sfSprite **sprite, sfTexture **texture)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile("./assets/walk1.png", NULL);
    sfSprite_setTexture(*sprite, *texture, sfFalse);
}

enemy_t *get_last_node(enemy_t *enemy)
{
    while (enemy->next != NULL)
        enemy = enemy->next;
    return (enemy);
}

void init_enemy_health_bar(enemy_t *enemy)
{
    sfVector2f size;
    sfVector2f pos;

    size.x = 100;
    size.y = 10;
    pos.x = -100;
    pos.y = -100;
    enemy->health_bar = create_health_bar(size, pos);
}

int create_enemy(enemy_t **enemy, checkpoint_t *checkpoints, sfVector2f pos)
{
    enemy_t *new_enemy = malloc(sizeof(enemy_t));

    if (new_enemy == NULL)
        return (84);
    new_enemy->health = 100;
    new_enemy->clock = sfClock_create();
    init_sprite(&new_enemy->sprite, &new_enemy->texture);
    sfSprite_setPosition(new_enemy->sprite, pos);
    new_enemy->next_checkpoint = checkpoints;
    new_enemy->next = NULL;
    init_enemy_health_bar(new_enemy);
    if (*enemy == NULL)
        *enemy = new_enemy;
    else
        get_last_node(*enemy)->next = new_enemy;
    return (0);
}

enemy_t *create_enemies(checkpoint_t *checkpoints)
{
    enemy_t *enemies = NULL;
    sfVector2f begin_pos;

    begin_pos.x = -100;
    begin_pos.y = 400;
    if (create_enemy(&enemies, checkpoints, begin_pos) == 84)
        return (NULL);
    begin_pos.x = -400;
    begin_pos.y = 400;
    if (create_enemy(&enemies, checkpoints, begin_pos) == 84)
        return (NULL);
    begin_pos.x = -600;
    begin_pos.y = 400;
    if (create_enemy(&enemies, checkpoints, begin_pos) == 84)
        return (NULL);
    return (enemies);
}
