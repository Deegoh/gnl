# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#    Updated: 2021/11/01 15:32:55 by tpinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = get_next_line
NAME = g
SRC = get_next_line.c get_next_line_utils.c
FLAGS = -Wextra -Werror -Wall
CC = cc
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
FD = line

.PHONY: all clean ffclean re bonus

all: $(NAME)

lldb: $(OBJ)
	$(CC) $(FLAGS) -fsanitize=address $(SRC) -o $(NAME)
	lldb g $(FD)

leaks:
	leaks -atExit -- ./$(NAME) $(FD)	

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	./$(NAME) $(FD) | cat -e

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
