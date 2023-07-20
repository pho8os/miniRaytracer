
NAME = minirt

CC = cc

SRC =	src/main.c \
		src/utils.c \
		\
		libgc/gc.c \
		libgc/gc_utils.c\
		\
		parsing/parse_ranges.c \
		parsing/parsecam.c \
		parsing/parsecy.c \
		parsing/parselights.c \
		parsing/parseplane.c \
		parsing/parsesp.c \
		parsing/rt_parsing.c \
		parsing/utils_pars.c \
		\
		render/vector_calculations.c \
		render/ft_rays.c \
		render/rt_render.c \
		render/rendering_utils.c \
		render/colors.c \
		render/light.c \
		render/ray_plane_intersection.c \
		render/ray_cylinder_intersection.c \
		render/ray_sphere_intersection.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ilibgc -fsanitize=address -g

INC_HEADERS =	-Iincludes

LIBFT_ARCHIVE = libft/libft.a

OBJS = $(patsubst %, obj/%, $(SRC:.c=.o))

DEPS = $(OBJS:%.o=%.d)

RM = rm -rf

all : mylibft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

# -MMD	: generate dependencies as a prerequisite for the rule
# -MP	: The files generated are added to .PHONY rule

obj/%.o : %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

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

#include "Dependency Files"
-include $(DEPS)