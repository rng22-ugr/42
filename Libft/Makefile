# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 20:25:44 by dapachec          #+#    #+#              #
#    Updated: 2024/12/27 17:42:07 by ranavarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

Sources = ft_isdigit.c\
	ft_isalpha.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c

OBJ = $(Sources:.c=.o)

OBJbonus = $(sourcesbonus:.c=.o)

flags = -Wall -Wextra -Werror

all:$(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:$(OBJbonus) $(OBJ)
	ar rcs $(NAME) $(OBJ) $(OBJbonus)

$(OBJ): $(Sources)
	gcc -c $(Sources) -Includes $(flags)

$(OBJbonus): $(sourcesbonus)
	gcc -c $(sourcesbonus) -Includes $(flags)

clean:
	rm -f $(OBJ)
	rm -f $(OBJbonus)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
