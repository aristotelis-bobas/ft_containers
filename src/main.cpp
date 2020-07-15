/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/15 18:45:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Vector.hpp"
#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector;
			std::vector<int> bla;
		
			for (int i = 0; i < 300; i++)
				MyVector.push_back((i * 99) + 1);
				
			std::cout << "array[3]: " << MyVector.at(3) << std::endl;
			std::cout << "array[first]: " << MyVector.front() << std::endl;
			std::cout << "array[last]: " << MyVector.back() << std::endl;
			std::cout << "cap: " << MyVector.capacity() << std::endl;
			std::cout << "size: " << MyVector.size() << std::endl;
			std::cout << "max_size: " << MyVector.max_size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			const ft::Vector<int> MyVector(6, 5);
			
			std::cout << "array[first]: " << MyVector.front() << std::endl;
			std::cout << "array[last]: " << MyVector.back() << std::endl;
			std::cout << "cap: " << MyVector.capacity() << std::endl;
			std::cout << "size: " << MyVector.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector(6, 5);
			MyVector.reserve(3385453);
			std::cout << "cap: " << MyVector.capacity() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector(100, 5);
			std::cout << "size: " << MyVector.size() << std::endl;
			MyVector.resize(10);
			std::cout << "size: " << MyVector.size() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector1(20, 555);
			ft::Vector<int> MyVector2(422, 43);
			
			std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
			std::cout << "MyVector1 cap: " << MyVector1.capacity() << std::endl;
			std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;
			std::cout << "MyVector2 cap: " << MyVector2.capacity() << std::endl;

			std::cout << "swapped MyVector1 and MyVector2" << std::endl;
			swap(MyVector1, MyVector2);

			std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
			std::cout << "MyVector1 cap: " << MyVector1.capacity() << std::endl;
			std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;
			std::cout << "MyVector2 cap: " << MyVector2.capacity() << std::endl;

			std::cout << "swapped MyVector1 and MyVector2" << std::endl;
			MyVector1.swap(MyVector2);

			std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
			std::cout << "MyVector1 cap: " << MyVector1.capacity() << std::endl;
			std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;
			std::cout << "MyVector2 cap: " << MyVector2.capacity() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector1;
			ft::Vector<int> MyVector2;
			
			MyVector1.push_back(100);
			MyVector1.push_back(44);
			
			MyVector2.push_back(100);
			MyVector2.push_back(44);
			
			if (MyVector1 < MyVector2)
				std::cout << "MyVector1 is smaller than MyVector2" << std::endl;
			if (MyVector1 <= MyVector2)
				std::cout << "MyVector1 is smaller than or equal to MyVector2" << std::endl;
			if (MyVector1 > MyVector2)
				std::cout << "MyVector1 is larger than MyVector2" << std::endl;
			if (MyVector1 >= MyVector2)
				std::cout << "MyVector1 is larger than or equal to MyVector2" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << std::endl;
	{
		try
		{
			ft::Vector<int> MyVector1;

			MyVector1.push_back(47);
			MyVector1.push_back(573);
			
			for (ft::Vector<int>::Iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
				std::cout << *it << std::endl;
			
			for (ft::Vector<int>::ReverseIterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); ++rit)
				std::cout << *rit << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
