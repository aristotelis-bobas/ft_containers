# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/13 17:19:37 by abobas        #+#    #+#                  #
#    Updated: 2020/08/06 17:41:05 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

STD =			-D MODE=std

FT =			-D MODE=ft

STACK =			-D CONTAINER=stack

CC =			clang++

test:			clean
				$(CC) $(FLAGS) src/tests/main.cpp -o main_test
				./main_test

vector:			clean
				$(CC) $(FLAGS) $(FT) src/tests/vector_test.cpp -o vector_test
				./vector_test > result_ft
				rm -rf vector_test
				$(CC) $(FLAGS) $(STD) src/tests/vector_test.cpp -o vector_test
				./vector_test > result_std
				diff -s result_ft result_std > result_diff
				
list:			clean
				$(CC) $(FLAGS) $(FT) src/tests/list_test.cpp -o list_test
				./list_test	> result_ft
				rm -rf list_test
				$(CC) $(FLAGS) $(STD) src/tests/list_test.cpp -o list_test
				./list_test	> result_std
				diff -s result_ft result_std > result_diff

stack:			clean
				$(CC) $(FLAGS) $(FT) $(STACK) src/tests/adaptor_test.cpp -o adaptor_test
				./adaptor_test	> result_ft
				rm -rf adaptor_test
				$(CC) $(FLAGS) $(STD) $(STACK) src/tests/adaptor_test.cpp -o adaptor_test
				./adaptor_test	> result_std
				diff -s result_ft result_std > result_diff
				
clean:
				rm -rf *test result*