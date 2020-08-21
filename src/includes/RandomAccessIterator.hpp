/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RandomAccessIterator.hpp                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/21 17:16:35 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 22:44:29 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

#include "Traits.hpp"
#include <cstddef>

namespace ft
{

template <typename T, typename R, typename P>
class random_access_iterator
{
public:
	typedef T value_type;
	typedef R reference;
	typedef P pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef random_access_iterator self_type;

	random_access_iterator(pointer array)
	{
		this->array = array;
	}

	random_access_iterator(self_type const &other)
	{
		this->array = other.array;
	}

	~random_access_iterator()
	{
	}

	random_access_iterator &operator=(self_type const &other)
	{
		this->array = other.array;
		return (*this);
	}

	reference operator*()
	{
		return (*this->array);
	}

	pointer operator->()
	{
		return (&(*this->array));
	}

	bool operator==(self_type const &other) const
	{
		if (this->array != other.array)
			return (false);
		return (true);
	}

	bool operator!=(self_type const &other) const
	{
		if (*this == other)
			return (false);
		return (true);
	}

	self_type &operator++()
	{
		this->array++;
		return (*this);
	}

	self_type operator++(int)
	{
		self_type tmp(*this);
		this->array++;
		return (tmp);
	}

	self_type operator+(difference_type n)
	{
		self_type tmp(*this);
		tmp.array += n;
		return (tmp);
	}

	self_type &operator+=(difference_type n)
	{
		this->array += n;
		return (*this);
	}

	self_type &operator--()
	{
		this->array--;
		return (*this);
	}

	self_type operator--(int)
	{
		self_type tmp(*this);
		this->array--;
		return (tmp);
	}

	self_type operator-(difference_type n)
	{
		self_type tmp(*this);
		tmp.array -= n;
		return (tmp);
	}

	self_type &operator-=(difference_type n)
	{
		this->array -= n;
		return (*this);
	}

private:
	pointer array;
};

template <typename T, typename R, typename P>
class reverse_random_access_iterator
{
public:
	typedef T value_type;
	typedef R reference;
	typedef P pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef reverse_random_access_iterator self_type;

	reverse_random_access_iterator(pointer elements)
	{
		this->elements = elements;
	}

	reverse_random_access_iterator(self_type const &other)
	{
		this->elements = other.elements;
	}

	~reverse_random_access_iterator()
	{
	}

	reverse_random_access_iterator &operator=(self_type const &other)
	{
		this->elements = other.elements;
		return (*this);
	}

	reference operator*()
	{
		return (*this->elements);
	}

	pointer operator->()
	{
		return (&(*this->array));
	}

	bool operator==(self_type const &other) const
	{
		if (this->elements != other.elements)
			return (false);
		return (true);
	}

	bool operator!=(self_type const &other) const
	{
		if (*this == other)
			return (false);
		return (true);
	}

	self_type &operator++()
	{
		this->elements--;
		return (*this);
	}

	self_type operator++(int)
	{
		self_type tmp(*this);
		this->elements--;
		return (tmp);
	}

	self_type operator+(difference_type n)
	{
		self_type tmp(*this);
		tmp.elements -= n;
		return (tmp);
	}

	self_type &operator+=(difference_type n)
	{
		this->elements -= n;
		return (*this);
	}

	self_type &operator--()
	{
		this->elements++;
		return (*this);
	}

	self_type operator--(int)
	{
		self_type tmp(*this);
		this->elements++;
		return (tmp);
	}

	self_type operator-(difference_type n)
	{
		self_type tmp(*this);
		tmp.elements += n;
		return (tmp);
	}

	self_type &operator-=(difference_type n)
	{
		this->elements += n;
		return (*this);
	}

private:
	pointer elements;
};

} // namespace ft

#endif
