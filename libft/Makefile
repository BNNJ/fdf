.PHONY: all clean fclean re

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR 	=	SRC_DISP SRC_CONV SRC_MEM SRC_LIST SRC_STR SRC_TSTR SRC_MISC 


SRC = 			$(addprefix $(DIR_DISP), $(SRC_DISP)) 	\
				$(addprefix $(DIR_CONV), $(SRC_CONV))	\
				$(addprefix $(DIR_STR), $(SRC_STR))		\
				$(addprefix $(DIR_TSTR), $(SRC_TSTR))	\
				$(addprefix $(DIR_MEM), $(SRC_MEM))		\
				$(addprefix $(DIR_LIST), $(SRC_LIST))	\
				$(addprefix $(DIR_MISC), $(SRC_MISC))

SRCS 		=	$(addprefix ./srcs/, $(SRC))


DIR_DISP	=	display/
SRC_DISP	=	ft_putchar.c		\
				ft_putchar_fd.c		\
				ft_putendl.c		\
				ft_putendl_fd.c		\
				ft_putnbr.c			\
				ft_putnbr_fd.c		\
				ft_putstr.c			\
				ft_putstr_fd.c

DIR_CONV	=	conversion/
SRC_CONV	=	ft_atoi.c			\
				ft_itoa.c			\
				ft_lltoa_base.c		\
				ft_ulltoa_base.c

DIR_STR		=	string/
SRC_STR		=	ft_strdup.c			\
				ft_strdup_s.c		\
				ft_strcat.c			\
				ft_strcmp.c			\
				ft_strcpy.c			\
				ft_strlcat.c		\
				ft_strlen.c			\
				ft_strlen_s.c		\
				ft_strncat.c		\
				ft_strncmp.c		\
				ft_strncpy.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strclr.c			\
				ft_strdel.c			\
				ft_strequ.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strjoin_f.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strnequ.c		\
				ft_strnew.c			\
				ft_strsplit.c		\
				ft_strsub.c			\
				ft_strsub_f.c		\
				ft_strtrim.c		\
				ft_strchr.c			\
				ft_findchar.c		\
				ft_strchrs.c		\
				ft_strchrsp.c		\
				get_next_line.c

DIR_MEM		=	memory/
SRC_MEM		=	ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_memccpy.c		\
				ft_bzero.c

DIR_TSTR	=	tstr/
SRC_TSTR	=	ft_tstr_new.c		\
				ft_tstr_del.c		\
				ft_tstr_clr.c		\
				ft_tstr_dup.c		\
				ft_tstr_clr.c		\
				ft_tstr_sub.c		\
				ft_tstr_join.c		\
				ft_tstr_print.c		\
				ft_tstr_to_str.c	\
				ft_tstr_findchar.c	\
				ft_tstr_cmp.c		\
				ft_tstr_eq.c

DIR_LIST	=	list/
SRC_LIST	=	ft_lstnew.c			\
				ft_lstadd.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_print_addr.c

DIR_MISC	=	misc/
SRC_MISC	=	ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_tolower.c		\
				ft_toupper.c

OBJ_DIR		=	./obj/
OBJ			=	$(SRC_CONV:.c=.o) \
				$(SRC_DISP:.c=.o) \
				$(SRC_TSTR:.c=.o) \
				$(SRC_STR:.c=.o) \
				$(SRC_LIST:.c=.o) \
				$(SRC_MISC:.c=.o) \
				$(SRC_MEM:.c=.o) 

OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ))


INC_DIR		=	./includes/
INCS		=	$(addprefix $(INC_DIR), $(INC))
INC			=	libft.h

all: $(NAME) 

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo compiling libft...
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: ./srcs/$(DIR_MISC)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_LIST)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_TSTR)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_STR)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_MEM)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_DISP)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)%.o: ./srcs/$(DIR_CONV)%.c $(INCS) 
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo cleaning objects

fclean: clean
	@rm -f $(NAME)
	@echo cleaning binary

re: fclean all
