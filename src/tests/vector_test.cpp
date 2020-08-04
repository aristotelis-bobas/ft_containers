/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_test.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:21:47 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/04 22:30:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vector.hpp"
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#ifndef MODE
#define MODE ft
#endif

int main()
{
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector((char)10, (char)10);

		for (size_t i = 0; i < MyVector.size(); i++)
			std::cout << MyVector[i] << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> test(10, 10);
		MODE::vector<int> MyVector(test.begin(), test.end());

		for (size_t i = 0; i < MyVector.size(); i++)
			std::cout << MyVector[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> test(10, 10);
		MODE::vector<int> MyVector(test.begin(), test.end());

		for (size_t i = 0; i < MyVector.size(); i++)
			std::cout << MyVector[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector;

		for (int i = 0; i < 300; i++)
			MyVector.push_back((i * 99) + 1);

		std::cout << "array[3]: " << MyVector.at(3) << std::endl;
		std::cout << "array[first]: " << MyVector.front() << std::endl;
		std::cout << "array[last]: " << MyVector.back() << std::endl;
		std::cout << "size: " << MyVector.size() << std::endl;
		std::cout << "max_size: " << MyVector.max_size() << std::endl;
	}
	std::cout << std::endl;
	{
		const MODE::vector<int> MyVector(6, 5);

		std::cout << "array[first]: " << MyVector.front() << std::endl;
		std::cout << "array[last]: " << MyVector.back() << std::endl;
		std::cout << "size: " << MyVector.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector(6, 5);
		MyVector.reserve(3385453);
		std::cout << "cap: " << MyVector.capacity() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector(100, 5);
		std::cout << "size: " << MyVector.size() << std::endl;
		MyVector.resize(10);
		std::cout << "size: " << MyVector.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1(20, 555);
		MODE::vector<int> MyVector2(422, 43);

		std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
		std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;

		std::cout << "swapped MyVector1 and MyVector2" << std::endl;
		swap(MyVector1, MyVector2);

		std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
		std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;

		std::cout << "swapped MyVector1 and MyVector2" << std::endl;
		MyVector1.swap(MyVector2);

		std::cout << "MyVector1 size: " << MyVector1.size() << std::endl;
		std::cout << "MyVector2 size: " << MyVector2.size() << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;
		MODE::vector<int> MyVector2;

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
	std::cout << std::endl;
	{

		const MODE::vector<int> MyVector1(3, 10);

		for (MODE::vector<int>::const_iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
		{
			std::cout << *it << std::endl;
		}

		std::cout << std::endl;

		for (MODE::vector<int>::const_iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; --it)
			std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		MyVector1.push_back(10);
		MyVector1.push_back(100);
		MyVector1.push_back(1000);

		for (MODE::vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); it = it + 1)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); it++)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.begin(); it != MyVector1.end(); it += 1)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; it = it - 1)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; it--)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; --it)
			std::cout << *it << std::endl;

		for (MODE::vector<int>::iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; it -= 1)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); rit = rit + 1)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); rit++)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); ++rit)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); rit += 1)
			std::cout << *rit << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rend() - 1; rit != MyVector1.rbegin() - 1; rit = rit - 1)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rend() - 1; rit != MyVector1.rbegin() - 1; rit--)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rend() - 1; rit != MyVector1.rbegin() - 1; --rit)
			std::cout << *rit << std::endl;

		for (MODE::vector<int>::reverse_iterator rit = MyVector1.rend() - 1; rit != MyVector1.rbegin() - 1; rit -= 1)
			std::cout << *rit << std::endl;
	}
	std::cout << std::endl;
	{
		const MODE::vector<int> MyVector1(3, 10);

		for (MODE::vector<int>::const_iterator it = MyVector1.begin(); it != MyVector1.end(); ++it)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::const_iterator it = MyVector1.end() - 1; it != MyVector1.begin() - 1; --it)
			std::cout << *it << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::const_reverse_iterator rit = MyVector1.rbegin(); rit != MyVector1.rend(); ++rit)
			std::cout << *rit << std::endl;

		std::cout << std::endl;

		for (MODE::vector<int>::const_reverse_iterator rit = MyVector1.rend() - 1; rit != MyVector1.rbegin() - 1; --rit)
			std::cout << *rit << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		MyVector1.push_back(50);
		MyVector1.push_back(500);
		MyVector1.push_back(5000);

		MODE::vector<int>::iterator it2 = MyVector1.begin();
		it2++;

		std::cout << *it2 << std::endl;
		MyVector1.erase(it2);
		std::cout << *it2 << std::endl;
		std::cout << std::endl;

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> MyVector1;

		MyVector1.push_back(50);
		MyVector1.push_back(500);
		MyVector1.push_back(5000);

		std::vector<int>::iterator it2 = MyVector1.begin();
		it2++;

		std::cout << *it2 << std::endl;
		MyVector1.erase(it2);
		std::cout << *it2 << std::endl;
		std::cout << std::endl;

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		for (size_t i = 1; i < 11; i++)
			MyVector1.push_back(i * 50);

		MODE::vector<int>::iterator it1 = MyVector1.begin();
		it1 += 7;

		MODE::vector<int>::iterator it2 = MyVector1.begin();
		it2 += 8;

		MyVector1.erase(it1, it2);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}

	std::cout << std::endl;
	{
		std::vector<int> MyVector1;

		for (size_t i = 1; i < 11; i++)
			MyVector1.push_back(i * 50);

		std::vector<int>::iterator it1 = MyVector1.begin();
		it1 += 7;

		std::vector<int>::iterator it2 = MyVector1.begin();
		it2 += 8;

		MyVector1.erase(it1, it2);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{

		MODE::vector<int> MyVector1;

		MyVector1.push_back(10);
		MyVector1.push_back(100);
		MyVector1.push_back(1000);
		MyVector1.insert(MyVector1.begin(), 1);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{

		MODE::vector<int> MyVector1;

		MyVector1.push_back(10);
		MyVector1.push_back(100);
		MyVector1.push_back(1000);
		MyVector1.push_back(10000);
		MyVector1.insert(MyVector1.begin(), 2, 1);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		MyVector1.push_back(9);
		MyVector1.push_back(99);
		MyVector1.push_back(999);
		MyVector1.push_back(9999);
		MyVector1.push_back(99999);
		MyVector1.insert(MyVector1.begin() + 1, 4, 1);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{

		MODE::vector<int> MyVector1;

		MyVector1.push_back(9);
		MyVector1.push_back(99);
		MyVector1.push_back(999);
		MyVector1.push_back(9999);
		MyVector1.push_back(99999);
		MyVector1.push_back(999999);
		MyVector1.insert(MyVector1.begin() + 2, 10, 1);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;
		MODE::vector<int> Range(10, 10);

		MyVector1.push_back(9);
		MyVector1.push_back(99);
		MyVector1.push_back(999);
		MyVector1.push_back(9999);
		MyVector1.push_back(99999);
		MyVector1.push_back(999999);
		MyVector1.insert(MyVector1.begin(), Range.begin(), Range.end());

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		MyVector1.push_back(9);
		MyVector1.push_back(99);
		MyVector1.push_back(999);
		MyVector1.push_back(9999);
		MyVector1.push_back(99999);
		MyVector1.push_back(999999);
		MyVector1.erase(MyVector1.begin());

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
	std::cout << std::endl;
	{
		MODE::vector<int> MyVector1;

		MyVector1.push_back(9);
		MyVector1.push_back(99);
		MyVector1.push_back(999);
		MyVector1.push_back(9999);
		MyVector1.push_back(99999);
		MyVector1.push_back(999999);
		MyVector1.erase(MyVector1.begin() + 1, MyVector1.begin() + 2);

		for (size_t i = 0; i < MyVector1.size(); ++i)
			std::cout << MyVector1[i] << std::endl;
	}
}
