/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** handle_events
*/
#include <SFML/Graphics/RenderWindow.h>
#include "my_defender.h"

void check_if_pressed_button(button_t **buttons, sfVector2f click_position)
{
    int i = 0;

    while (buttons[i] != NULL) {
        if (button_is_clicked(buttons[i], click_position) == 1) {
            sfRectangleShape_setOutlineColor(buttons[i]->rect, sfBlue);
        }
        i++;
    }
}

void check_if_released_button(button_t **buttons, sfVector2f click_position)
{
    int i = 0;

    while (buttons[i] != NULL) {
        if (button_is_clicked(buttons[i], click_position) == 1) {
            buttons[i]->callback();
            sfRectangleShape_setOutlineColor(buttons[i]->rect, sfGreen);
        }
        i++;
    }
}

void check_events_types(sfEvent *event, scene_t *scene)
{
    sfVector2f click_position;

    click_position.x = event->mouseButton.x;
    click_position.y = event->mouseButton.y;
    if (event->type == sfEvtMouseButtonPressed) {
        check_if_pressed_button(scene->buttons, click_position);
    }
    else if (event->type == sfEvtMouseButtonReleased) {
        check_if_released_button(scene->buttons, click_position);
    }
}

void check_button_hover(button_t **buttons, sfVector2i mouse_position)
{
    int i = 0;

    while (buttons[i] != NULL) {
        sfRectangleShape_setOutlineColor(buttons[i]->rect, sfRed);
        if (button_is_hovered(buttons[i], mouse_position) == 1) {
            sfRectangleShape_setOutlineColor(buttons[i]->rect, sfGreen);
        }
        i++;
    }
}

void handle_events(sfRenderWindow *window, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_button_hover(scene->buttons, mouse_pos);
        check_events_types(&event, scene);
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}
