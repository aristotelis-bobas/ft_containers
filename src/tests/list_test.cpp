/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_test.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 18:53:14 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../List/List.hpp"
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

template <typename T>
bool test3(T a, T b)
{
	if (a < b)
		return true;
	return false;
}

int main()
{
	{
		MODE::list<int> MyList;
		std::cout << MyList.empty() << std::endl;
		std::cout << MyList.size() << std::endl;
	}
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
		std::cout << *(MyList.erase(MyList.begin())) << std::endl;
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
		std::cout << *(MyList.erase(MyList.begin(), MyList.end())) << std::endl;
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
		MyList.reverse();
		MyList.sort();
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
		MyList.reverse();
		MyList.sort(*test3<int>);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		const MODE::list<int> MyList(10, 50);

		for (MODE::list<int>::const_iterator it = MyList.begin(); it != MyList.end(); ++it)
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

		for (MODE::list<int>::reverse_iterator it = MyList.rbegin(); it != MyList.rend(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(1);
		MyList.push_back(35);
		MyList.push_back(576);
		MyList.push_back(45);
		MyList.push_back(17);
		MyList.sort();
		MODE::list<int> MyList2;
		MyList2.push_back(5);
		MyList2.push_back(9);
		MyList2.push_back(34);
		MyList2.push_back(6);
		MyList2.push_back(99);
		MyList2.sort();
		MyList.merge(MyList2);

		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		for (MODE::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList;
		MyList.push_back(1);
		MyList.push_back(35);
		MyList.push_back(576);
		MyList.push_back(45);
		MyList.push_back(17);
		MyList.sort();
		MODE::list<int> MyList2;
		MyList2.push_back(5);
		MyList2.push_back(9);
		MyList2.push_back(34);
		MyList2.push_back(6);
		MyList2.push_back(99);
		MyList2.sort();
		MyList.merge(MyList2, *test3<int>);

		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		for (MODE::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); ++it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::list<int> MyList(33, 664);
		MODE::list<int> MyList2(5, 53);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		for (MODE::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); ++it)
			std::cout << *it << std::endl;
		MyList.swap(MyList2);
		for (MODE::list<int>::iterator it = MyList.begin(); it != MyList.end(); ++it)
			std::cout << *it << std::endl;
		for (MODE::list<int>::iterator it = MyList2.begin(); it != MyList2.end(); ++it)
			std::cout << *it << std::endl;
	}
	{
		MODE::list<int> MyList1;
		MODE::list<int> MyList2;

		MyList1.push_back(100);
		MyList1.push_back(44);

		MyList2.push_back(100);
		MyList2.push_back(44);

		if (MyList1 == MyList2)
			std::cout << "MyList1 is equal to MyList2" << std::endl;
		if (MyList1 < MyList2)
			std::cout << "MyList1 is smaller than MyList2" << std::endl;
		if (MyList1 <= MyList2)
			std::cout << "MyList1 is smaller than or equal to MyList2" << std::endl;
		if (MyList1 > MyList2)
			std::cout << "MyList1 is larger than MyList2" << std::endl;
		if (MyList1 >= MyList2)
			std::cout << "MyList1 is larger than or equal to MyList2" << std::endl;
		MyList1.swap(MyList2);
		if (MyList1 < MyList2)
			std::cout << "MyList1 is smaller than MyList2" << std::endl;
		if (MyList1 <= MyList2)
			std::cout << "MyList1 is smaller than or equal to MyList2" << std::endl;
		if (MyList1 > MyList2)
			std::cout << "MyList1 is larger than MyList2" << std::endl;
		if (MyList1 >= MyList2)
			std::cout << "MyList1 is larger than or equal to MyList2" << std::endl;
	}
}
