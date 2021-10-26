# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#    Updated: 2021/10/26 18:34:04 by tpinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = get_next_line
NAME = g
SRC = get_next_line.c get_next_line_utils.c
FLAGS = -Wextra -Werror -Wall
CC = cc
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
FD = t

.PHONY: all clean ffclean re bonus

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(BFLAGS) $(SRC) -o $(NAME)
	./$(NAME) $(FD)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
