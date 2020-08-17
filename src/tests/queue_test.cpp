/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue_test.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 18:18:13 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 18:51:20 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Queue/Queue.hpp"
#include <queue>
#include <iostream>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	{
		MODE::queue<int> MyQueue;
		std::cout << MyQueue.empty() << std::endl;
		std::cout << MyQueue.size() << std::endl;
	}
    std::cout << std::endl;
	{
		MODE::queue<int> MyQueue;
        std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(88);
        std::cout << MyQueue.back() << std::endl;
		MyQueue.push(44);
        std::cout << MyQueue.back() << std::endl;
		std::cout << MyQueue.size() << std::endl;
        MyQueue.pop();
        std::cout << MyQueue.size() << std::endl;
        std::cout << MyQueue.back() << std::endl;
        MyQueue.pop();
        std::cout << MyQueue.size() << std::endl;
    }
    std::cout << std::endl;
	{
		MODE::queue<int> MyQueue;
        std::cout << MyQueue.empty() << std::endl;
		MyQueue.push(88);
        std::cout << MyQueue.front() << std::endl;
		MyQueue.push(44);
        std::cout << MyQueue.front() << std::endl;
		std::cout << MyQueue.size() << std::endl;
        MyQueue.pop();
        std::cout << MyQueue.size() << std::endl;
        std::cout << MyQueue.front() << std::endl;
        MyQueue.pop();
        std::cout << MyQueue.size() << std::endl;
    }
	{
		MODE::queue<int> MyQueue1;
		MODE::queue<int> MyQueue2;

		MyQueue1.push(100);
		MyQueue1.push(44);

		MyQueue2.push(100);
		MyQueue2.push(44);

		if (MyQueue1 == MyQueue2)
            std::cout << "MyQueue1 is equal to MyQueue2" << std::endl;
		if (MyQueue1 < MyQueue2)
			std::cout << "MyQueue1 is smaller than MyQueue2" << std::endl;
		if (MyQueue1 <= MyQueue2)
			std::cout << "MyQueue1 is smaller than or equal to MyQueue2" << std::endl;
		if (MyQueue1 > MyQueue2)
			std::cout << "MyQueue1 is larger than MyQueue2" << std::endl;
		if (MyQueue1 >= MyQueue2)
			std::cout << "MyQueue1 is larger than or equal to MyQueue2" << std::endl;
    }
}
