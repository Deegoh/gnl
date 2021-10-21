# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#    Updated: 2021/10/21 17:55:43 by tpinto-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= get_next_line
SRC=
FLAGS= -Wextra -Werror -Wall
CC= cc
RM= rm -rf
OBJ= $(SRC:%.c=%.o)

.PHONY: all clean ffclean re bonus

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
