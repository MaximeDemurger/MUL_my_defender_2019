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

MENU = 		src/menu/init_start.c 				\
			src/menu/starting_menu.c			\
			src/menu/pause_menu.c 				\
			src/menu/init_death.c 				\
			src/menu/death_menu.c 				\
			src/menu/init_settings.c 			\
			src/menu/settings_menu.c 			\
			src/menu/init_select.c 				\
			src/menu/show_map_options.c 		\

MY =		src/my/get_next_line.c				\
			src/my/my_strdup.c					\
			src/my/my_atoi.c					\
			src/my/my_strlen.c					\
			src/my/my_putchar.c 				\
			src/my/my_putstr.c					\
			src/my/convert.c					\
			src/my/my_revstr.c 					\
			src/my/concat.c 					\

MAP =		src/map/init_map.c					\
			src/map/getting_map.c				\
			src/map/print_map.c					\
			src/map/checking_map.c				\
			src/map/get_maps.c 						\

GAME =		src/game/init_play.c							\
			src/game/find_line_col.c						\
			src/game/start_gameplay.c						\
			src/game/get_pos_case.c							\
			src/game/tower_folder/tower_set.c				\
			src/game/tower_folder/range_tower.c				\
			src/game/tower_folder/tower1_file.c				\
			src/game/tower_folder/tower2_file.c				\
			src/game/tower_folder/tower3_file.c				\
			src/game/tower_folder/tower4_file.c				\
			src/game/tower_folder/tower_shot.c				\

ENEMY =		src/enemy/create_enemy.c 			\
			src/enemy/enemy.c 					\
			src/enemy/get_path.c				\
			src/enemy/enemy_movements.c 		\
			src/enemy/attack_castle.c			\
			src/enemy/enemy_hit.c				\

HUD =		src/hud/init_hud.c 					\
			src/hud/draw_hud.c 					\

DESTROY =	src/destroy/destroy_allmaps.c 		\
			src/destroy/destroy_game.c 			\
			src/destroy/destroy_menu.c 			\
			src/destroy/destroy_death.c 		\
			src/destroy/destroy_path.c 			\
			src/destroy/destroy_selection.c 	\
			src/destroy/destroy_settings.c 		\

SRCS	= 	src/main.c 							\
			src/open_window.c 					\
			src/capture_event.c 				\
			src/event_tower.c					\
			$(DESTROY)							\
			$(HUD)								\
			$(ENEMY)							\
			$(GAME) 							\
			$(MAP) 								\
			$(MY)								\
			$(MENU)								\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Wno-deprecated

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
