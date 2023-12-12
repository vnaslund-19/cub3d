# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 16:46:17 by vnaslund          #+#    #+#              #
#    Updated: 2023/12/12 14:01:34 by vnaslund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3d
CFLAGS = -Wall -Wextra -Werror -g
LIBMLX  = ./MLX42
LIBFT   = ./libft

HEADERS = -I ./includes -I ${LIBMLX}/include -I ${LIBFT}
LIBGL   = -lglfw -L"/Users/vnaslund/.brew/opt/glfw/lib"
LIBS    = ${LIBGL} ${LIBFT}/libft.a ${LIBMLX}/build/libmlx42.a
SRCS    = main.c read_file.c playable.c fill_map.c mem.c explore.c
OBJS    = ${SRCS:.c=.o}

all: libmlx libft ${NAME}

libft:
	@echo "Compiling libft..."
	@${MAKE} -s -C ${LIBFT}
	@echo "libft compilation complete."

libmlx:
	@echo "Compiling MLX42..."
	@rm -rf $(LIBMLX)/build
	@cd $(LIBMLX) && mkdir -p build && cd build && cmake .. > /dev/null && make -s -j4 > /dev/null
	@echo "MLX42 compilation complete."

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

${NAME}: ${OBJS}
	@echo "Linking $@..."
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$@ compilation complete."

clean:
	@echo "Cleaning up object files..."
	@rm -f ${OBJS}
	@${MAKE} -s -C ${LIBFT} clean
	@${MAKE} -s -C ${LIBMLX}/build clean
	@echo "Cleanup complete."

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f ${NAME}
	@${MAKE} -s -C ${LIBFT} fclean
	@echo "Cleanup complete."

re: fclean all

.PHONY: all clean fclean re libmlx libft
