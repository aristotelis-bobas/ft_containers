/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 18:20:03 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vector.hpp"
#include "../includes/List.hpp"

#include <vector>
#include <list>

#include <cstdint>
#include <iostream>
#include <string>
#include <iterator>

int main()
{
	std::cout << std::endl;
	{
		ft::list<int> MyList;
		MyList.push_back(10);
		MyList.push_back(20);
		MyList.push_back(30);

		ft::list<int>::iterator it = MyList.begin();
		std::cout << *it << std::endl;
		it++;
		std::cout << *it << std::endl;
		it--;
		it += 2;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}
