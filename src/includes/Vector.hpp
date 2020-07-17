/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/17 19:41:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "VectorIterators.hpp"
#include <cstdint>
#include <stdexcept>
#include <climits>

#define BASE_CAP 128

namespace ft
{
    template <typename T>
    class Vector
    {
        public:
		
			typedef T						value_type;
			typedef T& 						reference;
			typedef const T& 				const_reference;
			typedef size_t					size_type;
			typedef Iterator<T>				iterator;
			typedef ConstIterator<T>		const_iterator;
			typedef ReverseIterator<T>		reverse_iterator;
			typedef ConstReverseIterator<T>	const_reverse_iterator;
			
            explicit Vector()
            {
            	this->array = new T[BASE_CAP];
               	this->total = 0;
              	this->cap = BASE_CAP;
            }
	
            explicit Vector(size_type n, const value_type &val)
            {
                this->array = new value_type[BASE_CAP];
              	this->cap = BASE_CAP;
               	this->total = 0;
                for (size_type i = 0; i < n; i++)
                    this->push_back(val);
            }

		//	template <class InputIterator>
		//	Vector(InputIterator first, InputIterator last);
			
            Vector(const Vector<T> &other)
            {
                this->array = new value_type[other.cap];
               	this->total = 0;
              	this->cap = other.cap;
                for (size_type i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
            }
			
			~Vector()
            {
                delete[] this->array;
            }

            Vector& operator=(const Vector<T> &other)
            {
                delete[] this->array;
                this->array = new value_type[other.cap];
              	this->cap = other.cap;
               	this->total = 0;
                for (size_type i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
                return (*this);
            }

			iterator begin()
			{
				return (iterator(this->array, 0));
			}

			const_iterator begin() const
			{
				return (const_iterator(this->array, 0));
			}

			iterator end()
			{
				return (iterator(this->array, this->size()));
			}

			const_iterator end() const
			{
				return (const_iterator(this->array, this->size()));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->array, this->size() - 1));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->array, this->size() - 1));
			}
			
			reverse_iterator rend()
			{
				return (reverse_iterator(this->array, SIZE_T_MAX));
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
			
            void resize(size_type n)
            {
                value_type *temp = new value_type[n];
                size_type temp_total = 0;
                for (size_type i = 0; i < this->size() && i < n; i++)
                {
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
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }

            const_reference at(size_type n) const
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
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
			void assign(InputIterator first, InputIterator last);

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
                this->array[this->total - 1] = 0;
                this->total--;
            }
			
			iterator insert(iterator position, const value_type &val);

			void insert(iterator position, size_type n, const value_type &val);

			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last);

			iterator erase(iterator position);

			iterator erase(iterator first, iterator last);
			
            void swap(Vector<T> &other)
            {
				Vector<T> temp(other);
				other = *this;
				*this = temp;
            }

            void clear()
            {
               	this->total = 0;
            }
			
			private:
		
				value_type		*array;
				size_type		total;
				size_type 		cap;
			
    };
	
    template <typename T>
    void swap(Vector<T> &first, Vector<T> &second)
    {
		Vector<T> temp(second);
		second = first;
		first = temp;
    }

    template <typename T>
    bool operator==(const Vector<T> &lhs, const Vector<T> &rhs)
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
    bool operator!=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs == rhs)
			return (false);
		else
			return (true);
	}

    template <typename T>
    bool operator<(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator<=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>=(const Vector<T> &lhs, const Vector<T> &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())
			return (false);
		return (true);
	}
}

#endif
