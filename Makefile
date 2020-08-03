# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/13 17:19:37 by abobas        #+#    #+#                  #
#    Updated: 2020/08/03 23:13:20 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

CC =			clang++

test:
				rm -rf main_test
				$(CC) $(FLAGS) src/tests/main.cpp -o main_test
				./main_test

vector:			
				rm -rf vector_test
				$(CC) $(FLAGS) src/tests/vector_test.cpp -o vector_test
				./vector_test

list:			
				rm -rf list_test
				$(CC) $(FLAGS) src/tests/list_test.cpp -o list_test
				./list_test	

clean:
				rm -rf main_test vector_test list_test