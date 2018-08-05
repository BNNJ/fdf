NAME		=	fdf

# Path

SRC_DIR		=	./src/

OBJ_DIR		=	./obj/

CPPFLAGS	=	-I./include/

# Files

SRC_NAME	=	fdf.c				\
				bresenham.c			\
				xiaolin_wu.c		\
				parser.c			\
				plot.c	\
				groundcontrol.c		\
				magic_stuff.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_NAME	=	$(SRC_NAME:.c=.o)

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

# Flags

LDFLAGS		=	-L./libft/

LFT			=	-lft

CC			=	gcc $(CFLAGS)

CFLAGS		=	-Wall -Wextra -Werror

MLX			=	-lmlx -framework OpenGL -framework AppKit

# Rules

all:			$(NAME)

$(NAME):		$(OBJ)
	@make -C./libft/
	@$(CC) $(LDFLAGS) $(LFT) $(OBJ) -o $@ $(MLX)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C ./libft/
	@rm -rf $(OBJ_DIR)

fclean:			clean
	@make fclean -C ./libft/
	@rm -f $(NAME)

re:				fclean all

.PHONY: all, clean, fclean, re
