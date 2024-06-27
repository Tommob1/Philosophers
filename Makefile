# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btomlins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:24:27 by btomlins          #+#    #+#              #
#    Updated: 2024/06/27 13:38:50 by btomlins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -gcc
RM		=	rm -f

INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

SRC		=	main.c \
			utils.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

OBJ		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.c, $(SRCS))

all:		$(NAME)

$(NAME):	$(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
									@mkdir -p $(@D)
									@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)

fclean:	clean
			@$(RM) $(NAME)
			@$(RM) src/a.out

re:

.PHONY:		all clean fclean re leaks valgrind_leaks help

