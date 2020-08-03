/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:03:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 21:30:38 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{

template <typename T>
class node
{
public:
    typedef T value_type;
    typedef T &reference;
    typedef ptrdiff_t difference_type;

    value_type data;
    node<T> *next;
    node<T> *previous;

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
        node *insert = new node(val);
        insert->previous = this->previous;
        insert->next = this;
        this->previous = insert;
    }

    node &operator=(const node &other)
    {
        this->data = other.data;
        this->next = other.next;
        this->previous = other.previous;
        return (*this);
    }

	bool operator==(const node &other) const
	{
		if (this->data != other.data)
			return (false);
        if (this->next != other.next)
            return (false);
        if (this->previous != other.previous)
            return (false);
		return (true);
	}

	bool operator!=(const node &other) const
	{
		if (*this == other)
			return (false);
		return (true);
	}

    reference operator*()
    {
        return (this->data);
    }

    node &operator++()
    {
        *this = *this->next;
        return (*this);
    }

    node &operator++(int)
    {
        *this = *this->next;
        return (*this);
    }

    node &operator+(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->next;
            n--;
        }
        return (*this);
    }

    node &operator+=(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->next;
            n--;
        }
        return (*this);
        return (*this);
    }

    node &operator--(int)
    {
        *this = *this->previous;
        return (*this);
    }

    node &operator--()
    {
        *this = *this->previous;
        return (*this);
    }

    node &operator-(difference_type n)
    {
        while (n > 0)
        {
            *this = *this->previous;
            n--;
        }
        return (*this);
    }

    node &operator-=(difference_type n)
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
