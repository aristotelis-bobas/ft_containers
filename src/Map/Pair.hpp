/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Pair.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 19:38:27 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 15:53:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template <class T1, class T2>
class pair
{
public:
    typedef T1 first_type;
    typedef T2 second_type;

    pair()
    {
        this->first = first_type();
        this->second = second_type();
    }

    template <class U, class V>
    pair(const pair<U, V> &pr)
    {
        this->first = pr.first;
        this->second = pr.second;
    }

    pair(const first_type &a, const second_type &b)
    {
        this->first = a;
        this->second = b;
    }

    pair &operator=(const pair &pr)
    {
        this->first = pr.first;
        this->second = pr.second;
        return (*this);
    }

    first_type first;
    second_type second;
};

template <class T1, class T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (!(lhs == rhs));
}

template <class T1, class T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (!(rhs < lhs));
}

template <class T1, class T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (rhs < lhs);
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
{
    return (!(lhs < rhs));
}

} // namespace ft

#endif
