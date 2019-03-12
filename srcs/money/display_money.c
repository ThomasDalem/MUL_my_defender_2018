/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** display_money
*/
#include <stdlib.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"
#include "strlib.h"
#include "my_printf.h"

void add_text_beginning(char *str)
{
    str[0] = 'M';
    str[1] = 'o';
    str[2] = 'n';
    str[3] = 'e';
    str[4] = 'y';
    str[5] = ':';
    str[6] = ' ';
    str[7] = '\0';
}

void display_money(money_t *money, sfRenderWindow *window)
{
    char *num_str = my_int_to_str(money->money);
    int money_size = my_strlen(num_str);
    static unsigned int prev_money = 0;

    if (money->money != prev_money) {
        free(money->str);
        money->str = malloc(sizeof(char) * (7 + money_size + 1));
        if (money->text == NULL)
            return;
        add_text_beginning(money->str);
        money->str = my_strcat(money->str, num_str); 
        sfText_setString(money->text, money->str);
    }
    free(num_str);
    prev_money = money->money;
    sfRenderWindow_drawText(window, money->text, NULL);
}
