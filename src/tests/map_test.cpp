/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_test.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 21:24:40 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 22:41:55 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Map/Map.hpp"
#include "../Map/Pair.hpp"
#include <iostream>
#include <map>
#include <string>
#include <iterator>

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
		MODE::map<char, std::string> MyMap;
		MyMap.insert(MODE::pair<char, std::string>('d', std::string("jemoeder")));
		MyMap.insert(MODE::pair<char, std::string>('a', std::string("jemoeder")));
		MyMap.insert(MODE::pair<char, std::string>('x', std::string("jemoeder")));
		/* 
		for (MODE::map<char, std::string>::iterator it = MyMap.begin(); it != MyMap.end(); it++)
		{
			std::cout << (*it).first << " => " << (*it).second << std::endl;
		}
		*/
	}
}
