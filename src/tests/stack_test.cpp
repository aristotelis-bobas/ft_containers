/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:34:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/23 18:28:14 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Stack/Stack.hpp"
#include <stack>
#include <iostream>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	{
		MODE::stack<int> MyStack;
		std::cout << MyStack.empty() << std::endl;
		std::cout << MyStack.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::stack<int> MyStack;
		std::cout << MyStack.empty() << std::endl;
		MyStack.push(88);
		std::cout << MyStack.top() << std::endl;
		MyStack.push(44);
		std::cout << MyStack.top() << std::endl;
		std::cout << MyStack.size() << std::endl;
		MyStack.pop();
		std::cout << MyStack.size() << std::endl;
		std::cout << MyStack.top() << std::endl;
		MyStack.pop();
		std::cout << MyStack.size() << std::endl;
	}
	{
		MODE::stack<int> MyStack1;
		MODE::stack<int> MyStack2;

		MyStack1.push(100);
		MyStack1.push(44);

		MyStack2.push(100);
		MyStack2.push(44);

		if (MyStack1 == MyStack2)
			std::cout << "MyStack1 is equal to MyStack2" << std::endl;
		if (MyStack1 < MyStack2)
			std::cout << "MyStack1 is smaller than MyStack2" << std::endl;
		if (MyStack1 <= MyStack2)
			std::cout << "MyStack1 is smaller than or equal to MyStack2" << std::endl;
		if (MyStack1 > MyStack2)
			std::cout << "MyStack1 is larger than MyStack2" << std::endl;
		if (MyStack1 >= MyStack2)
			std::cout << "MyStack1 is larger than or equal to MyStack2" << std::endl;
	}
}
