/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** Assign a turret type to a draggable button
*/
#include "my_defender.h"

void assign_turret_to_button(button_t *button, int id)
{
    if (id == 1)
        button_add_sprite(button, "./assets/turret1.png");
    if (id == 2)
        button_add_sprite(button, "./assets/spike.png");
}
