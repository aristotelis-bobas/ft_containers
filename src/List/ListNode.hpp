/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ListNode.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:03:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/23 19:00:01 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <cstddef>

namespace ft
{

template <typename T>
class node
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef T *pointer;
	typedef const T& const_reference;
	typedef node self_type;

	value_type data;
	node *next;
	node *previous;

	node(const value_type &val = value_type())
	{
		this->next = nullptr;
		this->previous = nullptr;
		this->data = val;
	}

	node(const node &other)
	{
		this->data = other.data;
		this->next = other.next;
		this->previous = other.previous;
	}

	~node()
	{
	}

	self_type &operator=(const self_type &other)
	{
		this->data = other.data;
		this->next = other.next;
		this->previous = other.previous;
		return (*this);
	}

	bool operator==(const self_type &other) const
	{
		if (this->data != other.data)
			return (false);
		if (this->next != other.next)
			return (false);
		if (this->previous != other.previous)
			return (false);
		return (true);
	}

	bool operator!=(const self_type &other) const
	{
		return (!(*this == other));
	}

	node *get_next()
	{
		return (this->next);
	}

	node *get_previous()
	{
		return (this->previous);
	}

};

} // namespace ft

#endif
