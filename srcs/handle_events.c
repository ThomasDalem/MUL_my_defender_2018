/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** handle_events
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include "my_defender.h"

void check_if_pressed_button(scene_t *scene, sfVector2f click_position)
{
    sfColor color;

    color.a = 255;
    color.r = 0;
    color.g = 125;
    color.b = 0;
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (button_is_clicked(scene->buttons[i], click_position) == 1) {
            scene->buttons[i]->callback(scene);
            sfRectangleShape_setOutlineColor(scene->buttons[i]->rect, color);
            sfText_setColor(scene->buttons[i]->text, color);
        }
    }
}

void check_if_released_button(scene_t *scene, sfVector2f click_position)
{
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        if (button_is_clicked(scene->buttons[i], click_position) == 1) {
            sfRectangleShape_setOutlineColor(scene->buttons[i]->rect, sfGreen);
            sfText_setColor(scene->buttons[i]->text, sfGreen);
        }
    }
}

void check_button_hover(scene_t *scene, sfVector2i mouse_position)
{
    for (int i = 0; scene->buttons[i] != NULL; i++) {
        sfRectangleShape_setOutlineColor(scene->buttons[i]->rect, sfRed);
        sfText_setColor(scene->buttons[i]->text, sfRed);
        if (button_is_hovered(scene->buttons[i], mouse_position) == 1) {
            sfRectangleShape_setOutlineColor(scene->buttons[i]->rect, sfGreen);
            sfText_setColor(scene->buttons[i]->text, sfGreen);
        }
    }
}

void check_events_types(sfEvent *event, scene_t *scene)
{
    sfVector2f click_position;

    click_position.x = event->mouseButton.x;
    click_position.y = event->mouseButton.y;
    if (event->type == sfEvtMouseButtonPressed)
        check_if_pressed_button(scene, click_position);
    else if (event->type == sfEvtMouseButtonReleased) {
        scene->is_dragging = 0;
        if (scene->turret != NULL) {
            scene->turret->display_range = 0;
            scene->turret->is_dragged = 0;
        }
        check_if_released_button(scene, click_position);
    }
}

void handle_events(sfRenderWindow *window, scene_t *scene)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        check_button_hover(scene, mouse_pos);
        check_events_types(&event, scene);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
