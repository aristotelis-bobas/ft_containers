/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 15:57:09 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/22 22:04:03 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

#include "../includes/Algorithms.hpp"
#include <cstddef>

namespace ft
{

template <typename T, class C>
class node
{
public:
	typedef T value_type;
	typedef T &reference;
	typedef T *pointer;
	typedef C key_compare;
	typedef const value_type *const_pointer;
	typedef node self_type;

	value_type data;
	node *parent;
	node *left;
	node *right;

	node(value_type const &val = value_type()) : data(val)
	{
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}

	node(const node &other) : data(other.data)
	{
		this->parent = other.parent;
		this->left = other.left;
		this->right = other.right;
	}

	~node()
	{
	}

	self_type &operator=(const self_type &other)
	{
		this->data = other.data;
		this->parent = other.parent;
		this->left = other.left;
		this->right = other.right;
		return (*this);
	}

	bool operator==(const self_type &other) const
	{
		if (this->data != other.data)
			return (false);
		if (this->parent != other.parent)
			return (false);
		if (this->left != other.left || this->right != other.right)
			return (false);
		return (true);
	}

	bool operator!=(const self_type &other) const
	{
		return (!(*this == other));
	}

	node *next()
	{
		if (this->right)
		{
			*this = *this->right;
			while (this->left)
				*this = *this->left;
		}
		else
		{
			node tmp = *this;
			*this = *this->parent;
			while (*this->left != tmp)
			{
				tmp = *this;
				*this = *this->parent;
			}
		}
		return (&(*this));
	}

	node *previous()
	{
		if (this->left)
		{
			*this = *this->left;
			while (this->right)
				*this = *this->right;
		}
		else
			*this = *this->parent;
		return (&(*this));
	}
};

} // namespace ft

#endif
