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
#include <SFML/System/Clock.h>

typedef struct scene_s {
    int money;
    int is_dragging;
    sfRenderWindow *window;
    sfTexture *background;
    sfSprite *background_sprite;
    struct button_s **buttons;
    struct turret_s *turret;
    struct enemy_s *enemies;
    struct checkpoint_s *checkpoints;
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

typedef struct health_bar_s {
    sfRectangleShape *red_bar;
    sfRectangleShape *green_bar;
} health_bar_t;

typedef struct checkpoint_s {
    sfVector2f pos;
    sfTexture *texture;
    sfSprite *sprite;
    struct checkpoint_s *next;
} checkpoint_t;

typedef struct turret_s {
    unsigned int display_range;
    unsigned int range;
    unsigned int is_dragged;
    float fire_rate;
    sfCircleShape *range_circle;
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    struct enemy_s *target;
    struct turret_s *next;
} turret_t;

typedef struct enemy_s {
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    int health;
    health_bar_t *health_bar;
    checkpoint_t *next_checkpoint;
    struct enemy_s *next;
} enemy_t;

typedef struct castle_s {
    int health;
    health_bar_t *health_bar;
} castle_t;

sfRenderWindow *create_window(int width, int height);
void init_button(button_t *button ,sfVector2f position, sfVector2f size);
void button_destroy(button_t *button);
void button_set_text(button_t *button, char *text);
void handle_events(sfRenderWindow *window, scene_t *scene);
void draw_scene(sfRenderWindow *window, scene_t *scene, castle_t *castle);
int close_window(int add);
void free_scene(scene_t *scene);
void button_add_sprite(button_t *button, char const *filepath);
void follow_mouse(scene_t *scene);
void change_is_dragging(scene_t *scene);
void create_object(scene_t *scene);
checkpoint_t *create_checkpoints(void);
void free_checkpoints(checkpoint_t *checkpoints);
health_bar_t *create_health_bar(sfVector2f size, sfVector2f pos);
void draw_health(health_bar_t *health_bar, int health, sfRenderWindow *window);
void move_health_bar(health_bar_t *health_bar, sfVector2f pos);

//Enemies functions
enemy_t *create_enemies(checkpoint_t *checkpoints);
void move_enemies(enemy_t *enemies);
void free_enemy(enemy_t *enemy);
void free_enemies(enemy_t *enemies);
void remove_dead_enemies(scene_t *scene);

// Turrets functions
void free_turrets(turret_t *turrets);
void draw_turrets(turret_t *turret, sfRenderWindow *window);
int create_turret(turret_t **turrets);
int turrets_shooting(turret_t *turret, enemy_t *enemy);

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

// Castle functions
castle_t *init_castle(void);
void draw_castle_health(castle_t *castle, sfRenderWindow *window);

#endif /* !MY_DEFENDER_H_ */
