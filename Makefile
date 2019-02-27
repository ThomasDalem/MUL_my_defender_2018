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

SRCS		=	$(SRCSPATH)main.c			    \
			$(BUTTONSFILE)button_init.c		    \
			$(BUTTONSFILE)button_states.c		    \
			$(BUTTONSFILE)buttons_callbacks.c	    \
			$(BUTTONSFILE)button_add_sprite.c	    \
			$(TURRETSFILE)draw_turrets.c		    \
			$(TURRETSFILE)create_turrets.c		    \
			$(SCENEFILE)create_scene_main_menu.c	    \
			$(SCENEFILE)create_test_scene.c		    \
			$(SCENEFILE)scene_free.c		    \
			$(SCENEFILE)draw_scene.c		    \
			$(SRCSPATH)create_checkpoints.c		    \
			$(ENEMIESFILE)create_enemy.c		    \
			$(ENEMIESFILE)enemies_free.c		    \
			$(SRCSPATH)test_scene.c			    \
			$(ENEMIESFILE)enemy_movement.c		    \
			$(SRCSPATH)main_menu.c			    \
			$(SRCSPATH)handle_events.c		    \
			$(SRCSPATH)follow_mouse.c		    \
			$(SRCSPATH)create_object.c		    \
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
