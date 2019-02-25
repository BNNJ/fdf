# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    include.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fstadelw <fstadelw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 17:23:35 by fstadelw          #+#    #+#              #
#    Updated: 2018/11/21 17:31:33 by fstadelw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPF		:=	libftprintf.a

LIBPF_PATH	?=	.

LIBPF_LINK	:= -L $(LIBPF_PATH) -l ftprintf
LIBPF_INC	:= -I $(LIBPF_PATH)/include

ifndef LIB_LINK
LIB_LINK	:=
LIB_INC		:=
endif

LIB_LINK	+= $(LIBPF_LINK)
LIB_INC		+= $(LIBPF_INC)
