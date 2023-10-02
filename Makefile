# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:06:22 by cmateos-          #+#    #+#              #
#    Updated: 2023/09/01 17:06:24 by cmateos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# COLORS #
COLOR_RESET = \x1b[0m
COLOR_RED = \x1b[0;31m
COLOR_RED_N = \x1b[1;31m
COLOR_GREEN = \x1b[1;32m
COLOR_YELLOW = \x1b[1;33m
COLOR_BLUE = \x1b[1;34m
COLOR_MAGENTA = \x1b[1;35m
COLOR_CYAN = \x1b[0;36m
BLANCO_T = \x1b[37m
BLANCO_F = \x1b[47m
MAGENTA = \033[0;95m
BROWN =	\033[0;38;2;184;143;29m

NAME = philo
CC = gcc
CFLAGS = -Wall -W -g3 -fsanitize=address
RM = rm -f
SRC = ./src/philosophers.c ./src/utils.c ./src/ft_init.c ./src/ft_split.c ./src/ft_check_args.c ./src/ft_time.c ./src/ft_free_and_clean.c ./src/ft_routine.c
OBJ = $(SRC:.c=.o)
INCLUDE = philosophers.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	@echo "${BLANCO_T} ◎ $(BROWN)Compiling 🛠️  ${MAGENTA}→   $(COLOR_CYAN)$< $(COLOR_RESET)"
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(COLOR_BLUE) Created! 😸 $(COLOR_RESET)"

clean:
	@rm -f $(OBJ)
#@echo "$(COLOR_RED) Cleaned files .o $(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_RED_N) Cleaned all! 🧹 $(COLOR_RESET)"

normi:
	norminette

re: fclean all

.PHONY: all, clean, fclean, re
