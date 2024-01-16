# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:56:55 by jaurasma          #+#    #+#              #
#    Updated: 2023/12/04 13:47:23 by jaurasma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutant

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

.cpp.o:
				$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
				$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
