/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** free_money
*/
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <stdlib.h>
#include "my_defender.h"

void free_money(money_t *money)
{
    if (money != NULL) {
        sfText_destroy(money->text);
        sfFont_destroy(money->font);
        free(money->str);
        free(money);
    }
}
