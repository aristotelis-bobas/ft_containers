/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:03:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/04 16:57:49 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

namespace ft
{

template <typename T>
class node
{
public:
    typedef T value_type;
    typedef T &reference;
    typedef const T& const_reference;
    typedef ptrdiff_t difference_type;
    typedef node self_type;

    value_type data;
    node *next;
    node *previous;

    node(value_type val = value_type())
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

    void insert_before(value_type val = value_type())
    {
        self_type *insert = new self_type(val);
        insert->previous = this->previous;
        insert->next = this;
        this->previous = insert;
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
		if (*this == other)
			return (false);
		return (true);
	}

    reference operator*()
    {
        return (this->data);
    }

    const_reference operator*() const
    {
        return (this->data);
    }

    self_type &operator++()
    {
        *this = *this->next;
        return (*this);
    }

    self_type &operator++(int)
    {
        *this = *this->next;
        return (*this);
    }

    self_type &operator+(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->next;
            n--;
        }
        return (*this);
    }

    self_type &operator+=(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->next;
            n--;
        }
        return (*this);
    }

    self_type &operator--(int)
    {
        *this = *this->previous;
        return (*this);
    }

    self_type &operator--()
    {
        *this = *this->previous;
        return (*this);
    }

    self_type &operator-(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->previous;
            n--;
        }
        return (*this);
    }

    self_type &operator-=(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->previous;
            n--;
        }
        return (*this);
    }
};

} // namespace ft

#endif
