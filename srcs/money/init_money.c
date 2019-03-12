/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** init_money
*/
#include <stdlib.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include "my_defender.h"

money_t *init_money(int beginning_money)
{
    money_t *money = malloc(sizeof(money_t));
    sfVector2f pos;

    if (money == NULL)
        return (NULL);
    pos.x = 20;
    pos.y = 20;
    money->money = beginning_money;
    money->text = NULL;
    money->font = sfFont_createFromFile("./assets/Comfortaa-Light.ttf");
    money->text = sfText_create();
    money->str = NULL;
    sfText_setFont(money->text, money->font);
    sfText_setColor(money->text, sfRed);
    sfText_setPosition(money->text, pos);
    return (money);
}
