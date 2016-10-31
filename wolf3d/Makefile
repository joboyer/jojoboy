NAME = wolf3d

CC = gcc 

FLAG = -Wall -Wextra -Werror

FLAG2 = -framework OpenGL -framework Appkit

SRC =  wolf_main.c \
	   option1.c \
	   option2.c \
	   option3.c \
	   option4.c \
	   option5.c \
	   open_wind.c \

POINTA = ./libft

POINTM = ./minilibx_macos/libmlx.a

SRCO = $(SRC:%.c=%.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
		cd ./libft/; make
		cd ./minilibx_macos/; make
		$(CC) $(FLAG) -c $(SRC)
		$(CC) $(FLAG) $(FLAG2) $(SRCO) -o $(NAME) $(POINTM) -L $(POINTA) -l ft
		@echo  "\033[0;32mExecutable WOLF3D cree avec succes\033[0m"
							        
clean:
		cd ./libft/; make clean
		cd ./minilibx_macos/; make clean
		/bin/rm -f $(SRCO)

					        
fclean: clean
		cd ./libft/; make fclean
		/bin/rm -f $(NAME)
					        
re: fclean all
