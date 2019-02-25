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

typedef struct scene_s {
    int is_dragging;
    sfRenderWindow *window;
    struct button_s **buttons;
    struct game_object_s *objects;
} scene_t;

typedef struct button_s {
    int is_draggable;
    sfRectangleShape *rect;
    sfTexture *texture;
    sfTexture *obj_texture;
    sfSprite *obj_sprite;
    sfFont *font;
    sfText *text;
    void (*callback)(struct scene_s *scene);
    void (*hover)(struct button_s *button);
} button_t;

typedef struct game_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    struct game_object_s *next;
} game_object_t;

sfRenderWindow *create_window(int width, int height);
void init_button(button_t *button ,sfVector2f position, sfVector2f size);
void button_destroy(button_t *button);
void button_set_text(button_t *button, char *text);
void handle_events(sfRenderWindow *window, scene_t *scene);
void draw_scene(sfRenderWindow *window, scene_t *scene);
int close_window(int add);
void free_scene(scene_t *scene);
void button_add_sprite(button_t *button, char const *filepath);
void follow_mouse(scene_t *scene);
void change_is_dragging(scene_t *scene);
void create_object(scene_t *scene);

// Test functions
void print_hello(scene_t *scene);

// Scenes
int main_menu(sfRenderWindow *window);
int test_scene(sfRenderWindow *window);

// Scenes creation
scene_t *create_scene_test(void);
scene_t *create_scene_main_menu(void);

// Button callbacks
void play(scene_t *scene);
void quit(scene_t *scene);

// Button states
int button_is_clicked(button_t *button, sfVector2f click_position);
int button_is_hovered(button_t *button, sfVector2i mouse_position);

#endif /* !MY_DEFENDER_H_ */
