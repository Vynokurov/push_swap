# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/09 17:07:23 by dvynokur          #+#    #+#              #
#    Updated: 2017/01/27 17:03:01 by dvynokur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = libft.h

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memcpy.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memset.c ft_memccpy.c\
		ft_strcat.c ft_strchr.c ft_strcpy.c ft_strlcat.c ft_strdup.c ft_strlen.c\
		ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strcmp.c\
		ft_strncmp.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strncat.c ft_memalloc.c\
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
		ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c\
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
		get_next_line.c

OFILES = $(SRC:.c=.o)

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@ar rc $(NAME) $(OFILES) $(HEADER)
	@echo "\x1b[32m"libft has been made "\x1b[0m"

$(NAME): $(OFILES)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: clean all
