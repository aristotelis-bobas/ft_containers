# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/13 17:19:37 by abobas        #+#    #+#                  #
#    Updated: 2020/08/04 20:03:42 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

CC =			clang++

test:
				rm -rf main_test
				$(CC) $(FLAGS) src/tests/main.cpp -o main_test
				./main_test

vector:			
				rm -rf vector_test result_ft result_std result_diff
				$(CC) $(FLAGS) -D MODE=ft src/tests/vector_test.cpp -o vector_test
				./vector_test	> result_ft
				rm -rf vector_test
				$(CC) $(FLAGS) -D MODE=std src/tests/vector_test.cpp -o vector_test
				./vector_test	> result_std
				diff -s result_ft result_std > result_diff
list:			
				rm -rf list_test result_ft result_std result_diff
				$(CC) $(FLAGS) -D MODE=ft src/tests/list_test.cpp -o list_test
				./list_test	> result_ft
				rm -rf list_test
				$(CC) $(FLAGS) -D MODE=std src/tests/list_test.cpp -o list_test
				./list_test	> result_std
				diff -s result_ft result_std > result_diff
clean:
				rm -rf *test result* a.out