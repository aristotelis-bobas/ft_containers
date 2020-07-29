/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/29 21:06:07 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "Iterator.hpp"
#include "Traits.hpp"
#include <stdexcept>
#include <climits>

#define BASE_CAP 128

namespace ft
{

template <typename T>
class vector
{
public:
	typedef T value_type;
	typedef value_type &reference;
	typedef const value_type &const_reference;
	typedef value_type *pointer;
	typedef const value_type *const_pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef random_access_iterator<value_type, pointer, reference> iterator;
	typedef random_access_iterator<value_type, const_pointer, const_reference> const_iterator;
	typedef reverse_random_access_iterator<value_type, pointer, reference> reverse_iterator;
	typedef reverse_random_access_iterator<value_type, const_pointer, const_reference> const_reverse_iterator;

	explicit vector()
	{
		this->array = new value_type[BASE_CAP];
		this->total = 0;
		this->cap = BASE_CAP;
	}

	explicit vector(size_type n, const value_type &val = value_type())
	{
		this->array = new value_type[BASE_CAP];
		this->cap = BASE_CAP;
		this->total = 0;
		for (size_type i = 0; i < n; i++)
			this->push_back(val);
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		   typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		this->array = new value_type[BASE_CAP];
		this->cap = BASE_CAP;
		this->total = 0;
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
	}

	vector(const vector &x)
	{
		this->array = new value_type[x.cap];
		this->total = 0;
		this->cap = x.cap;
		for (size_type i = 0; i < x.size(); i++)
			this->push_back(x[i]);
	}

	~vector()
	{
		delete[] this->array;
	}

	vector &operator=(const vector &x)
	{
		delete[] this->array;
		this->array = new value_type[x.cap];
		this->cap = x.cap;
		this->total = 0;
		for (size_type i = 0; i < x.size(); i++)
			this->push_back(x[i]);
		return (*this);
	}

	iterator begin()
	{
		return (iterator(this->array, 0));
	}

	iterator end()
	{
		return (iterator(this->array, this->size()));
	}

	const_iterator begin() const
	{
		return (const_iterator(this->array, 0));
	}

	const_iterator end() const
	{
		return (const_iterator(this->array, this->size()));
	}

	reverse_iterator rbegin()
	{
		return (reverse_iterator(this->array, this->size() - 1));
	}

	reverse_iterator rend()
	{
		return (reverse_iterator(this->array, SIZE_T_MAX));
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(this->array, this->size() - 1));
	}

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(this->array, SIZE_T_MAX));
	}

	size_type size() const
	{
		return (this->total);
	}

	size_type max_size() const
	{
		return (SIZE_T_MAX / sizeof(value_type));
	}

	void resize(size_type n, value_type val = value_type())
	{
		value_type *temp = new value_type[n];
		size_type temp_total = 0;
		for (size_type i = 0; i < this->size() && i < n; i++)
		{
			if (i >= this->total)
				temp[i] = val;
			else
				temp[i] = this->array[i];
			temp_total++;
		}
		delete[] this->array;
		this->array = temp;
		this->total = temp_total;
		this->cap = n;
	}

	size_type capacity() const
	{
		return (this->cap);
	}

	bool empty() const
	{
		if (this->total == 0)
			return (true);
		else
			return (false);
	}

	void reserve(size_type n)
	{
		if (n > this->capacity())
			this->resize(n);
	}

	reference operator[](size_type n)
	{
		return (this->array[n]);
	}

	const_reference operator[](size_type n) const
	{
		return (this->array[n]);
	}

	reference at(size_type n)
	{
		if (n >= this->total)
			throw std::out_of_range("vector out of range");
		else
			return (this->array[n]);
	}

	const_reference at(size_type n) const
	{
		if (n >= this->total)
			throw std::out_of_range("vector out of range");
		else
			return (this->array[n]);
	}

	reference front()
	{
		return (this->array[0]);
	}

	const_reference front() const
	{
		return (this->array[0]);
	}

	reference back()
	{
		return (this->array[this->total - 1]);
	}

	const_reference back() const
	{
		return (this->array[this->total - 1]);
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		this->clear();
		while (first != last)
		{
			this->push_back(*first);
			first++;
		}
	}

	void assign(size_type n, const value_type &val)
	{
		this->clear();
		for (size_type i = 0; i < n; i++)
			this->push_back(val);
	}

	void push_back(const value_type &val)
	{
		if (this->total == this->cap)
			this->resize(this->cap * 2);
		this->array[this->total] = val;
		this->total++;
	}

	void pop_back()
	{
		this->total--;
	}

	iterator insert(iterator position, const value_type &val)
	{
		iterator it = this->end() - 1;
		this->push_back(*it);
		while (it != position)
		{
			reference tmp = *it;
			it--;
			tmp = *it;
		}
		*it = val;
		return (it);
	}

	void insert(iterator position, size_type n, const value_type &val)
	{
		iterator it = this->end() - n;
		for (size_type i = 0; i < n; i++)
		{
			this->push_back(*it);
			it++;
		}
		it++;
		while (it != position)
		{
			iterator tmp = it;
			tmp -= n;
			*it = *tmp;
			it--;
		}
		for (size_type i = 0; i < n; i++)
		{
			*position = val;
			position++;
		}
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		difference_type n = last - first;
		iterator it = this->end() - n;
		for (difference_type i = 0; i < n; i++)
		{
			this->push_back(*it);
			it++;
		}
		it++;
		while (it != position)
		{
			iterator tmp = it;
			tmp -= n;
			*it = *tmp;
			it--;
		}
		for (difference_type i = 0; i < n; i++)
		{
			*position = *first;
			first++;
			position++;
		}
	}

	iterator erase(iterator position)
	{	
		for (iterator it = position; it != this->end() - 1; it++)
		{
			iterator tmp = it;
			tmp++;
			*it = *tmp;
		}
		this->total -= 1;
		return (position);
	}

	iterator erase(iterator first, iterator last)
	{
		difference_type n = last - first;
		for (iterator it = last; it != this->end(); it++)
		{
			*first = *it;
			first++;
		}
		this->total -= n;
		return (last);
	}

	void swap(vector &x)
	{
		vector temp(x);
		x = *this;
		*this = temp;
	}

	void clear()
	{
		this->total = 0;
	}

private:
	pointer array;
	size_type total;
	size_type cap;
};

template <typename T>
void swap(vector<T> &x, vector<T> &y)
{
	vector<T> temp(y);
	y = x;
	x = temp;
}

template <typename T>
bool operator==(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return (false);
	}
	return (true);
}

template <typename T>
bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs == rhs)
		return (false);
	else
		return (true);
}

template <typename T>
bool operator<(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs == rhs || lhs.size() > rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs[i] > rhs[i])
			return (false);
	}
	return (true);
}

template <typename T>
bool operator<=(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs == rhs)
		return (true);
	if (lhs.size() > rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs[i] > rhs[i])
			return (false);
	}
	return (true);
}

template <typename T>
bool operator>(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs == rhs || lhs.size() < rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs[i] < rhs[i])
			return (false);
	}
	return (true);
}

template <typename T>
bool operator>=(const vector<T> &lhs, const vector<T> &rhs)
{
	if (lhs == rhs)
		return (true);
	if (lhs.size() < rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
	{
		if (lhs[i] < rhs[i])
			return (false);
	}
	return (true);
}

} // namespace ft

#endif
