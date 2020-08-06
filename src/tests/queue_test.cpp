/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:18:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/06 18:18:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Queue.hpp"
#include <queue>
#include <iostream>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	{
		MODE::queue<int> MyAdaptor;
		std::cout << MyAdaptor.empty() << std::endl;
		std::cout << MyAdaptor.size() << std::endl;
	}
    std::cout << std::endl;
	{
		MODE::queue<int> MyAdaptor;
        std::cout << MyAdaptor.empty() << std::endl;
		MyAdaptor.push(88);
        std::cout << MyAdaptor.back() << std::endl;
		MyAdaptor.push(44);
        std::cout << MyAdaptor.back() << std::endl;
		std::cout << MyAdaptor.size() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
        std::cout << MyAdaptor.back() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
    }
    std::cout << std::endl;
	{
		MODE::queue<int> MyAdaptor;
        std::cout << MyAdaptor.empty() << std::endl;
		MyAdaptor.push(88);
        std::cout << MyAdaptor.front() << std::endl;
		MyAdaptor.push(44);
        std::cout << MyAdaptor.front() << std::endl;
		std::cout << MyAdaptor.size() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
        std::cout << MyAdaptor.front() << std::endl;
        MyAdaptor.pop();
        std::cout << MyAdaptor.size() << std::endl;
    }
}
