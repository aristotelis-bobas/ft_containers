/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Algorithms.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 14:30:06 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/19 16:08:22 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Traits.hpp"
#include <cstddef>

namespace ft
{
template <class Iterator>
ptrdiff_t distance(Iterator first, Iterator last,
                   typename enable_if<is_iterator<typename Iterator::iterator_category>::value, Iterator>::type * = nullptr)
{
    ptrdiff_t n = 0;
    while (first != last)
    {
        first++;
        n++;
    }
    return (n);
}

template <class T>
struct less : binary_function<T, T, bool>
{
    bool operator()(const T &x, const T &y) const
    {
        return (x < y);
    }
};

} // namespace ft

#endif
