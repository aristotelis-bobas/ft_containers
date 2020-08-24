/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/08/24 19:00:33 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../includes/RandomAccessIterator.hpp"
#include "../includes/Traits.hpp"
#include "../includes/Algorithms.hpp"
#include <stdexcept>
#include <climits>

namespace ft
{

template <class T>
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
	typedef random_access_iterator<value_type, reference, pointer> iterator;
	typedef random_access_iterator<value_type, const_reference, const_pointer> const_iterator;
	typedef reverse_random_access_iterator<value_type, reference, pointer> reverse_iterator;
	typedef reverse_random_access_iterator<value_type, const_reference, const_pointer> const_reverse_iterator;

	explicit vector()
	{
		this->array = nullptr;
		this->cap = 0;
		this->total = 0;
	}

	explicit vector(size_type n, const value_type &val = value_type())
	{
		this->array = new value_type[n];
		this->cap = n;
		this->assign(n, val);
	}

	template <class InputIterator>
	vector(InputIterator first, InputIterator last,
		   typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		size_t n = ft::distance(first, last);
		this->array = new value_type[n];
		this->cap = n;
		this->assign(first, last);
	}

	vector(const vector &x)
	{
		this->array = new value_type[x.cap];
		this->cap = x.cap;
		this->assign(x.begin(), x.end());
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
		this->assign(x.begin(), x.end());
		return (*this);
	}

	iterator begin()
	{
		return (iterator(this->array));
	}

	iterator end()
	{
		return (iterator(&(this->array[this->size()])));
	}

	const_iterator begin() const
	{
		return (const_iterator(this->array));
	}

	const_iterator end() const
	{
		return (const_iterator(&(this->array[this->size()])));
	}

	reverse_iterator rbegin()
	{
		return (reverse_iterator(&(this->array[this->size() - 1])));
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(&(this->array[this->size() - 1])));
	}

	reverse_iterator rend()
	{
		return (reverse_iterator(&(this->array[SIZE_T_MAX])));
	}

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(&(this->array[SIZE_T_MAX])));
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
		value_type *tmp = new value_type[n];
		size_type tmp_total = 0;
		for (size_type i = 0; i < this->size() && i < n; i++)
		{
			if (i >= this->total)
				tmp[i] = val;
			else
				tmp[i] = this->array[i];
			tmp_total++;
		}
		delete[] this->array;
		this->array = tmp;
		this->total = tmp_total;
		this->cap = n;
	}

	size_type capacity() const
	{
		return (this->cap);
	}

	bool empty() const
	{
		return (!this->size());
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
		if (this->array == nullptr)
		{
			this->array = new value_type[1];
			this->cap = 1;
		}
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
		size_t n = distance(position, this->end()) - 1;
		this->push_back(this->back());
		iterator it = this->end() - 1;
		for (size_type i = 0; i < n; i++)
		{
			*it = *(it - 1);
			it--;
		}
		*it = val;
		return (it);
	}

	void insert(iterator position, size_type n, const value_type &val)
	{
		size_t m = distance(position, this->end()) + n - 1;
		for (size_type i = 0; i < n; i++)
			this->push_back(this->array[this->total - (i + 1)]);
		iterator it = this->end() - 1;
		for (size_type i = 0; i < m; i++)
		{
			*it = *(it - n);
			it--;
		}
		for (size_type i = 0; i < n; i++)
		{
			*it = val;
			it++;
		}
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last,
				typename enable_if<is_iterator<typename InputIterator::iterator_category>::value, InputIterator>::type * = nullptr)
	{
		size_type n = distance(first, last);
		size_t m = distance(position, this->end()) + n - 1;
		for (size_type i = 0; i < n; i++)
			this->push_back(this->array[this->total - (i + 1)]);
		iterator it = this->end() - 1;
		for (size_type i = 0; i < m; i++)
		{
			*it = *(it - n);
			it--;
		}
		for (size_type i = 0; i < n; i++)
		{
			*it = *first;
			first++;
			it++;
		}
	}

	iterator erase(iterator position)
	{
		for (iterator it = position; it != this->end() - 1; it++)
			*it = *(it + 1);
		this->total -= 1;
		return (position);
	}

	iterator erase(iterator first, iterator last)
	{
		difference_type n = distance(first, last);
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
		vector tmp(x);
		x = *this;
		*this = tmp;
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
	vector<T> tmp(y);
	y = x;
	x = tmp;
}

template <typename T>
bool operator==(const vector<T> &lhs, const vector<T> &rhs)
{
	typename vector<T>::const_iterator rhs_it = rhs.begin();
	typename vector<T>::const_iterator lhs_it = lhs.begin();

	if (lhs.size() != rhs.size())
		return (false);
	while (lhs_it != lhs.end())
	{
		if (*lhs_it != *rhs_it)
			return (false);
		lhs_it++;
		rhs_it++;
	}
	return (true);
}

template <typename T>
bool operator!=(const vector<T> &lhs, const vector<T> &rhs)
{
	return (!(lhs == rhs));
}

template <typename T>
bool operator<(const vector<T> &lhs, const vector<T> &rhs)
{
	typename vector<T>::const_iterator rhs_it = rhs.begin();
	typename vector<T>::const_iterator lhs_it = lhs.begin();

	if (lhs == rhs || lhs.size() > rhs.size())
		return (false);
	while (lhs_it != lhs.end() && rhs_it != rhs.end())
	{
		if (*lhs_it > *rhs_it)
			return (false);
		lhs_it++;
		rhs_it++;
	}
	return (true);
}

template <typename T>
bool operator<=(const vector<T> &lhs, const vector<T> &rhs)
{
	return (!(lhs > rhs));
}

template <typename T>
bool operator>(const vector<T> &lhs, const vector<T> &rhs)
{
	return (rhs < lhs);
}

template <typename T>
bool operator>=(const vector<T> &lhs, const vector<T> &rhs)
{
	return (!(lhs < rhs));
}

} // namespace ft

#endif
