/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Algorithms.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 14:30:06 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/04 22:37:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Traits.hpp"
#include "Iterator.hpp"

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
} // namespace ft
