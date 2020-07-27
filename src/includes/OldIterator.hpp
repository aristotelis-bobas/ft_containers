/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   OldIterator.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/17 17:03:06 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/27 20:41:12 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>

namespace ft
{

class random_access_iterator_tag
{
};

class bidirectional_iterator_tag
{
};
class forward_iterator_tag
{
};
class input_iterator_tag
{
};

class output_iterator_tag
{
};

template <typename T>
class iterator
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef const T &const_reference;
	typedef T *pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef iterator self_type;

	iterator(value_type *array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	iterator(iterator const &other)
	{
		this->array = other.array;
		this->pos = other.pos;
	}

	iterator &operator=(iterator const &other)
	{
	}

	reference operator*()
	{
		return (this->array[this->pos]);
	}

	bool operator==(self_type const &other) const
	{
		if (this->array != other.array)
			return (false);
		if (this->pos != other.pos)
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
		this->pos++;
		return (*this);
	}

	self_type &operator++(int)
	{
		self_type(*this);
		this->pos++;
		return (*this);
	}

	self_type &operator+(difference_type n)
	{
		self_type(*this);
		this->pos += n;
		return (*this);
	}

	self_type &operator+=(difference_type n)
	{
		this->pos += n;
		return (*this);
	}

	self_type &operator--()
	{
		this->pos--;
		return (*this);
	}

	self_type &operator--(int)
	{
		self_type(*this);
		this->pos--;
		return (*this);
	}

	self_type &operator-(difference_type n)
	{
		self_type(*this);
		this->pos -= n;
		return (*this);
	}

	self_type &operator-=(difference_type n)
	{
		this->pos -= n;
		return (*this);
	}

private:
	pointer array;
	size_type pos;
};

template <typename T>
class ReverseIterator
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef const T &const_reference;
	typedef T *pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef ReverseIterator self_type;

	ReverseIterator(value_type *array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	reference operator*()
	{
		return (this->array[this->pos]);
	}

	bool operator==(self_type const &other) const
	{
		if (this->array != other.array)
			return (false);
		if (this->pos != other.pos)
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
		this->pos--;
		return (*this);
	}

	self_type &operator++(int)
	{
		self_type(*this);
		this->pos--;
		return (*this);
	}

	self_type &operator+(difference_type n)
	{
		self_type(*this);
		this->pos -= n;
		return (*this);
	}

	self_type &operator+=(difference_type n)
	{
		this->pos -= n;
		return (*this);
	}

	self_type &operator--()
	{
		this->pos++;
		return (*this);
	}

	self_type &operator--(int)
	{
		self_type(*this);
		this->pos++;
		return (*this);
	}

	self_type &operator-(difference_type n)
	{
		self_type(*this);
		this->pos += n;
		return (*this);
	}

	self_type &operator-=(difference_type n)
	{
		this->pos += n;
		return (*this);
	}

private:
	value_type *array;
	size_type pos;
};

template <typename T>
class ConstIterator
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef const T &const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef ConstIterator self_type;

	ConstIterator(value_type *array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	const_reference operator*() const
	{
		return (this->array[this->pos]);
	}

	bool operator==(self_type const &other) const
	{
		if (this->array != other.array)
			return (false);
		if (this->pos != other.pos)
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
		this->pos++;
		return (*this);
	}

	self_type &operator++(int)
	{
		self_type(*this);
		this->pos++;
		return (*this);
	}

	self_type &operator+(difference_type n)
	{
		self_type(*this);
		this->pos += n;
		return (*this);
	}

	self_type &operator+=(difference_type n)
	{
		this->pos += n;
		return (*this);
	}

	self_type &operator--()
	{
		this->pos--;
		return (*this);
	}

	self_type &operator--(int)
	{
		self_type(*this);
		this->pos--;
		return (*this);
	}

	self_type &operator-(difference_type n)
	{
		self_type(*this);
		this->pos -= n;
		return (*this);
	}

	self_type &operator-=(difference_type n)
	{
		this->pos -= n;
		return (*this);
	}

private:
	value_type *array;
	size_type pos;
};

template <typename T>
class ConstReverseIterator
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef const T &const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef ConstReverseIterator self_type;

	ConstReverseIterator(value_type *array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	const_reference operator*() const
	{
		return (this->array[this->pos]);
	}

	bool operator==(self_type const &other) const
	{
		if (this->array != other.array)
			return (false);
		if (this->pos != other.pos)
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
		this->pos--;
		return (*this);
	}

	self_type &operator++(int)
	{
		self_type(*this);
		this->pos--;
		return (*this);
	}

	self_type &operator+(difference_type n)
	{
		self_type(*this);
		this->pos -= n;
		return (*this);
	}

	self_type &operator+=(difference_type n)
	{
		this->pos -= n;
		return (*this);
	}

	self_type &operator--()
	{
		this->pos++;
		return (*this);
	}

	self_type &operator--(int)
	{
		self_type(*this);
		this->pos++;
		return (*this);
	}

	self_type &operator-(difference_type n)
	{
		self_type(*this);
		this->pos += n;
		return (*this);
	}

	self_type &operator-=(difference_type n)
	{
		this->pos += n;
		return (*this);
	}

private:
	value_type *array;
	size_type pos;
};

} // namespace ft

#endif
