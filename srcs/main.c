/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** main
*/
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_defender.h"

int close_window(int add)
{
    static int close = 0;

    if (add == 1) {
        close++;
    }
    return (close);
}

int main(void)
{
    sfRenderWindow *window = create_window(800, 600);
    
    main_menu(window);
    sfRenderWindow_destroy(window);
    return (0);
}
