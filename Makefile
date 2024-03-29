# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:46:17 by vnaslund          #+#    #+#              #
#    Updated: 2024/01/24 16:14:22 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
BONUS	= cub3d_bonus

CFLAGS  = -Wall -Wextra -Werror -g

LIBMLX  = ./MLX42
LIBMLX_A = $(LIBMLX)/build/libmlx42.a
LIBFT   = ./libft
LIBFT_A = $(LIBFT)/libft.a

HEADERS = -I ./includes -I ${LIBMLX}/include -I ${LIBFT}
LIBGL   = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
LIBS    = ${LIBGL} $(LIBFT_A) ${LIBMLX}/build/libmlx42.a

SRCS    = main.c parsing/read_file.c parsing/playable.c parsing/file_check.c \
          parsing/fill_map.c parsing/explore.c exit_handler.c \
		  game/init_game.c game/hooks.c game/move.c game/rotate.c \
		  game/raycasting/draw.c  game/raycasting/raycast.c \
		  game/raycasting/angles.c game/raycasting/raycasting_utils.c \
		  game/raycasting/raycasting_each_pixel.c \

BSRCS	= main.c parsing/read_file.c parsing/playable.c parsing/file_check.c \
          parsing/fill_map.c parsing/explore.c exit_handler.c \
		  game/init_game.c game/hooks.c game/move_bonus.c game/rotate.c \
		  game/raycasting/draw.c  game/raycasting/raycast.c \
		  game/raycasting/angles.c game/raycasting/raycasting_utils.c \
		  game/raycasting/raycasting_each_pixel.c \

OBJ_DIR = obj/
OBJS    = $(SRCS:%.c=$(OBJ_DIR)%.o)
BOBJS	= $(BSRCS:%.c=$(OBJ_DIR)%.o)

all: libmlx libft $(NAME)
bonus: libmlx libft $(BONUS)

libft: $(LIBFT_A)

$(LIBFT_A):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT) > /dev/null 2>&1
	@echo "libft compilation complete."

libmlx: $(LIBMLX_A)

$(LIBMLX_A):
	@echo "Compiling MLX42..."
	@rm -rf $(LIBMLX)/build
	@cd $(LIBMLX) && mkdir -p build && cd build && cmake .. > /dev/null && make -s -j4 > /dev/null
	@echo "MLX42 compilation complete."

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$@ compilation complete."

$(BONUS): $(BOBJS)
	@echo "Linking $@..."
	@$(CC) $(BOBJS) $(LIBS) $(HEADERS) -o $(BONUS)
	@echo "$@ compilation complete."

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(LIBMLX)/build clean
	@echo "Cleanup complete."

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -s -C $(LIBFT) fclean
	@echo "Cleanup complete."

re: fclean all

.PHONY: all clean fclean re bonus
