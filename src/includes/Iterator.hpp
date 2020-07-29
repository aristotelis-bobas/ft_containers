/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 20:18:21 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/29 19:48:33 by abobas        ########   odam.nl         */
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

template <typename T, typename T_pointer, typename T_reference>
class random_access_iterator
{
public:
	typedef T value_type;
	typedef T_reference reference;
	typedef T_pointer pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef random_access_iterator self_type;

	random_access_iterator(pointer array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	random_access_iterator(self_type const &other)
	{
		this->array = other.array;
		this->pos = other.pos;
	}

	~random_access_iterator()
	{
	}

	random_access_iterator &operator=(self_type const &other)
	{
		this->array = other.array;
		this->pos = other.pos;
		return (*this);
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

	difference_type position() const
	{
		return (this->pos);
	}

private:
	pointer array;
	size_type pos;
};

template <typename T, typename T_pointer, typename T_reference>
ptrdiff_t operator-(const random_access_iterator<T, T_pointer, T_reference> &lhs,
					const random_access_iterator<T, T_pointer, T_reference> &rhs)
{
	return (lhs.position() - rhs.position());
}

template <typename T, typename T_pointer, typename T_reference>
ptrdiff_t operator+(const random_access_iterator<T, T_pointer, T_reference> &lhs,
					const random_access_iterator<T, T_pointer, T_reference> &rhs)
{
	return (lhs.position() + rhs.position());
}

template <typename T, typename T_pointer, typename T_reference>
class reverse_random_access_iterator
{
public:
	typedef T value_type;
	typedef T_reference reference;
	typedef T_pointer pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator_tag iterator_category;
	typedef reverse_random_access_iterator self_type;

	reverse_random_access_iterator(pointer array, size_type pos)
	{
		this->array = array;
		this->pos = pos;
	}

	reverse_random_access_iterator(self_type const &other)
	{
		this->array = other.array;
		this->pos = other.pos;
	}

	~reverse_random_access_iterator()
	{
	}

	reverse_random_access_iterator &operator=(self_type const &other)
	{
		this->array = other.array;
		this->pos = other.pos;
		return (*this);
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
	pointer array;
	size_type pos;
};

template <typename T, typename T_pointer, typename T_reference>
ptrdiff_t operator-(const reverse_random_access_iterator<T, T_pointer, T_reference> &lhs,
					const reverse_random_access_iterator<T, T_pointer, T_reference> &rhs)
{
	return (lhs.position() - rhs.position());
}

template <typename T, typename T_pointer, typename T_reference>
ptrdiff_t operator+(const reverse_random_access_iterator<T, T_pointer,
														 T_reference> &lhs,
					const reverse_random_access_iterator<T, T_pointer, T_reference> &rhs)
{
	return (lhs.position() + rhs.position());
}

} // namespace ft

#endif
