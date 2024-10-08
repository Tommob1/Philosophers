# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btomlins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 16:24:27 by btomlins          #+#    #+#              #
#    Updated: 2024/09/26 19:05:38 by btomlins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	main

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address
RM		=	rm -f

INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

SRC		=	main.c \
			utils.c \
			sim_start.c \
			monitor.c \
			data_init.c \
			handle_threads_mutex.c \
			parse_input.c \
			print_status.c \
			protect_vars.c

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

OBJ		=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

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
		@echo "\033[1;36mmake all\033[0m	Compile the program"
		@echo "\033[1;36mmake clean\033[0m	Remove object files"
		@echo "\033[1;36mmake fclean\033[0m	Remove object files and the executable"
		@echo "\033[1;36mmake re\033[0m   Re-build program from fresh after fclean"		@echo "\033[1;36mmake leaks\033[0m   Check for memory leaks in macOS"
		@echo "\033[1;36mmake leaks\033[0m	Check for leaks int macOS"
		@echo "\033[1;36mmake valgrind_leaks\033[0m   Check for leaks with valgrind in linux"