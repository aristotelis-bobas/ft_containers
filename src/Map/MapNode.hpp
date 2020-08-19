/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MapNode.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 15:57:09 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 17:22:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

#include "Pair.hpp"
#include "../includes/Algorithms.hpp"

namespace ft
{

template <class Key, class T, class Compare = less<Key> >
class node
{
public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *pointer;
    typedef node self_type;

    value_type data;
    self_type *parent;
    self_type *left_child;
    self_type *right_child;

    node(value_type val = value_type())
    {
        this->data = val;
        this->parent = nullptr;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }

    node(const node &other)
    {
        this->data = other.data;
        this->parent = other.parent;
        this->left_child = other.left_child;
        this->right_child = other.right_child;
    }

    ~node()
    {
    }
    
    self_type &operator=(const self_type &other)
    {
		if (this->data != other.data)
			return (false);
        if (this->parent != other.parent)
            return (false);
        if (this->left_child != other.left_child || this->right_child != other.right_child)
            return (false);
		return (true);
    }

	bool operator!=(const self_type &other) const
	{
        return (!(*this == other));
	}

    reference operator*()
    {
        return (this->data);
    }

    const_reference operator*() const
    {
        return (this->data);
    }
};

} // namespace ft

#endif
