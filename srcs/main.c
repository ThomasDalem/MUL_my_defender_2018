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

void print_hello(void)
{
    write(1, "hello\n", 6);
}

int main(void)
{
    sfRenderWindow *window = create_window(800, 600);
    sfVector2f pos;
    sfVector2f size;
    sfEvent event;
    button_t *button = malloc(sizeof(button_t));
    sfVector2f click_pos;

    pos.x = 100;
    pos.y = 100;
    size.x = 180;
    size.y = 50;
    init_button(button, pos, size);
    while (sfRenderWindow_isOpen(window) == 1) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
        sfRenderWindow_display(window);
        if (button_is_hovered(button, sfMouse_getPositionRenderWindow(window))) {
            button->hover(button);
        } else {
            sfRectangleShape_setOutlineColor(button->rect, sfBlue);
        }
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtMouseButtonPressed) {
                click_pos.x = event.mouseButton.x;
                click_pos.y = event.mouseButton.y;
                if (button_is_clicked(button, click_pos)) {
                    button->callback();
                }
            }
        }
    }
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
    button_destroy(button);
    return (0);
}
