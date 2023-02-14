# **************************************************************************** #
#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 08:20:09 by cberganz          #+#    #+#              #
#    Updated: 2022/02/27 02:26:37 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= fixed

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp Fixed.cpp

OBJ			= $(SRC_FILES:.cpp=.o)

.cpp.o: $(NAME)
	${CC} ${CFLAGS} -c -I. $< -o ${<:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n Compiling executable $(NAME)...
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Done.

clean:
	@echo -n Making clean...
	@rm -rf $(OBJ)
	@echo Done.

fclean: clean
	@echo -n Making fclean...
	@rm -f $(NAME)
	@echo Done.

re: fclean all

.PHONY : all clean fclean re

test: $(NAME)
		./$(NAME) > my_output.diff;
		@echo  "Default constructor called\nCopy constructor called\nCopy assignment operator called // <-- This line may be missing depending on your implementation\ngetRawBits member function called\nDefault constructor called\nCopy assignment operator called\ngetRawBits member function called\ngetRawBits member function called\n0\ngetRawBits member function called\n0\ngetRawBits member function called\n0\nDestructor called\nDestructor called\nDestructor called\n" > expected_output.diff;
		-diff my_output.diff expected_output.diff;
		rm my_output.diff expected_output.diff;
