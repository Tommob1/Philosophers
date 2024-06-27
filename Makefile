# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btomlins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:24:27 by btomlins          #+#    #+#              #
#    Updated: 2024/06/27 13:45:23 by btomlins         ###   ########.fr        #
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

re:			fclean all

.PHONY:		all clean fclean re leaks valgrind_leaks help

leaks: re
		@echo "\033[1;33m\nTesting for memory leaks...\003[0m"
		leaks --atExit -- ./$(NAME) 5 800 200 3

valgrind_leaks: re
		@echo "\033[1;33m\nTesting for memory leaks with valgrind...\033[0m"
		valgrind --leak-check=full ./$(NAME) 5 800 200 3

help:
		@echo "\033[1;35mMake options:\033[0m"
