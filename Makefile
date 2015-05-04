##
## Makefile for lem-in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
## 
## Made by kevin lansel
## Login   <lansel_k@epitech.net>
## 
## Started on  Mon Apr  2 13:23:34 2012 kevin lansel
## Last update Fri Apr 27 14:58:03 2012 florian dewulf
##

NAME=		lem_in

SRC=		main.c		\
		game.c		\
		my_strlen.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_match.c	\
		get_next.c	\
		list_init.c	\
		add_to_end.c	\
		link_room.c	\
		way.c		\
		check.c		\
                check2.c	\
                check3.c	\
                check_link.c	\
                check_valid_pipe.c \
                comp.c		\
                concate.c	\
                alphasort.c	\
                error.c		\
                free_tab.c	\
                modif_pipe.c	\
                move.c		\
                str_to_wordtab.c \
                suppr.c		\
                tri.c		\
                xfunc.c		\
		my_road.c	\
		link_road.c	\
		check_road.c	\
		one_road.c	\
		two_road.c	\
		my_str_to_wordtab.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -g

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)
