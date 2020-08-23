# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/13 17:19:37 by abobas        #+#    #+#                  #
#    Updated: 2020/08/23 18:06:20 by abobas        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS =			-Wall -Werror -Wextra -std=c++98 -pedantic

STD =			-D MODE=std

FT =			-D MODE=ft

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

map:			clean
				$(CC) $(FLAGS) $(FT) src/tests/map_test.cpp -o map_test -ggdb
				./map_test	> result_ft 
				rm -rf map_test
				$(CC) $(FLAGS) $(STD) src/tests/map_test.cpp -o map_test
				./map_test	> result_std
				diff -s result_ft result_std > result_diff

stack:			clean
				$(CC) $(FLAGS) $(FT) src/tests/stack_test.cpp -o stack_test
				./stack_test > result_ft
				rm -rf stack_test
				$(CC) $(FLAGS) $(STD) src/tests/stack_test.cpp -o stack_test
				./stack_test > result_std
				diff -s result_ft result_std > result_diff

queue:			clean
				$(CC) $(FLAGS) $(FT) src/tests/queue_test.cpp -o queue_test
				./queue_test > result_ft
				rm -rf queue_test
				$(CC) $(FLAGS) $(STD) src/tests/queue_test.cpp -o queue_test
				./queue_test > result_std
				diff -s result_ft result_std > result_diff				
				
clean:
				rm -rf *test result*