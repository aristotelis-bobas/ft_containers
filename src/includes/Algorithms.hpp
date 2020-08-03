/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Algorithms.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 14:30:06 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/03 23:15:59 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Traits.hpp"
#include "Iterator.hpp"

#include <cstddef>

namespace ft
{
template <class InputIterator>
ptrdiff_t distance(InputIterator first, InputIterator last,
                   typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
{
    ptrdiff_t n = 0;
    while (first != last)
    {
        first++;
        n++;
    }
    return (n);
}
} // namespace ft
