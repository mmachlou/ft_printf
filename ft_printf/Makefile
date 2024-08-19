NAME = libftprintf.a

SOURCES = 	ft_printf.c ft_print_hex.c \
			ft_print_ptr.c ft_print_unsigned.c \
			ft_print_tools.c ft_print_libft.c

OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $@ $^

%.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re