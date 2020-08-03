/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 17:06:53 by abobas        ########   odam.nl         */
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
		ft::list<int> MyVector1(10, 10);
		ft::list<int>::iterator it = MyVector1.begin();
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}
