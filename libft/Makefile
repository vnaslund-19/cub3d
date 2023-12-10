NAME = libft.a

SOURCES = \
	ft_strlen.c ft_bzero.c ft_calloc.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c format.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $(NAME) $?

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
