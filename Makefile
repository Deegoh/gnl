# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#    Updated: 2021/10/21 18:36:33 by tpinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRC = get_next_line.c
FLAGS = -Wextra -Werror -Wall
BFLAGS = -D BUFFER_SIZE=42
CC = cc
RM = rm -rf
OBJ = $(SRC:%.c=%.o)

.PHONY: all clean ffclean re bonus

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(BFLAGS) $(SRC) -o $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
