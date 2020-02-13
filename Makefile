##
## EPITECH PROJECT, 2019
## lemin
## File description:
## Makefile
##

NAME	= my_defender

CC	= gcc

RM	= rm -f

TESTS	= $(wildcard src/*.g*)

SRCS	= 	src/main.c 							\
			src/open_window.c 					\
			src/capture_event.c 				\
			src/my/my_putchar.c 				\
			src/my/my_putstr.c					\
			src/menu/init_start.c 				\
			src/menu/starting_menu.c			\
			src/menu/pause_menu.c 				\
			src/menu/init_death.c 				\
			src/menu/death_menu.c 				\
			src/destroy/destroy_game.c 			\
			src/destroy/destroy_menu.c 			\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TESTS)
tests_run:
	@make -C tests/ tests_run

re: fclean all

.PHONY: all clean fclean re
