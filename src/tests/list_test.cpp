/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/04 17:30:01 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/List.hpp"
#include <list>
#include <iostream>

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
		ft::list<int> MyList(10, 10);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(10, 10);
		ft::list<int> MyList2(MyList.begin(), MyList.end());
		for (ft::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(88);
		MyList.push_front(44);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		MyList.push_back(1000);
		MyList.pop_front();
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(10, 10);
		MyList.resize(15);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(10, 10);
		MyList.resize(5);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); it++)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(88);
		MyList.push_back(44);
		MyList.push_back(22);
		MyList.push_back(11);
		ft::list<int>::iterator it = MyList.begin();
		it += 3;
		std::cout << *it << std::endl;
		it -= 2;
		std::cout << *it << std::endl;
		it += 1;
		std::cout << *it << std::endl;
		it -= 2;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(5, 10);
		MyList.insert(MyList.begin() + 2, 1000);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(5, 10);
		MyList.insert(MyList.begin() + 5, 5, 1000);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList(10, 3);
		ft::list<int> MyRange(4, 5);
		MyList.insert(MyList.begin() + 1, MyRange.begin(), MyRange.end());
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(4);
		MyList.push_back(44);
		MyList.push_back(444);
		MyList.push_back(4444);
		MyList.erase(MyList.begin() + 1);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(4);
		MyList.push_back(44);
		MyList.push_back(444);
		MyList.push_back(4444);
		MyList.erase(MyList.begin(), MyList.begin() + 1);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		MyList.reverse();
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.remove(3);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		ft::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin() + 1, Filler);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		ft::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin() + 1, Filler, Filler.begin() + 2);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		ft::list<int> Filler(5, 66);
		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.splice(MyList.begin() + 1, Filler, Filler.begin() + 1, Filler.end() - 1);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;

		MyList.push_back(5);
		MyList.push_back(4);
		MyList.push_back(3);
		MyList.push_back(2);
		MyList.push_back(1);
		MyList.remove_if(*test);
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;

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
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		ft::list<int> MyList;

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
		for (ft::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}
