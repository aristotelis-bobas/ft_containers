/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Node.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 15:03:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 18:19:07 by abobas        ########   odam.nl         */
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
    typedef node<T> self_type;
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

    node &operator=(const node &other)
    {
        this->data = other.data;
        this->next = other.next;
        this->previous = other.previous;
        return (*this);
    }

    reference operator*()
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
