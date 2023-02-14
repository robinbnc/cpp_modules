# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:35:40 by rbicanic          #+#    #+#              #
#    Updated: 2022/05/24 15:29:26 by rbicanic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= array

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp

OBJ			= $(SRC_FILES:.cpp=.o)

.cpp.o: $(NAME)
	${CC} ${CFLAGS} -c -I. $< -o ${<:.cpp=.o}

all: $(NAME) Array.hpp

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
