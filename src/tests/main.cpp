/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 20:30:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Map/Map.hpp"
#include <vector>
#include <list>
#include <iterator>
#include <string>
#include <iostream>
#include <cstddef>

int main()
{
	ft::pair<int, char> jemoeder(299, 'a');

	std::cout << jemoeder.first << std::endl;
	std::cout << jemoeder.second << std::endl;

	ft::map<int, std::string> blabla;
	blabla.key_comp();
	blabla.value_comp();
}
