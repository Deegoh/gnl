# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 17:35:44 by tpinto-m          #+#    #+#              #
#   Updated: 2021/12/09 18:45:53 by tpinto-m         ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = gnl
SRC =	get_next_line.c\
		get_next_line_utils.c

SRCBONUS = get_next_line_bonus.c\
			get_next_line_utils_bonus.c

CFLAGS = -Wextra -Werror -Wall
CC = cc
RM = rm -rf
OBJ = $(SRC:%.c=%.o)
OBJBONUS = $(SRCBONUS:%.c=%.o)
FD = file/text

.PHONY: all clean ffclean re bonus lldb valgrind

all: $(NAME)

lldb: $(OBJ)
	$(CC) $(CFLAGS) -g $(SRC) -o $(NAME)
	lldb $(NAME) $(FD)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose -s ./$(NAME) $(FD)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	./$(NAME) $(FD) | cat -e

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
bonus:
	$(CC) $(CFLAGS) $(SRCBONUS) -o $(NAME)
