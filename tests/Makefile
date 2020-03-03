##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

SRC_MAIN	=	test_basics.c		\

SRC		=	../src/my/my_putstr.c 		\
			../src/my/my_putchar.c 		\
			../src/my/my_atoi.c 		\
			../src/my/my_strlen.c 		\
			../src/my/concat.c 			\
			../src/my/convert.c 		\
			../src/my/my_revstr.c 		\
			../src/my/my_strdup.c 		\

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

OBJ_SRC		=	$(SRC:.c=.o)

NAME		=	unit_test

CC			=	gcc -Wno-deprecated

override CFLAGS		+=	-Wall -Wextra -Werror -I ../include --coverage

$(NAME):$(OBJ_MAIN) $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) $(OBJ_MAIN) -o $(NAME) -lcriterion
	./unit_test

all:$(NAME)

clean:
	@rm -rf $(OBJ_MAIN) $(OBJ_SRC) *.gcno *.gcda

fclean: clean
	@rm -f $(NAME)

re:	fclean	all

tests_run: all

.PHONY:	all	clean	fclean	tests_run
