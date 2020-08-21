/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 20:18:21 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 17:19:40 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Traits.hpp"
#include <cstddef>


namespace ft
{

template <typename T, typename T_pointer, typename T_reference>
class bidirectional_iterator
{
public:
	typedef T value_type;
	typedef T_reference reference;
	typedef T_pointer pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator_tag iterator_category;
	typedef bidirectional_iterator self_type;

	bidirectional_iterator(pointer elements)
	{
		this->elements = elements;
	}

	bidirectional_iterator(self_type const &other)
	{
		this->elements = other.elements;
	}

	~bidirectional_iterator()
	{
	}

	bidirectional_iterator &operator=(self_type const &other)
	{
		this->elements = other.elements;
		return (*this);
	}

	reference operator*()
	{
		return (*this->elements);
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
		this->elements++;
		return (*this);
	}

	self_type operator++(int)
	{
		self_type tmp(*this);
		this->elements++;
		return (tmp);
	}

	self_type &operator--()
	{
		this->elements--;
		return (*this);
	}

	self_type operator--(int)
	{
		self_type tmp(*this);
		this->elements--;
		return (tmp);
	}

private:
	pointer elements;
};

template <typename T, typename T_pointer, typename T_reference>
class reverse_bidirectional_iterator
{
public:
	typedef T value_type;
	typedef T_reference reference;
	typedef T_pointer pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator_tag iterator_category;
	typedef reverse_bidirectional_iterator self_type;

	reverse_bidirectional_iterator(pointer elements)
	{
		this->elements = elements;
	}

	reverse_bidirectional_iterator(self_type const &other)
	{
		this->elements = other.elements;
	}

	~reverse_bidirectional_iterator()
	{
	}

	reverse_bidirectional_iterator &operator=(self_type const &other)
	{
		this->elements = other.elements;
		return (*this);
	}

	reference operator*()
	{
		return (*this->elements);
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

private:
	pointer elements;
};

} // namespace ft

#endif
