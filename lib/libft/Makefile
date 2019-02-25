# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:23:35 by fstadelw          #+#    #+#              #
#    Updated: 2018/11/30 18:42:58 by fstadelw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include include.mk

NAME	:=	$(LIBFT)

SRCDIR	:=	src
OBJDIR	:=	obj
DEPDIR	:=	dep
INCDIR	:=	inc

CC		:=	cc

INCFLAG	:= -I $(INCDIR)
STDFLAG	?=	-std=c11
WFLAGS	?=	-Wall -Wextra -Werror
CFLAGS	=	$(WFLAGS) $(INCFLAG) $(STDFLAG)

DEPGEN	:=	$(CC) $(INCFLAG)
DEPFLAG	=	-MM -MQ $@

AR		:=	ar
ARFLAGS	:=	rcs
SRC		:=	\
	ascii/ft_isalnum.c	\
	ascii/ft_isalpha.c	\
	ascii/ft_isascii.c	\
	ascii/ft_isdigit.c	\
	ascii/ft_islower.c	\
	ascii/ft_isprint.c	\
	ascii/ft_isspace.c	\
	ascii/ft_isupper.c	\
	ascii/ft_tolower.c	\
	ascii/ft_toupper.c	\
	\
	gnl/get_next_line.c	\
	\
	lst/ft_lstadd.c		\
	lst/ft_lstdelelem.c	\
	lst/ft_lstdel.c		\
	lst/ft_lstdelone.c	\
	lst/ft_lstiter.c	\
	lst/ft_lstmap.c		\
	lst/ft_lstnew.c		\
	\
	math/ft_abs.c		\
	math/ft_atoi.c		\
	math/ft_itoa.c		\
	math/ft_max.c		\
	math/ft_min.c		\
	math/ft_pow.c		\
	\
	mem/ft_bzero.c		\
	mem/ft_memalloc.c	\
	mem/ft_memccpy.c	\
	mem/ft_memchr.c		\
	mem/ft_memcmp.c		\
	mem/ft_memcpy.c		\
	mem/ft_memdel.c		\
	mem/ft_memmove.c	\
	mem/ft_memset.c		\
	\
	put/ft_putchar.c	\
	put/ft_putchar_fd.c	\
	put/ft_putendl.c	\
	put/ft_putendl_fd.c	\
	put/ft_putnbr.c		\
	put/ft_putnbr_fd.c	\
	put/ft_putstr.c		\
	put/ft_putstr_fd.c	\
	\
	str/ft_strcat.c		\
	str/ft_strchr.c		\
	str/ft_strclr.c		\
	str/ft_strcmp.c		\
	str/ft_strcpy.c		\
	str/ft_strcpy_s.c	\
	str/ft_strdel.c		\
	str/ft_strdup.c		\
	str/ft_strequ.c		\
	str/ft_striter.c	\
	str/ft_striteri.c	\
	str/ft_strjoin.c	\
	str/ft_strlcat.c	\
	str/ft_strlen.c		\
	str/ft_strlen_s.c	\
	str/ft_strmap.c		\
	str/ft_strmapi.c	\
	str/ft_strncat.c	\
	str/ft_strncmp.c	\
	str/ft_strncpy.c	\
	str/ft_strnequ.c	\
	str/ft_strnew.c		\
	str/ft_strnstr.c	\
	str/ft_strrchr.c	\
	str/ft_strsplit.c	\
	str/ft_strstr.c		\
	str/ft_strsub.c		\
	str/ft_strtrim.c	\
	str/ft_stridx.c

# File used as a command output buffer
TMP		:=	.tmp.txt

SRCLOCA	:=	$(shell find $(SRCDIR) -type d)
OBJLOCA	:=	$(subst $(SRCDIR), $(OBJDIR), $(SRCLOCA))
DEPLOCA	:=	$(subst $(SRCDIR), $(DEPDIR), $(SRCLOCA))

OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP		:=	$(addprefix $(DEPDIR)/, $(SRC:.c=.d))

ifdef TERM
RED			:=	"\033[1;31m"
GREEN		:=	"\033[0;32m"
BGREEN		:=	"\033[1;32m"
BLUE		:=	"\033[0;34m"
YELLOW		:=	"\033[0;33m"
PURPLE		:=	"\033[0;35m"
CYAN		:=	"\033[0;36m"
GREY		:=	"\033[0;37m"
# When printed reset the color
COLRESET	:=	"\033[0m"
endif

COMPCOLOR	:=	$(GREEN)
LINKCOLOR	:=	$(PURPLE)
KOCOLOR		:=	$(RED)
RMCOLOR		:=	$(GREY)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ $(AR) $(ARFLAGS) $(NAME) $(OBJ) &> $(TMP) && \
		(echo $(LINKCOLOR)[$(NAME)]$(COLRESET)"	: created" ; \
			cat $(TMP) ; rm $(TMP)) || \
		(echo $(KOCOLOR)[KO]$(COLRESET)"	: linkage fail" ; \
			cat $(TMP) ; rm $(TMP) ; exit 1)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR) $(DEPDIR)
	@$(CC) -c $< $(CFLAGS) -o  $@ &> $(TMP) && \
		(echo $(COMPCOLOR)[OK]$(COLRESET)"	: "$@ ; \
			cat $(TMP)) || \
		(echo $(KOCOLOR)[KO]$(COLRESET)"	: "$@ ; \
			cat $(TMP) ; rm $(TMP) ; exit 1)
	@$(DEPGEN) -c $< $(DEPFLAG) > $(subst $(SRCDIR), $(DEPDIR), $(<:.c=.d))

$(OBJDIR):
	@ mkdir -p $(OBJLOCA)

$(DEPDIR):
	@ mkdir -p $(DEPLOCA)

clean:
	@ rm -f $(TMP)
	@ rm -r $(OBJDIR) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" libft obj ; (exit 0)
	@ rm -r $(DEPDIR) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" libft dep ; (exit 0)

fclean:		clean
	@ rm $(NAME) &> /dev/null && \
		echo $(RMCOLOR)[CLR]$(COLRESET)"	:" $(NAME) ; (exit 0)

re:			fclean all

-include $(DEP)

.phony: all clean fclean re
