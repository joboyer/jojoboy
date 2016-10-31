# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joboyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 16:08:41 by joboyer           #+#    #+#              #
#    Updated: 2016/02/12 14:19:29 by joboyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

H = libft.h

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_bzero.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memchr.c \
		ft_memdel.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_putchar.c \
		ft_memmove.c \
		ft_putchar_fd.c \
		ft_memset.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putstr.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putnbr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strchr.c \
		ft_strdel.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strequ.c \
		ft_strdup.c \
		ft_striter.c \
		ft_strlen.c \
		ft_striteri.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnew.c \
		ft_strnequ.c \
		ft_strrchr.c \
		ft_strsub.c \
		ft_strstr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strnstr.c \
		ft_strmapi.c \
		ft_strmap.c \
		ft_itoa.c \
		ft_strsplit.c \
		get_next_line.c

OBJ = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME):
	@echo "\033[0;31mCompilation des sources...\033[0m"
	$(CC) $(FLAGS) -include $(H) -c $(SRCS)
	@echo  "\033[0;31mCreation de la librairie...\033[0m"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo  "\033[0;32mLibrairie cree avec succes\033[0m"

clean : $(SRC:%.c=%.o)
	@rm -rf $(OBJ)
	@echo "\033[0;32mFichiers objets supprimes\033[0m"

fclean: clean
	rm -rf $(NAME)
	@echo "\033[0;32mLibrairie supprimee\033[0m"

re : fclean all
