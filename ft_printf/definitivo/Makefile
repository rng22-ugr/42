NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar crs
RM = rm -f
SOURCES = \
	ft_itoa.c\
	ft_print_dec.c\
	ft_printf.c\
	ft_print_hex.c\
	ft_print_percent.c \
	ft_print_ptr.c\
	ft_print_str.c\
	ft_print_unsigned.c\
	ft_putchar.c\
	ft_uitoa.c\



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
