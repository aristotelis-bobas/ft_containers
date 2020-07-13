# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/13 17:19:37 by abobas        #+#    #+#                  #
#    Updated: 2020/07/13 17:21:37 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC = 			main.cpp

SRC_DIR	=		./src/

SRC :=			$(SRC:%=$(SRC_DIR)%)

INCLUDE =		Vector.hpp

INCLUDE_DIR =	./src/includes/
			
INCLUDE :=		$(INCLUDE:%=$(INCLUDE_DIR)%)

NAME = 			containers

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

CC =			clang++

all: 			$(NAME)

$(NAME):		$(SRC) $(INCLUDE)
				$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
				rm -rf *.o

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
