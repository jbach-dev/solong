# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbach <jbach@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 16:52:33 by jbach             #+#    #+#              #
#    Updated: 2022/03/20 17:21:49 by jbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
UNAME = $(shell uname -s)
CC=gcc

ifeq ($(UNAME), Linux)
	MINILIBX_SRC = -I/usr/include -Imlx_linux -O3
	MINILIBX_OBJ = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MINILIBX_SRC = -Imlx 
	MINILIBX_OBJ = -Lmlx -lmlx -framework OpenGL -framework AppKit
	MLX = ./mlx/libmlx.a
endif

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRCS = main.c\
move/ft_move_right.c\
move/ft_move_left.c\
move/ft_move_up.c\
move/ft_move_down.c\
map/ft_read_map.c\
map/ft_init_map.c\
map/ft_imgtofile.c\
map/ft_imgtowindow.c\
map/ft_img_new_position.c\
verif/ft_verif_params_map.c\
verif/ft_verif_params_argu.c\
gnl/get_next_line.c\
gnl/get_next_line_utils.c\
utils/ft_utils.c\
utils/ft_close.c\
utils/ft_itoa.c\
utils/ft_fnct_utils.c\
move/ft_event_key.c

SRCS_BONUS = bonus/main_bonus.c\
bonus/move/ft_move_right_bonus.c\
bonus/move/ft_move_left_bonus.c\
bonus/move/ft_move_up_bonus.c\
bonus/move/ft_move_down_bonus.c\
bonus/move/ft_event_key_bonus.c\
bonus/map/ft_read_map_bonus.c\
bonus/map/ft_init_map_bonus.c\
bonus/map/ft_imgtofile_bonus.c\
bonus/map/ft_imgtowindow_bonus.c\
bonus/map/ft_img_new_position_bonus.c\
bonus/verif/ft_verif_params_map_bonus.c\
bonus/verif/ft_verif_params_argu_bonus.c\
bonus/gnl/get_next_line_bonus.c\
bonus/gnl/get_next_line_utils_bonus.c\
bonus/utils/ft_utils_bonus.c\
bonus/utils/ft_close_bonus.c\
bonus/utils/ft_itoa_bonus.c\
bonus/utils/ft_fnct_utils_bonus.c\
bonus/write_on_screen/ft_write_screen_bonus.c

OBJETS = ${SRCS:.c=.o}

OBJETS_BONUS = ${SRCS_BONUS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJETS) $(MLX)
	$(CC) $(OBJETS) $(MINILIBX_OBJ) -o $@

$(MLX):
	$(MAKE) -C $(@D) $(@F)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJETS_BONUS) $(MLX)
	$(CC) $(OBJETS_BONUS) $(MINILIBX_OBJ) -o $@

clean: 
	$(RM) $(OBJETS) $(OBJETS_BONUS) $(MLX)

fclean: clean 
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
