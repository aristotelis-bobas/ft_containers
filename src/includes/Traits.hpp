/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Traits.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 17:18:11 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/17 20:08:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
#define TRAITS_HPP

#include "Iterator.hpp"

namespace ft
{

template <bool B, class T = void>
struct enable_if
{
};

template <class T>
struct enable_if<true, T>
{
	typedef T type;
};

template <bool is_iterator, typename T>
struct iterator_result
{
	typedef T type;
	static const bool value = is_iterator;
};

template <typename>
struct iterator_check : public iterator_result<false, bool>
{
};

template <>
struct iterator_check<random_access_iterator_tag>
	: public iterator_result<true, random_access_iterator_tag>
{
};

template <>
struct iterator_check<bidirectional_iterator_tag>
	: public iterator_result<true, bidirectional_iterator_tag>
{
};

template <>
struct iterator_check<forward_iterator_tag>
	: public iterator_result<true, forward_iterator_tag>
{
};

template <>
struct iterator_check<input_iterator_tag>
	: public iterator_result<true, input_iterator_tag>
{
};

template <typename T>
struct is_iterator : public iterator_check<T>
{
};

template <class Arg1, class Arg2, class Result>
struct binary_function
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

} // namespace ft

#endif
