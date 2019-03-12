##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

CC		=	gcc

CFLAGS		=	-g3 -Wall -Wextra

INCLUDES	=	-I./include/

CSFMLINCLUDES	=	-lcsfml-graphics -lcsfml-system

RM		=	rm -f

SRCSPATH	=	./srcs/

PRINTLIBPATH	=	$(SRCSPATH)libs/PSU_my_printf_2018

STRLIBPATH	=	$(SRCSPATH)libs/strlib/

INCLUDELIB	=	-L$(PRINTLIBPATH) -lmy

BUTTONSFILE	=	$(SRCSPATH)buttons/

SCENEFILE	=	$(SRCSPATH)scenes/

ENEMIESFILE	=	$(SRCSPATH)enemies/

TURRETSFILE	=	$(SRCSPATH)turrets/

MONEYPATH	=	$(SRCSPATH)money/

HEALTHPATH	=	$(SRCSPATH)healthbar/

SRCS		=	$(SRCSPATH)main.c			    \
			$(BUTTONSFILE)button_init.c		    \
			$(BUTTONSFILE)button_states.c		    \
			$(BUTTONSFILE)buttons_callbacks.c	    \
			$(BUTTONSFILE)button_add_sprite.c	    \
			$(BUTTONSFILE)assign_button_turret.c	    \
			$(BUTTONSFILE)drag_buttons_callbacks.c	    \
			$(TURRETSFILE)draw_turrets.c		    \
			$(TURRETSFILE)create_turrets.c		    \
			$(TURRETSFILE)free_turrets.c		    \
			$(TURRETSFILE)turrets_shooting.c	    \
			$(SCENEFILE)create_scene_main_menu.c	    \
			$(SCENEFILE)create_test_scene.c		    \
			$(SCENEFILE)scene_free.c		    \
			$(SCENEFILE)draw_scene.c		    \
			$(SCENEFILE)test_scene.c		    \
			$(SRCSPATH)create_checkpoints.c		    \
			$(ENEMIESFILE)create_enemy.c		    \
			$(ENEMIESFILE)enemies_free.c		    \
			$(ENEMIESFILE)enemy_movement.c		    \
			$(ENEMIESFILE)remove_dead_enemies.c	    \
			$(SRCSPATH)main_menu.c			    \
			$(SRCSPATH)handle_events.c		    \
			$(SRCSPATH)follow_mouse.c		    \
			$(SRCSPATH)create_object.c		    \
			$(SRCSPATH)free_checkpoints.c		    \
			$(SRCSPATH)init_castle.c		    \
			$(HEALTHPATH)draw_castle_health.c	    \
			$(HEALTHPATH)init_health_bar.c		    \
			$(HEALTHPATH)draw_health_bar.c		    \
			$(HEALTHPATH)move_health_bar.c		    \
			$(HEALTHPATH)free_healthbar.c		    \
			$(MONEYPATH)init_money.c		    \
			$(MONEYPATH)display_money.c		    \
			$(MONEYPATH)free_money.c		    \
			$(STRLIBPATH)my_getnbr.c		    \
			$(STRLIBPATH)my_strlen.c		    \
			$(STRLIBPATH)my_strcat.c		    \
			$(STRLIBPATH)my_int_to_str.c		    \
			$(STRLIBPATH)my_revstr.c		    \
			$(SRCSPATH)create_window.c

NAME		=	my_defender

all: $(NAME)

$(NAME):
	make -C $(PRINTLIBPATH)
	$(CC) -o $(NAME) $(SRCS) $(CFLAGS) $(INCLUDELIB) $(INCLUDES) $(CSFMLINCLUDES)

clean:
	make clean -C $(PRINTLIBPATH)

fclean: clean
	make fclean -C $(PRINTLIBPATH)
	$(RM) $(NAME)

re: fclean all
