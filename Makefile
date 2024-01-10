# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:46:17 by vnaslund          #+#    #+#              #
#    Updated: 2024/01/10 15:48:42 by vnaslund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
CFLAGS  = -Wall -Wextra -Werror -g
LIBMLX  = ./MLX42
LIBMLX_A = $(LIBMLX)/build/libmlx42.a
LIBFT   = ./libft
LIBFT_A = $(LIBFT)/libft.a

HEADERS = -I ./includes -I ${LIBMLX}/include -I ${LIBFT}
LIBGL   = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
LIBS    = ${LIBGL} $(LIBFT_A) ${LIBMLX}/build/libmlx42.a

SRCS    = main.c parsing/read_file.c parsing/playable.c parsing/file_check.c \
          parsing/fill_map.c parsing/explore.c \
          memory_handling/exit_handler.c  memory_handling/end_game.c debug.c

OBJ_DIR = obj/
OBJS    = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: libmlx libft $(NAME)

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

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT) clean
	@$(MAKE) -s -C $(LIBMLX)/build clean
	@echo "Cleanup complete."

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT) fclean
	@echo "Cleanup complete."

re: fclean all

.PHONY: all clean fclean re
