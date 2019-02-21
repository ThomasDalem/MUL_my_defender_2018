/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_defender header
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Graphics/RectangleShape.h>

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    void (*callback)();
    void (*hover)(struct button_s *button);
} button_t;

sfRenderWindow *create_window(int width, int height);
void init_button(button_t *button ,sfVector2f position, sfVector2f size);
void print_hello(void);
void button_destroy(button_t *button);

// Button states
int button_is_clicked(button_t *button, sfVector2f click_position);
int button_is_hovered(button_t *button, sfVector2i mouse_position);

#endif /* !MY_DEFENDER_H_ */
