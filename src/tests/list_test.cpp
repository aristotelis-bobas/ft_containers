/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/04 19:59:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/List.hpp"
#include <list>
#include <iostream>

#ifndef MODE
	#define MODE ft
#endif

bool test(int a)
{
	if (a == 3)
		return true;
	return false;
}

bool test2(int a, int b)
{
	if (a == b)
		return true;
	return false;
}

int main()
{
	std::cout << std::endl;
	{
		MODE::list<int> MyList(10, 10);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(10, 10);
		MODE::list<int> MyList2(MyList.begin(), MyList.end());
		for (MODE::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(88);
		MyList.push_front(44);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		MyList.push_back(1000);
		MyList.pop_front();
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(10, 10);
		MyList.resize(15);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(10, 10);
		MyList.resize(5);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(5, 10);
		MyList.insert(MyList.begin(), 1000);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(5, 10);
		MyList.insert(MyList.begin(), 5, 1000);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(10, 3);
		MODE::list<int> MyRange(4, 5);
		MyList.insert(MyList.begin(), MyRange.begin(), MyRange.end());
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(4);
		MyList.push_back(44);
		MyList.push_back(444);
		MyList.push_back(4444);
		MyList.erase(MyList.begin());
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(4);
		MyList.push_back(44);
		MyList.push_back(444);
		MyList.push_back(4444);
		MyList.erase(MyList.begin(), MyList.begin());
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		MyList.reverse();
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.remove(3);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MODE::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin(), Filler);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MODE::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin(), Filler, Filler.begin());
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MODE::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin(), Filler, Filler.begin(), Filler.end());
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;

		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.remove_if(*test);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;

		MyList.push_back(5);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.push_back(1);
		MyList.unique();
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;

		MyList.push_back(5);
		MyList.push_back(5);
		MyList.push_back(5);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.push_back(1);
		MyList.unique(*test2);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}
