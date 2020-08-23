/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 21:24:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/23 22:05:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Map/Map.hpp"
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <utility>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(10, 353));
		MyMap.insert(std::make_pair(100, 4543));
		MyMap.insert(std::make_pair(1000, 34534));
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> Range;
		Range.insert(std::make_pair(10, 99));
		Range.insert(std::make_pair(100, 999));
		Range.insert(std::make_pair(1000, 9999));
		MODE::map<int, int> MyMap(Range.begin(), Range.end());
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> Range;
		Range.insert(std::make_pair(1, 80));
		Range.insert(std::make_pair(-10, 57758));
		Range.insert(std::make_pair(89, 34));
		MODE::map<int, int> MyMap(Range.begin(), Range.end());
		MODE::map<int, int>::iterator result = MyMap.insert(MyMap.end()--, std::make_pair(-666, 33333));
		std::cout << result->first << " => " << result->second << std::endl;
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(-10, 57758));
		MyMap.insert(std::make_pair(89, 34));
		MODE::map<int, int>::iterator result = MyMap.find(89);
		std::cout << result->first << " => " << result->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(-10, 57758));
		MyMap.insert(std::make_pair(89, 34));
		std::cout << (MyMap.lower_bound(2))->first << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(-10, 57758));
		MyMap.insert(std::make_pair(89, 34));
		std::cout << (MyMap.lower_bound(88))->first << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(-10, 57758));
		MyMap.insert(std::make_pair(89, 34));
		std::cout << (MyMap.equal_range(-5)).first->first << " --- " << (MyMap.equal_range(2)).second->first << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(10, 57758));
		MyMap.insert(std::make_pair(100, 34));
		std::cout << MyMap[10] << std::endl;
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(10, 57758));
		MyMap.insert(std::make_pair(100, 34));
		MyMap[10] = 99;
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap;
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(10, 57758));
		MyMap.insert(std::make_pair(100, 34));
		MyMap[1000] = 99;
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap; 
		MyMap.insert(std::make_pair(1, 80));
		MyMap.erase(MyMap.begin());
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap; 
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(10, 57758));
		MyMap.insert(std::make_pair(100, 34));
		MyMap.erase(MyMap.begin());
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap; 
		MyMap.insert(std::make_pair(10, 57758));
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(100, 34));
		MyMap.erase(10);
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
}
