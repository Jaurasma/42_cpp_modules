# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 13:56:55 by jaurasma          #+#    #+#              #
#    Updated: 2023/07/27 16:13:03 by jaurasma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = My_First_Class_in_Orthodox_Canonical_Form

SRC = main.cpp Fixed.cpp

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