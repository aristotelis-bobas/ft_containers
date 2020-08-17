/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Queue.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 16:49:33 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 18:11:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../List/List.hpp"

namespace ft
{
template <class T, class Container = list<T> >
class queue
{
public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    explicit queue(const container_type &cntr = container_type())
    {
        this->container = cntr;
    }

    bool empty() const
    {
        return (this->container.empty());
    }

    size_type size() const
    {
        return (this->container.size());
    }

    value_type &front()
    {
        return (this->container.front());
    }

    const value_type &front() const
    {
        return (this->container.front());
    }

    value_type &back()
    {
        return (this->container.back());
    }

    const value_type &back() const
    {
        return (this->container.back());
    }

    void push(const value_type &val)
    {
        this->container.push_back(val);
    }

    void pop()
    {
        this->container.pop_front();
    }

    template <class U, class Cont>
    friend bool operator==(const queue<U, Cont> &lhs, const queue<U, Cont> &rhs);

    template <class U, class Cont>
    friend bool operator<(const queue<U, Cont> &lhs, const queue<U, Cont> &rhs);

private:
    container_type container;
};

template <class T, class Container>
bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
    return (lhs.container == rhs.container);
}

template <class T, class Container>
bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Container>
bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
    return (lhs.container < rhs.container);
}

template <class T, class Container>
bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Container>
bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace ft

#endif
