
NAME = libftprintf.a


CC = cc
CFLAGS = -Wall -Wextra -Werror


AR = ar rcs
RM = rm -f


SRC = ft_printf.c ft_check.c ft_putadress.c ft_putchar.c ft_puthex.c \
      ft_puthex_m.c ft_putnbr.c ft_putunbr.c ft_putstr.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re