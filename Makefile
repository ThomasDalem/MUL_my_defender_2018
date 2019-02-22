##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

CC		=	gcc

CFLAGS		=	-g3 -Wall -Wextra

INCLUDES	=	-I./include/

CSFMLINCLUDES	=	-lcsfml-graphics

RM		=	rm -f

SRCSPATH	=	./srcs/

PRINTLIBPATH	=	$(SRCSPATH)libs/PSU_my_printf_2018

STRLIBPATH	=	$(SRCSPATH)libs/strlib/

INCLUDELIB	=	-L$(PRINTLIBPATH) -lmy

SRCS		=	$(SRCSPATH)main.c		    \
			$(SRCSPATH)button_init.c	    \
			$(SRCSPATH)button_states.c	    \
			$(SRCSPATH)handle_events.c	    \
			$(SRCSPATH)draw_scene.c		    \
			$(SRCSPATH)create_scene_main_menu.c \
			$(SRCSPATH)buttons_callbacks.c	    \
			$(SRCSPATH)button_free.c	    \
			$(SRCSPATH)scene_free.c		    \
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
