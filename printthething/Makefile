NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
AR = ar crs
RM = rm -f
SOURCES = \ 
	ft_printf.c\
	ft_putchar.c\
	ft_put_percent.c\

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
