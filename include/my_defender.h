/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** my_defender header
*/

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfFont *font;
    sfText *text;
    void (*callback)();
    void (*hover)(struct button_s *button);
} button_t;

typedef struct game_object_s {
    sfTexture *texture;
    sfSprite *sprite;
} game_object_t;

typedef struct scene_s {
    button_t **buttons;
    game_object_t **objects;
} scene_t;

sfRenderWindow *create_window(int width, int height);
void init_button(button_t *button ,sfVector2f position, sfVector2f size);
void print_hello(void);
void button_destroy(button_t *button);
void button_set_text(button_t *button, char *text);
void handle_events(sfRenderWindow *window, scene_t *scene);
void draw_scene(sfRenderWindow *window, scene_t *scene);
scene_t *create_scene_main_menu(void);
int close_window(int add);
void free_scene(scene_t *scene);
void free_button(button_t *button);

// Button callbacks
void quit(void);

// Button states
int button_is_clicked(button_t *button, sfVector2f click_position);
int button_is_hovered(button_t *button, sfVector2i mouse_position);

#endif /* !MY_DEFENDER_H_ */
