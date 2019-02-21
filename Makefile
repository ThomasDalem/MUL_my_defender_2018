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

SRCS		=	$(SRCSPATH)main.c		\
			$(SRCSPATH)button_init.c	\
			$(SRCSPATH)button_states.c	\
			$(SRCSPATH)button_destroy.c	\
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
