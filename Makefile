NAME = minirt

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

HEADER =	includes/minirt.h \
			includes/rt_parser.h \
			libgc/gc.h \
			libft/libft.h

INC_HEADERS =	-Iincludes

SRC = 		src/main.c	\
			parsing/rt_parsing.c \
			libgc/gc.c \
			libgc/gc_utils.c 

OBJ = $(SRC:.c=.o)

LIBFT_ARCHIVE = libft/libft.a

OBJ_DIR = $(patsubst %, obj/%, $(OBJ))

RM = rm -rf

all : mylibft $(NAME)

$(NAME): $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR) $(LIBFT_ARCHIVE) -o $(NAME)

obj/%.o : %.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_HEADER) -c $< -o $@

mylibft :
	make -C libft

clean :
	$(RM) obj
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : clean all fclean re mylibft
