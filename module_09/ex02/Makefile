# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 14:42:33 by jaurasma          #+#    #+#              #
#    Updated: 2024/01/03 15:33:27 by jaurasma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

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
