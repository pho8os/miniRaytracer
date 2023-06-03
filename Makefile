NAME = minirt

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

HEADER = includes/minirt.h includes/rt_parser.h libgc/gc.h libft/libft.h

SRC =  main.c	parsing/rt_parsing.c libgc/gc.c libgc/gc_utils.c \

OBJ = $(SRC:.c=.o)



all : $(NAME) mylibft

mylibft : 
	make -C libft

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HEADER) mylibft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

re : fclean all

.PHONY : clean all fclean re mylibft