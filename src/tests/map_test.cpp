/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 21:24:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 18:59:49 by abobas        ########   odam.nl         */
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
	}
	std::cout << std::endl;
	{
		MODE::map<double, std::string> MyMap;
		MyMap.insert(std::make_pair(555, std::string("world")));
		MyMap.insert(std::make_pair(111, std::string("hello")));
		MyMap.insert(std::make_pair(777, std::string("!!!!")));
		for (MODE::map<double, std::string>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
			std::cout << it->first << " => " << it->second << std::endl;
	}
}
