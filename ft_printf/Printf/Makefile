NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar crs
RM = rm -f
SOURCES = \
	ft_printf.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putint.c \
	ft_putpercent.c \
	ft_putptr.c \
	ft_print_str.c \
	ft_uitoa.c \
	ft_puthex.c\
	ft_putunsigned.c\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
