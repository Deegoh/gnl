# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#    Updated: 2021/11/05 09:34:54 by tpinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
SRC = get_next_line.c\
		get_next_line_utils.c
FLAGS = -Wextra -Werror -Wall
CC = cc
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
FD = get_next_line.c

.PHONY: all clean ffclean re bonus lldb valgrind

all: $(NAME)

lldb: $(OBJ)
	$(CC) $(FLAGS) -fsanitize=address $(SRC) -o $(NAME)
	lldb g $(FD)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt -s ./$(NAME) $(FD)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	./$(NAME) $(FD) | cat -e

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
