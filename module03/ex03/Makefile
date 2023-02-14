# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:35:40 by rbicanic          #+#    #+#              #
#    Updated: 2022/05/17 17:03:34 by rbicanic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= DiamondTrap

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98

SRC_FILES 	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

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
