/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/11 20:22:57 by abobas        #+#    #+#                 */
/*   Updated: 2020/07/14 21:35:36 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdint>
#include <stdexcept>
#include <limits>

#define BASE_CAP 128

namespace ft
{
    template <typename T>
    class Vector
    {
        private:
            T *array;
            uint32_t total;
            uint32_t cap;
        public:
            Vector()
            {
            	this->array = new T[BASE_CAP];
               	this->total = 0;
              	this->cap = BASE_CAP;
            }

            Vector(uint32_t n, const T &val)
            {
                this->array = new T[BASE_CAP];
              	this->cap = BASE_CAP;
               	this->total = 0;
                for (uint32_t i = 0; i < n; i++)
                    this->push_back(val);
            }
			
            // Vector(IteratorFirst, IteratorLast)
			
            Vector(Vector<T> const &other)
            {
                this->array = new T[other.cap];
               	this->total = 0;
              	this->cap = other.cap;
                for (uint32_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
            }
			
            Vector& operator=(Vector<T> const &other)
            {
                delete[] this->array;
                this->array = new T[other.cap];
              	this->cap = other.cap;
               	this->total = 0;
                for (uint32_t i = 0; i < other.size(); i++)
                    this->push_back(other[i]);
                return (*this);
            }

            ~Vector()
            {
                delete[] this->array;
               	this->total = 0;
              	this->cap = 0;
            }
			
            /*
                begin()
                end()
                rbegin()
                rend()
            */
		   
            uint32_t size() const
            {
                return (this->total);
            }
			
            uint32_t max_size() const
			{
				return (std::numeric_limits<uint32_t>::max());
			}
			
            void resize(uint32_t n)
            {
                T *temp = new T[n];
                uint32_t temp_total = 0;
                for (uint32_t i = 0; i < this->size() && i < n; i++)
                {
                    temp[i] = this->array[i];
                    temp_total++;
                }
                delete[] this->array;
                this->array = temp;
              	this->total = temp_total;
              	this->cap = n;
            }
			
            uint32_t capacity() const
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

            void reserve(uint32_t n)
            {
                this->resize(n);
            }
			
            T& operator[](uint32_t n)
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }

            const T& operator[](uint32_t n) const
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }
			
            T& at(uint32_t n)
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }

            const T& at(uint32_t n) const
            {
                if (n >= this->total)
                    throw std::out_of_range("Vector out of range");
                else
                    return (this->array[n]);
            }
			
            T& front()
            {
				if (this->total == 0)
					throw std::out_of_range("Vector empty");
				else
                	return (this->array[0]);
            }

            const T& front() const
            {
                if (this->total == 0)
					throw std::out_of_range("Vector empty");
				else
                	return (this->array[0]);
            }
			
            T& back()
            {
				if (this->total == 0)
					throw std::out_of_range("Vector empty");
				else
                	return (this->array[this->total - 1]);
            }
			
            const T& back() const
            {
                if (this->total == 0)
					throw std::out_of_range("Vector empty");
				else
                	return (this->array[this->total - 1]);
            }

            void push_back(const T &val)
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
			
            void swap(Vector<T> &other)
            {
				Vector<T> temp(other);
				other = *this;
				*this = temp;
            }

            void clear()
            {
                for (uint32_t i = this->size() - 1; i >= 0; i--)
                    this->array[i] = 0;
               	this->total = 0;
            }
			
            /*
                assign()
                insert()
                erase()
            */
    };
	 
    template <typename T>
    void swap(Vector<T> &first, Vector<T> &second)
    {
		Vector<T> temp(second);
		second = first;
		first = temp;
    }

    template <typename T>
    bool operator==(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		for (uint32_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

    template <typename T>
    bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		else
			return (true);
	}

    template <typename T>
    bool operator<(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (uint32_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (uint32_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (false);
		for (uint32_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())
			return (false);
		return (true);
	}

    template <typename T>
    bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs)
	{
		if (lhs == rhs)
			return (true);
		for (uint32_t i = 0; i < lhs.size() && i < rhs.size(); i++)
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
