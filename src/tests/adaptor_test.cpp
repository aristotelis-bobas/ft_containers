/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adaptor_test.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 17:34:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/06 17:44:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Stack.hpp"
#include "../includes/List.hpp"
#include "../includes/Vector.hpp"

#include <list>
#include <vector>
#include <stack>

#include <iostream>

#ifndef MODE
#define MODE ft
#endif

#ifndef CONTAINER
#define CONTAINER stack
#endif

int main()
{
	{
		MODE::CONTAINER<int> MyAdaptor;
		std::cout << MyAdaptor.empty() << std::endl;
		std::cout << MyAdaptor.size() << std::endl;
	}
    std::cout << std::endl;
	{
		MODE::CONTAINER<int> MyAdaptor;
        std::cout << MyAdaptor.empty() << std::endl;
		MyAdaptor.push(88);
        std::cout << MyAdaptor.top() << std::endl;
		MyAdaptor.push(44);
        std::cout << MyAdaptor.top() << std::endl;
		std::cout << MyAdaptor.size() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
        std::cout << MyAdaptor.top() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
    }
}
