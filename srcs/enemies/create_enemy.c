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
    *texture = sfTexture_createFromFile("./assets/spike.png", NULL);
    sfSprite_setTexture(*sprite, *texture, sfFalse);
}

int create_enemy(enemy_t **enemy, checkpoint_t *checkpoints)
{
    enemy_t *new_enemy = malloc(sizeof(enemy_t));
    sfVector2f scale;
    sfVector2f begin_pos;

    scale.x = 0.2;
    scale.y = 0.2;
    begin_pos.x = -50;
    begin_pos.y = 50;
    if (new_enemy == NULL) {
        return (84);
    }
    new_enemy->health = 100;
    new_enemy->clock = sfClock_create();
    init_sprite(&new_enemy->sprite, &new_enemy->texture);
    sfSprite_setScale(new_enemy->sprite, scale);
    sfSprite_setPosition(new_enemy->sprite, begin_pos);
    new_enemy->next_checkpoint = checkpoints;
    new_enemy->next = *enemy;
    *enemy = new_enemy;
    return (0);
}

enemy_t *create_enemies(checkpoint_t *checkpoints)
{
    enemy_t *enemies = NULL;

    if (create_enemy(&enemies, checkpoints) == 84) {
        return (NULL);
    }
    return (enemies);
}
