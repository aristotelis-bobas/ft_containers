/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 21:24:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 21:57:44 by abobas        ########   odam.nl         */
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
		MODE::map<int, char> MyMap;
		std::cout << MyMap.size() << std::endl;
		MyMap.clear();
	}
	std::cout << std::endl;
	{
		MODE::map<double, std::string> MyMap;
		MyMap.insert(std::make_pair(555, std::string("world")));
		MODE::map<double, std::string>::iterator it = MyMap.begin();
		std::cout << it->first << " => " << it->second << std::endl;
		MyMap.insert(std::make_pair(111, std::string("hello")));
		MyMap.insert(std::make_pair(777, std::string("!!!!")));
		for (MODE::map<double, std::string>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> Range; 
		Range.insert(std::make_pair(1, 80));
		Range.insert(std::make_pair(-10, 57758));
		Range.insert(std::make_pair(89, 34));
		MODE::map<int, int> MyMap(Range.begin(), Range.end());
		for (MODE::map<int, int>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
		std::cout << MyMap.size() << std::endl;
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
		std::cout << MyMap.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::map<int, int> MyMap; 
		MyMap.insert(std::make_pair(1, 80));
		MyMap.insert(std::make_pair(-10, 57758));
		MyMap.insert(std::make_pair(89, 34));
		MODE::map<int, int>::iterator result = MyMap.find(89);
		std::cout << result->first << " => " << result->second << std::endl;
		MODE::map<int, int>::iterator res2 = MyMap.find(89);
		std::cout << res2->first << " => " << res2->second << std::endl;
	}
}
