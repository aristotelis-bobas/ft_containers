/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Stack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/06 16:49:33 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 18:11:30 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "../List/List.hpp"

namespace ft
{
template <class T, class Container = list<T> >
class stack
{
public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

    explicit stack(const container_type &cntr = container_type())
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

    value_type &top()
    {
        return (this->container.back());
    }

    const value_type &top() const
    {
        return (this->container.back());
    }

    void push(const value_type &val)
    {
        this->container.push_back(val);
    }

    void pop()
    {
        this->container.pop_back();
    }

    template <class U, class Cont>
    friend bool operator==(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs);

    template <class U, class Cont>
    friend bool operator<(const stack<U, Cont> &lhs, const stack<U, Cont> &rhs);

private:
    container_type container;
};

template <class T, class Container>
bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
    return (lhs.container == rhs.container);
}

template <class T, class Container>
bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (!(lhs == rhs));
}

template <class T, class Container>
bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
    return (lhs.container < rhs.container);
}

template <class T, class Container>
bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (!(lhs > rhs));
}

template <class T, class Container>
bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace ft

#endif
