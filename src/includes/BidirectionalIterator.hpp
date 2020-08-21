/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BidirectionalIterator.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 20:18:21 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/21 22:36:34 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "Traits.hpp"
#include <cstddef>

namespace ft
{

template <typename T, typename R, typename P, typename N>
class bidirectional_iterator
{
public:
	typedef T value_type;
	typedef R reference;
	typedef P pointer;
	typedef N node;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator_tag iterator_category;
	typedef bidirectional_iterator self_type;

	bidirectional_iterator(node element)
	{
		this->element = element;
	}

	bidirectional_iterator(self_type const &other)
	{
		this->element = other.element;
	}

	~bidirectional_iterator()
	{
	}

	bidirectional_iterator &operator=(self_type const &other)
	{
		this->element = other.element;
		return (*this);
	}

	reference operator*()
	{
		return (*this->element);
	}
	
	pointer operator->()
	{
		return (&this->element);
	}

	bool operator==(self_type const &other) const
	{
		if (this->element != other.element)
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
		this->element++;
		return (*this);
	}

	self_type operator++(int)
	{
		self_type tmp(*this);
		this->element++;
		return (tmp);
	}

	self_type &operator--()
	{
		this->element--;
		return (*this);
	}

	self_type operator--(int)
	{
		self_type tmp(*this);
		this->element--;
		return (tmp);
	}

private:
	node element;
};

template <typename T, typename R, typename P, typename N>
class reverse_bidirectional_iterator
{
public:
	typedef T value_type;
	typedef R reference;
	typedef P pointer;
	typedef N node;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef bidirectional_iterator_tag iterator_category;
	typedef reverse_bidirectional_iterator self_type;

	reverse_bidirectional_iterator(node element)
	{
		this->element = element;
	}

	reverse_bidirectional_iterator(self_type const &other)
	{
		this->element = other.element;
	}

	~reverse_bidirectional_iterator()
	{
	}

	reverse_bidirectional_iterator &operator=(self_type const &other)
	{
		this->element = other.element;
		return (*this);
	}

	reference operator*()
	{
		return (*this->element);
	}

	pointer operator->()
	{
		return (&this->element);
	}

	bool operator==(self_type const &other) const
	{
		if (this->element != other.element)
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
		this->element--;
		return (*this);
	}

	self_type operator++(int)
	{
		self_type tmp(*this);
		this->element--;
		return (tmp);
	}

	self_type &operator--()
	{
		this->element++;
		return (*this);
	}

	self_type operator--(int)
	{
		self_type tmp(*this);
		this->element++;
		return (tmp);
	}

private:
	node element;
};

} // namespace ft

#endif
