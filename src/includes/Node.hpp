/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:03:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 17:04:41 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{

template <typename T>
struct node
{
    typedef T value_type;
    typedef T &reference;
    typedef node self_type;

    value_type data;
    node<T> *next;
    node<T> *previous;

    reference operator*()
	{
		return (*this->data);
	}

    self_type &operator++()
    {
        *this = this->next;
        return (*this);
    }

    self_type &operator--()
    {
        *this = this->previous;
        return (*this);
    }
};

} // namespace ft

#endif
