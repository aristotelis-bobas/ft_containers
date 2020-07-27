/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Utilities.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/27 18:32:14 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/27 18:36:25 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_HPP
#define UTILITIES_HPP

namespace ft
{
const class nullptr_t
{
public:
	template <class T>
	operator T *() const
	{
		return 0;
	}

	template <class C, class T>
	operator T C::*() const
	{
		return 0;
	}

private:
	void operator&() const;

} ft_nullptr = {};
} // namespace ft

#endif
