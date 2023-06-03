NAME = minirt

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

HEADER =	includes/minirt.h \
			includes/rt_parser.h \
			libgc/gc.h \
			libft/libft.h

SRC = 		main.c	\
			parsing/rt_parsing.c \
			libgc/gc.c \
			libgc/gc_utils.c 

OBJ = $(SRC:.c=.o)

LIBFT_ARCHIVE = libft/libft.a

RM = rm -rf

all : mylibft $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_ARCHIVE) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

mylibft :
	make -C libft

clean :
	$(RM) $(OBJ)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : clean all fclean re mylibft
