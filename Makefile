# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btomlins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:24:27 by btomlins          #+#    #+#              #
#    Updated: 2024/05/23 15:22:34 by btomlins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -gcc
RM		=	rm -f

INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

SRC		=	main.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

OBJ		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.c, $(SRCS))

all:		$(NAME)
